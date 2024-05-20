#include <WinSock2.h>

#include "cached/network/packets/serverHandlers/packet188_RequestDeleteBlockList.h"

#include "cached/model/CUserDb.h"
#include "cached/network/CServerSocket.h"
#include "l2core/db/DBConn.h"
#include "l2core/logger/CLog.h"
#include "l2core/network/PacketUtils.h"
#include "l2core/network/packets/CacheToServerPackets.h"
#include "l2core/utils/Utils.h"
#include "l2core/utils/dbg/StackGuard.h"

namespace serverHandlers
{
// L2CacheD 0x00451970
bool packet188_RequestDeleteBlockList(CIOSocket* pSocket, const uint8_t* packet)
{
    guard(L"bool serverHandlers::packet188_RequestDeleteBlockList(CIOSocket *pSocket, const uint8_t *packet)");

    CServerSocket* serverSocket = static_cast<CServerSocket*>(pSocket);

    uint32_t characterId = 0;
    int unknownParam1 = 0;
    wchar_t characterName[25] = {0};
    PacketUtils::Disassemble(packet, "ddS", &characterId, &unknownParam1, sizeof(characterName), characterName);
    CUserSP character = g_userDb.GetUser(characterId, true);
    if (character == NULL)
    {
        g_winlog.Add(LOG_ERROR, L"[%S][%d]Cannot find user, dbid[%d]", TEXT(__FILE__), __LINE__, characterId);
        // serverSocket->Send("cddS", CacheToServerPacket_ReplyDeleteBlockList, unknownParam1, 0);
        serverSocket->Send("cdd", CacheToServerPacket_ReplyDeleteBlockList, unknownParam1, 0);  // FIXED

        unguard();
        return false;
    }

    int blockResult = 0;

    DBConn sql;
    sql.Bind(&blockResult);
    if (!sql.Execute(L"EXEC lin_DeleteBlockList %d, N'%s'", character->GetId(), characterName))
    {
        serverSocket->Send("cddS", CacheToServerPacket_ReplyDeleteBlockList, unknownParam1, 0, characterName);

        unguard();
        return false;
    }

    if (!sql.Fetch())
    {
        serverSocket->Send("cddS", CacheToServerPacket_ReplyDeleteBlockList, unknownParam1, 0, characterName);

        unguard();
        return false;
    }

    serverSocket->Send("cddS", CacheToServerPacket_ReplyDeleteBlockList, unknownParam1, blockResult, characterName);

    unguard();
    return false;
}
}  // namespace serverHandlers