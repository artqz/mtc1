#pragma once

#include <l2core/utils/cstdint_support.h>

class CAdminSocket;

namespace adminHandlers
{
bool packet24_DelBookMarkPacket(CAdminSocket* pSocket, const char* packet);  // L2CacheD 0x0041C9D0
}  // namespace adminHandlers
