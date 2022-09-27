#include "conn_mgr.h"
static CONN_MGR mgr;
CONN_MGR::CONN_MGR()
{

}

CHANNEL *CONN_MGR::dest_chl(int id)
{
    map<int, CHANNEL*>::iterator it = uid_chl.find(id);
    if(uid_chl.end() == it)
        return NULL;
    return it->second;
}

void CONN_MGR::set(int uid, CHANNEL* chl)
{
    uid_chl[uid] = chl;
}
CONN_MGR *singleton()
{
    return &mgr;
}
