#pragma once

#include <l2core/utils/cstdint_support.h>

class CIOSocket;

namespace serverHandlers
{
bool packet081_RequestReserveDismissPenalty(CIOSocket* pSocket, const uint8_t* packet);  // L2CacheD 0x004409F0
}  // namespace serverHandlers
