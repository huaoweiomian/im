#include "loop.h"
#include <iostream>
using std::cout;
using std::endl;
LOOP::LOOP()
{

}
void loop(PROTOCOL& pro, CHANNEL* chl){
    CONN_MGR* mgr = singleton();
    switch (pro.id()) {
    case MSG_c:
    {
        MESSAGE msg;
        pro.get_content(&msg,sizeof (msg));
        CHANNEL* pdest = mgr->dest_chl(msg.dest);
        if(pdest){
            pdest->send(pro.buf);//将消息发送给目标消息服务器
        }else{

        }
    }
        break;

    case LOGIN_c:
    {

        LOGIN l;
        pro.get_content(&l,sizeof (l));
        mgr->set(l.uid,chl);
        cout<<l.uid<<"登录"<<endl;
    }
        break;
    //default:
        //
    }
}
