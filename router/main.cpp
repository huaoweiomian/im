#include <QCoreApplication>
#include "../baselib/net/channel_factory.h"
#include <unordered_map>
#include "../pro/protocol.h"
#include "conn_mgr.h"
#include "loop.h"

using std::unordered_map;
void start_svr();
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    start_svr();

    return a.exec();
}

void start_svr(){
    CHANNEL_FACTORY cf;
    string ip("192.168.106.148");
    CHLQ* q = cf.init(ip,6666, 10);
    while(true){
        CHANNEL* pchl = q->block_read();
        if(pchl->status() == INVALID){
            cout<<"CHANNEL* pchl = q->block_read(); chl invalid"<<endl;
            continue;
        }
        BUFFER b;
        pchl->recv(b);
        unordered_map<CHANNEL*, BUFFER> mp;//处理粘包
        BUFFER ret = item(mp,pchl,b);
        PROTOCOL pro(ret);
        if(!pro.parser()){
            cout<<"start_svr;pro.parser false"<<endl;
            return;
        }
        loop(pro, pchl);
    }

}


