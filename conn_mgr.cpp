#include "conn_mgr.h"
static CONN_MGR mgr;
CONN_MGR::CONN_MGR()
{

}

CONN_MGR *singleton()
{
    return &mgr;
}
