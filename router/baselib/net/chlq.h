#ifndef CHLQ_H
#define CHLQ_H
#include<pthread.h>
#include<list>
using std::list;
#include "channel.h"
class CHLQ
{
    friend class CHANNEL_FACTORY;
    friend void *run_accept(void *arg);
public:
    CHANNEL* read();
    CHANNEL* block_read();
private:
    CHLQ();
    void add_chl(CHANNEL* v);
    bool init();
    list<CHANNEL*> cl;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    pthread_mutex_t cmutex;
};

#endif // CHLQ_H
