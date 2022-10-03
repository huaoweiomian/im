#include <QCoreApplication>

#include "../baselib/net/channel_client.h"
#include "../baselib/net/channel_factory.h"
#include "../pro/protocol.h"
#include "conn_mgr.h"
#include "loop.h"
#include <signal.h>
void wait_connect(CHANNEL_FACTORY& cf);
bool connect_svr();

int main(int argc, char *argv[])
{
    //signal(SIGSTOP, SIG_IGN);
    QCoreApplication a(argc, argv);
    CHANNEL_FACTORY cf;
    if(!connect_svr()){
        return 0;
    }
    wait_connect(cf);
    return a.exec();
}

void wait_connect(CHANNEL_FACTORY& cf){
    string ip("192.168.106.148");
    CHLQ* q = cf.init(ip,8888, 10);
    while(true){
        CHANNEL* pchl = q->block_read();
        if(INVALID == pchl->status()){
            cout<<"CHANNEL* pchl = q->block_read; chl invalid;"<<endl;
            q->del_chl(pchl);
            continue;
        }
        BUFFER b;
        pchl->recv(b);
        unordered_map<CHANNEL*, BUFFER> mp;//处理粘包
        BUFFER ret = item(mp,pchl,b);
        PROTOCOL pro(ret);
        if(!pro.parser()){
            cout<<"start_svr;pro.parser false"<<endl;
            continue;
        }
        loop(pro,pchl);
    }
}
//string ip("192.168.106.148");
//CHLQ* q = cf.init(ip,6666, 10);
bool connect_svr(){
    CHANNEL_CLIENT* cc = new  CHANNEL_CLIENT() ;
    string ip("192.168.106.148");
    if(!cc->init(ip, 6666)){
        cout<<"CHANNEL_CLIENT::init error"<<endl;
        return false;
    }
    CONN_CMGR* cmgr = csingleton();
    cmgr->set(0,cc);
    return true;
}
