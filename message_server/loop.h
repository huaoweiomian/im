#ifndef LOOP_H
#define LOOP_H

#include "../pro/protocol.h"
#include "conn_mgr.h"
#include "../baselib/net/channel.h"
#include "../baselib/net/channel_client.h"
class LOOP
{
public:
    LOOP();
};



void loop(PROTOCOL& pro, CHANNEL* pchl);
#endif // LOOP_H
