#ifndef CHANNEL_H
#define CHANNEL_H
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#include "buffer.h"
#include <string> //EAGAIN
#include <unordered_map>
using std::unordered_map;
enum CHL_STATUS{
    VALID,
    INVALID
};

class CHANNEL
{
    friend class CHANNEL_FACTORY;
public:
    CHANNEL(int fd);
    CHL_STATUS status();
    bool init();
    void recv(BUFFER& barg);
    void send(const BUFFER& b);
    void set_status(CHL_STATUS st);
private:
    //{{
    CHANNEL();//不允许默认构造
    CHANNEL(const CHANNEL&);//不允许拷贝构造
    CHANNEL& operator=(const CHANNEL&);//不允赋值
    //预期是只能使用指针或引用，且每一个生产出来的频道是唯一的。
    //}}
    BUFFER buff;
    int fd;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    pthread_mutex_t cmutex;

    CHL_STATUS stat;
};
BUFFER item(unordered_map<CHANNEL*, BUFFER>& mp,
            CHANNEL* pchl, BUFFER &b);
#endif // CHANNEL_H
