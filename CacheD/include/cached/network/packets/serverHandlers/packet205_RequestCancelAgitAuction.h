#pragma once

#include <l2core/utils/cstdint_support.h>

class CIOSocket;

namespace serverHandlers
{
bool packet205_RequestCancelAgitAuction(CIOSocket* pSocket, const uint8_t* packet);  // L2CacheD 0x00454260
}  // namespace serverHandlers
