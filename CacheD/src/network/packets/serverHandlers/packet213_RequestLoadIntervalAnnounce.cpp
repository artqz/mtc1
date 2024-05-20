#include <WinSock2.h>

#include "cached/network/packets/serverHandlers/packet213_RequestLoadIntervalAnnounce.h"

#include "cached/model/CAnnounce.h"
#include "cached/network/CServerSocket.h"
#include "l2core/logger/CLog.h"
#include "l2core/network/CPacket.h"
#include "l2core/network/PacketUtils.h"
#include "l2core/utils/Unused.h"
#include "l2core/utils/Utils.h"
#include "l2core/utils/dbg/CallStack.h"
#include "l2core/utils/dbg/StackGuard.h"

namespace serverHandlers
{

// L2CacheD 0x00437050
bool packet213_RequestLoadIntervalAnnounce(CIOSocket* pSocket, const uint8_t* packet)
{
    guard(L"bool serverHandlers::packet213_RequestLoadIntervalAnnounce(CIOSocket *pSocket, const uint8_t *packet)");

    CServerSocket* serverSocket = static_cast<CServerSocket*>(pSocket);
    g_announce.LoadIntervalAnnounce(serverSocket, packet);

    unguard();
    return false;
}

}  // namespace serverHandlers