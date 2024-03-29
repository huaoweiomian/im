#ifndef CONN_MGR_H
#define CONN_MGR_H
#include <map>
using std::map;
//这是一个单例
class CHANNEL;
class CHANNEL_CLIENT;
class CONN_MGR
{
public:
    CONN_MGR();
    CHANNEL* dest_chl(int id);
    void set(int uid, CHANNEL*chl);
private:
    map<int, CHANNEL*> uid_chl;//客户端连接
};

CONN_MGR* singleton();

class CONN_CMGR
{
public:
    CONN_CMGR();
    void set(int id, CHANNEL_CLIENT* cc);
    CHANNEL_CLIENT* get(int id);
private:
    map<int, CHANNEL_CLIENT*> id_cc;
};

CONN_CMGR *csingleton();
#endif // CONN_MGR_H
