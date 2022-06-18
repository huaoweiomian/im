#include <QCoreApplication>
#include "baselib/net/channel_factory.h"
#include <unordered_map>
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
    int* p = (int*)mp[pchl].buff_f();
    if(*p > btmp.sizef()){//包长比数据长，说明数据还没接收完。
        return BUFFER();
    }
    char* ret = btmp.left_cut(*p);
    mp[pchl] = btmp;
    btmp = BUFFER(*p,ret);
    delete [] ret;
    return btmp;

}
void start_svr(){
    CHANNEL_FACTORY cf;
    string ip("192.168.106.148");
    CHLQ* q = cf.init(ip,6666, 10);
    CHANNEL* pchl = q->block_read();
    BUFFER b;
    pchl->read_from_self(b);
    unordered_map<CHANNEL*, BUFFER> mp;//处理粘包


}
