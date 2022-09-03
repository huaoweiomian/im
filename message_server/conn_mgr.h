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
    void set(int uid, int msgid);
private:
    map<int, CHANNEL*> uid_chl;
    map<int, int> uid_msgid;
};

CONN_MGR* singleton();

class CONN_CMGR
{
public:
    CONN_CMGR();
    void set(int id, CHANNEL_CLIENT* cc);
    CHANNEL_CLIENT* cc(int id);
private:
    map<int, CHANNEL_CLIENT*> id_cc;
};

CONN_CMGR *csingleton();
#endif // CONN_MGR_H
