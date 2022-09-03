#ifndef LOOP_H
#define LOOP_H

#include "../pro/protocol.h"
#include "conn_mgr.h"
#include "../baselib/net/channel.h"
class LOOP
{
public:
    LOOP();
};



void loop(PROTOCOL& pro);
#endif // LOOP_H
