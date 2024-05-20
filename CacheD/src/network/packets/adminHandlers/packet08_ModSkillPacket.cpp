#include <WinSock2.h>

#include "cached/network/packets/adminHandlers/packet08_ModSkillPacket.h"

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

// L2CacheD 0x00418790
bool packet08_ModSkillPacket(CAdminSocket* pSocket, const char* packet)
{
    guard(L"bool adminHandlers::packet08_ModSkillPacket(CAdminSocket *pSocket, const char *packet)");

    int unknown = 0;
    char charname[256] = {0};
    int skillId = 0;
    int newSkillLevel = 0;
    char adminaccount[256] = {0};
    char cUnknown[256] = {0};
    PacketUtils::ReadSocketArgs(packet, "dsddss", &unknown, charname, &skillId, &newSkillLevel, adminaccount, cUnknown);
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

    if (newSkillLevel < 0 || newSkillLevel > 256)
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
    if (user != NULL && (user = g_userDb.GetUser(user->GetId(), true)) != NULL)
    {
        bool isAquired = user->AquireSkill(skillId, newSkillLevel, true);
        if (user->IsLoggedIn() && CServerSocket::s_gameServerSocket != NULL)
        {
            CServerSocket::s_gameServerSocket->Send("cdddd", CacheToServerPacket_UpdateSkillPacket, user->GetId(), 3, skillId, newSkillLevel);
        }

        if (isAquired)
        {
            g_winlog.Add(LOG_IN, L"%d,%u,%u,%u,%u,,,,,,,%d,%d,,,,,,,,,%s,%s,%s,%s,", LogId_ModSkill, 0, 0, user->GetId(), user->GetAccountID(), skillId, newSkillLevel, wAdminaccount, wUnknown, user->GetCharName(), user->GetAccountName());
            pSocket->SendBuffer("1", 1);
            unguard();
            return false;
        }
    }
    else
    {
        g_winlog.Add(LOG_ERROR, L"[%S][%d]Cannot find user, char name[%s]", __FILE__, __LINE__, wNamelowerCase);
        pSocket->Send("0%d", 4);
        unguard();
        return false;
    }

    return false;
}

}  // namespace adminHandlers
