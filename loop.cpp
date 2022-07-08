#include "loop.h"

LOOP::LOOP()
{

}
void loop(PROTOCOL& pro){
    CONN_MGR* mgr = singleton();
    switch (pro.type()) {
    case ROUTER_c:
    {
        ROUTER rr;
        pro.get_struct(&rr,sizeof (rr));
        CHANNEL* pdest = mgr->dest_chl(rr.dest);
        if(pdest){
            pdest->write_to_self(pro.buf);//将消息发送给目标消息服务器
        }else{

        }
    }
        break;

    case REPORT_INFO_c:
    {
        REPORT_INFO ri;
        pro.get_struct(&ri,sizeof (ri));
        mgr->set(ri.uid,ri.msgid);
    }
        break;
    //default:
        //
    }
}
