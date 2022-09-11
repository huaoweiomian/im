#include "loop.h"
#include "config.h"
#include <iostream>
LOOP::LOOP()
{

}
void loop(PROTOCOL& pro, CHANNEL* pchl){
    CONN_MGR* mgr = singleton();
    CONN_CMGR* cmgr = csingleton();
    CONFIG* cfg = cfg_singleton();
    switch (pro.type()) {
    case MSG_SVR_LOGIN_c:
    {
        LOGIN l;
        pro.get_struct(&l,sizeof (l));
        REPORT_INFO ri;
        ri.uid = l.uid;//
        ri.msgid = cfg->message_svr_id();
        mgr->set(l.uid,pchl);
        CHANNEL_CLIENT* pc = cmgr->get(0);
        if(NULL == pc){
            std::cout<<"CHANNEL_CLIENT* pc = cmgr->get(0) is NULL."<<std::endl;
            std::cout<<"router 0 do not exist."<<std::endl;
            return;
        }
        BOTH_HEADER bh;
        bh.h.len = sizeof (ri)+ sizeof (bh);
        bh.h.type = RAW_c;
        bh.h.count = 0;
        bh.hr.id = MSG_SVR_LOGIN_c;
        bh.hr.len = sizeof (bh.hr) + sizeof (ri);
        BUFFER b;
        b.append(sizeof (bh), (char*)&bh);
        b.append(sizeof (ri),(char*)&ri);
        pc->mysend(b);
    }
        break;
    case MSG_SVR_MSG_c:
    {
        //save to database;
        CHANNEL_CLIENT* pc = cmgr->get(0);
        if(NULL == pc){
            std::cout<<"CHANNEL_CLIENT* pc = cmgr->get(0) is NULL."<<std::endl;
            std::cout<<"router 0 do not exist."<<std::endl;
            return;
        }
        pc->mysend(pro.buf);
    }
        break;
    //default:
        //
    }
}
//    case ROUTER_c:
//    {
//        ROUTER rr;
//        pro.get_struct(&rr,sizeof (rr));
//        CHANNEL* pdest = mgr->dest_chl(rr.dest);
//        if(pdest){
//            pdest->write_to_self(pro.buf);//将消息发送给目标消息服务器
//        }else{

//        }
//    }
//        break;

//    case REPORT_INFO_c:
//    {
//        REPORT_INFO ri;
//        pro.get_struct(&ri,sizeof (ri));
//        mgr->set(ri.uid,ri.msgid);
//    }
//        break;
