#ifndef CONN_MGR_H
#define CONN_MGR_H
#include <map>
using std::map;
//这是一个单例
class CHANNEL;
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
#endif // CONN_MGR_H
