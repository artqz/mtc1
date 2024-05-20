#pragma once

#include "l2auth/threads/CLock.h"

class CWantedPacket;
class CWantedSocket;

class CWantedPacketSlot
{
public:
    CWantedPacketSlot();
    ~CWantedPacketSlot();

    union
    {
        CWantedPacket* packet;
        CWantedSocket* socket;
    } m_data;
    CLock m_lock;
};
