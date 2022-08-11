#include <QCoreApplication>
#include "baselib/net/channel_factory.h"
#include <unordered_map>
#include "pro/protocol.h"
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
BUFFER item(unordered_map<CHANNEL*, BUFFER>& mp,
            CHANNEL* pchl, BUFFER &b){
    mp[pchl].append(b);
    BUFFER btmp = mp[pchl];
    int* p = (int*)mp[pchl].buff_f();//取报文头参考protocol.h查看报文定义
    if(*p > btmp.sizef()){//包长比数据长，说明数据还没接收完。
        return BUFFER();
    }
    BUFFER ret = btmp.left_cut(*p);
    mp[pchl] = btmp;
    return ret;

}
void loop(PROTOCOL& pro);
CHANNEL* get_dest_chl(HEADER_ROUTER& hr);
void start_svr(){
    CHANNEL_FACTORY cf;
    string ip("192.168.106.148");
    CHLQ* q = cf.init(ip,6666, 10);
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


