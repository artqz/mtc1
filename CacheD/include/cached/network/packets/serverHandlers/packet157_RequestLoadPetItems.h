#pragma once

#include <l2core/utils/cstdint_support.h>

class CIOSocket;

namespace serverHandlers
{
bool packet157_RequestLoadPetItems(CIOSocket* pSocket, const uint8_t* packet);  // L2CacheD 0x00455FB0
}  // namespace serverHandlers
