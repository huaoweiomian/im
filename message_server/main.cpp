#include <QCoreApplication>

#include "../baselib/net/channel_client.h"
#include "../baselib/net/channel_factory.h"
#include "../pro/protocol.h"
#include "conn_mgr.h"
#include "loop.h"
void wait_connect();
void connect_svr();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    connect_svr();
    wait_connect();
    return a.exec();
}

void wait_connect(){
    CHANNEL_FACTORY cf;
    string ip("192.168.106.148");
    CHLQ* q = cf.init(ip,8888, 10);
    CHANNEL* pchl = q->block_read();
    BUFFER b;
    pchl->read_from_self(b);
    unordered_map<CHANNEL*, BUFFER> mp;//处理粘包
    BUFFER ret = item(mp,pchl,b);
    PROTOCOL pro(ret);
    if(!pro.parser()){
        cout<<"start_svr;pro.parser false"<<endl;
        return;
    }
    loop(pro);
}
//string ip("192.168.106.148");
//CHLQ* q = cf.init(ip,6666, 10);
void connect_svr(){
    CHANNEL_CLIENT* cc = new  CHANNEL_CLIENT() ;
    string ip("192.168.106.148");
    if(!cc->init(ip, 6666)){
        cout<<"CHANNEL_CLIENT::init error"<<endl;
        return;
    }
    CONN_CMGR* cmgr = csingleton();
    cmgr->set(0,cc);
}
