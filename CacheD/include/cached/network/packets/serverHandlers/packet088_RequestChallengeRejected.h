#pragma once

#include <l2core/utils/cstdint_support.h>

class CIOSocket;

namespace serverHandlers
{
bool packet088_RequestChallengeRejected(CIOSocket* pSocket, const uint8_t* packet);  // L2CacheD 0x00442AD0
}  // namespace serverHandlers
