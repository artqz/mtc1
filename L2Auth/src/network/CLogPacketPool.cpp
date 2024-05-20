#include "l2auth/network/CLogPacketPool.h"

#include "l2auth/network/CLogPacket.h"

CLogPacketSlot CLogPacketPool::g_slot[16];
long CLogPacketPool::g_nAlloc = -1;
long CLogPacketPool::g_nFree = 0;

CLogPacketPool theLogPacketPool;

CLogPacketPool::~CLogPacketPool()
{
    CLogPacket::FreeAll();
}