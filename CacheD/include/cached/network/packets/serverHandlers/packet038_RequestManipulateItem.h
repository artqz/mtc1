#pragma once

#include <l2core/utils/cstdint_support.h>

class CIOSocket;

namespace serverHandlers
{
bool packet038_RequestManipulateItem(CIOSocket* pSocket, const uint8_t* packet);  // L2CacheD 0x00442260
}  // namespace serverHandlers
