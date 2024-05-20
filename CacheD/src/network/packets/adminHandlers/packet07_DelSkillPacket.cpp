#include <WinSock2.h>

#include "cached/network/packets/adminHandlers/packet07_DelSkillPacket.h"

#include "cached/model/CUserDb.h"
#include "cached/network/CAdminSocket.h"
#include "cached/network/CServerSocket.h"
#include "l2core/logger/CLog.h"
#include "l2core/network/CPacket.h"
#include "l2core/network/PacketUtils.h"
#include "l2core/network/packets/CacheToServerPackets.h"
#include "l2core/utils/Utils.h"
#include "l2core/utils/dbg/CallStack.h"
#include "l2core/utils/dbg/StackGuard.h"

namespace adminHandlers
{

// L2CacheD 0x00418340
bool packet07_DelSkillPacket(CAdminSocket* pSocket, const char* packet)
{
    guard(L"bool adminHandlers::packet07_DelSkillPacket(CAdminSocket *pSocket, const char *packet)");

    int unknown = 0;
    char charname[256] = {0};
    int skillId = 0;
    char adminaccount[256] = {0};
    char cUnknown[256] = {0};
    PacketUtils::ReadSocketArgs(packet, "dsdss", &unknown, charname, &skillId, adminaccount, cUnknown);

    if (strlen(charname) < 1)
    {
        pSocket->Send("0%d", 3);
        unguard();
        return false;
    }

    if (skillId < 0 || skillId > 0x10000)
    {
        pSocket->Send("0%d", 3);
        unguard();
        return false;
    }

    wchar_t wAdminaccount[256] = {0};
    if (strlen(adminaccount) == 0)
    {
        wcscpy(wAdminaccount, L"__DEL__");
    }
    else
    {
        Utils::AnsiToUnicode(adminaccount, sizeof(adminaccount) - 1, wAdminaccount, (sizeof(wAdminaccount) / sizeof(wchar_t)) - 1);
    }

    wchar_t wUnknown[256] = {0};
    if (strlen(cUnknown) == 0)
    {
        wcscpy(wUnknown, L"__DEL__");
    }
    else
    {
        Utils::AnsiToUnicode(cUnknown, sizeof(cUnknown) - 1, wUnknown, (sizeof(wUnknown) / sizeof(wchar_t)) - 1);
    }

    wchar_t wCharname[256] = {0};
    Utils::AnsiToUnicode(charname, sizeof(charname), wCharname, sizeof(wCharname) / sizeof(wchar_t));

    wchar_t wNamelowerCase[256] = {0};
    Utils::CopyStrInLowerCase(wCharname, wNamelowerCase);
    CUserSP user = g_userDb.GetUser(wNamelowerCase);
    if (user == NULL || ((user = g_userDb.GetUser(user->GetId(), true)) == NULL))
    {
        g_winlog.Add(LOG_ERROR, L"[%S][%d]Cannot find user, char name[%s]", __FILE__, __LINE__, wNamelowerCase);
        pSocket->Send("0%d", 4);
        unguard();
        return false;
    }

    bool isDeleteSkill = user->DeleteSkill(skillId);
    if (user->IsLoggedIn() && CServerSocket::s_gameServerSocket != NULL)
    {
        CServerSocket::s_gameServerSocket->Send("cdddd", CacheToServerPacket_UpdateSkillPacket, user->GetId(), 2, skillId, 0);
    }

    if (!isDeleteSkill)
    {
        pSocket->Send("0%d", 1);
        unguard();
        return false;
    }

    g_winlog.Add(LOG_IN, L"%d,%u,%u,%u,%u,,,,,,,%d,,,,,,,,,,%s,%s,%s,%s,", LogId_DelSkill, 0, 0, user->GetId(), user->GetAccountID(), skillId, wAdminaccount, wUnknown, user->GetCharName(), user->GetAccountName());
    pSocket->SendBuffer("1", 1);

    unguard();
    return false;
}

}  // namespace adminHandlers