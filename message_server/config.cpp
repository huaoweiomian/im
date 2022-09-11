#include "config.h"
static CONFIG cfg;

CONFIG* cfg_singleton(){
    return &cfg;
}
CONFIG::CONFIG()
{
    svr_id = 0;
}

int CONFIG::message_svr_id()
{
    return svr_id;
}
