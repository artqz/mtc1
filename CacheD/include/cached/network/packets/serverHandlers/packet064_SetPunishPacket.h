#pragma once

#include <l2core/utils/cstdint_support.h>

class CIOSocket;

namespace serverHandlers
{
bool packet064_SetPunishPacket(CIOSocket* pSocket, const uint8_t* packet);  // L2CacheD 0x00435C90
}  // namespace serverHandlers
