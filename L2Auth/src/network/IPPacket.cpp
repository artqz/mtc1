#include "l2auth/network/IPPacket.h"

#include "l2auth/network/CIOBuffer.h"
#include "l2auth/network/IPPacketPool.h"
#include "l2auth/network/IPPacketSlot.h"
#include "l2auth/network/IPSocket.h"
#include "l2auth/threads/CLock.h"
#include "l2auth/utils/CExceptionInit.h"

long IPPacket::g_nPendingPacket;

// L2AuthD 0x00426960
IPPacket::IPPacket()
    : CIOObject()
    , m_pSocket(NULL)
    , m_pBuf(NULL)
    , m_pFunc(NULL)
{
}

// L2AuthD 0x004269B0
IPPacket::~IPPacket()
{
}

// L2AuthD 0x004245CF
IPPacket* IPPacket::Alloc()
{
    IPPacketSlot* slot = &IPPacketPool::g_slot[InterlockedIncrement(&IPPacketPool::g_nAlloc) & 0xF];
    slot->m_lock.Enter();

    IPPacket* packet = slot->m_data.packet;
    if (packet != NULL)
    {
        slot->m_data.socket = packet->m_pSocket;
        slot->m_lock.Leave();
    }
    else
    {
        slot->m_lock.Leave();
        packet = new IPPacket();
    }
    return packet;
}

// L2AuthD 0x00424691
void IPPacket::FreeAll()
{
    for (int i = 0; i < 16; ++i)
    {
        IPPacketSlot* slot = &IPPacketPool::g_slot[i];
        slot->m_lock.Enter();
        while (true)
        {
            IPPacket* packet = slot->m_data.packet;
            if (packet == NULL)
            {
                break;
            }

            slot->m_data.socket = packet->m_pSocket;
            delete packet;
        }
        slot->m_lock.Leave();
    }
}

// L2AuthD 0x0042471F
void IPPacket::Free()
{
    IPPacketSlot* slot = &IPPacketPool::g_slot[InterlockedDecrement(&IPPacketPool::g_nFree) & 0xF];
    slot->m_lock.Enter();
    m_pSocket = slot->m_data.socket;
    slot->m_data.packet = this;
    slot->m_lock.Leave();
}

// L2AuthD 0x0042476E
void IPPacket::OnIOCallback(BOOL /*bSuccess*/, DWORD dwTransferred, LPOVERLAPPED /*lpOverlapped*/)
{
    auth_guard;

    uint8_t* packet = m_pBuf->m_Buffer + dwTransferred;
    if ((m_pFunc)(m_pSocket, packet + 1))
    {
        m_pSocket->CloseSocket();
    }

    m_pSocket->ReleaseRef();
    m_pBuf->Release();
    ::InterlockedDecrement(&IPPacket::g_nPendingPacket);
    Free();

    auth_vunguard;
}