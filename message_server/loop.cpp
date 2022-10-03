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
    switch (pro.id()) {
    case LOGIN_c:
    {
        LOGIN l;
        pro.get_content(&l,sizeof (l));
        l.msgid = cfg->message_svr_id();
        mgr->set(l.uid,pchl);
        CHANNEL_CLIENT* pc = cmgr->get(0);
        if(NULL == pc){
            std::cout<<"CHANNEL_CLIENT* pc = cmgr->get(0) is NULL."<<std::endl;
            std::cout<<"router 0 do not exist."<<std::endl;
            return;
        }
        BUFFER b;
        pro.set_content(pro.id(),&l,sizeof (l));
        pc->mysend(pro.buf);
        cout<<l.uid<<"登录"<<endl;
    }
        break;
    case MSG_c:
    {
        //save to database;
        CHANNEL_CLIENT* pc = cmgr->get(0);
        if(NULL == pc){
            std::cout<<"CHANNEL_CLIENT* pc = cmgr->get(0) is NULL."<<std::endl;
            std::cout<<"router 0 do not exist."<<std::endl;
            return;
        }     
        pc->mysend(pro.buf);
        pchl->send(pro.buf);
        MESSAGE msg;
        pro.get_content(&msg, sizeof(msg));
        cout<<msg.src<<"-->"<<msg.dest<<":"<<msg.buff<<endl;
    }
        break;
    //default:
        //
    }
}
