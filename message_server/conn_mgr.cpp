#include "conn_mgr.h"
static CONN_MGR mgr;
static CONN_CMGR cmgr;
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


void CONN_MGR::set(int uid, CHANNEL * chl)
{
    uid_chl[uid] = chl;
}

CONN_MGR *singleton()
{
    return &mgr;
}

CONN_CMGR *csingleton()
{
    return &cmgr;
}

CONN_CMGR::CONN_CMGR()
{

}

void CONN_CMGR::set(int id, CHANNEL_CLIENT *cc)
{
    id_cc[id] = cc;
}

CHANNEL_CLIENT *CONN_CMGR::get(int id)
{
    map<int, CHANNEL_CLIENT*>::iterator it = id_cc.find(id);
    if(id_cc.end() == it)
        return NULL;
    return it->second;
}
