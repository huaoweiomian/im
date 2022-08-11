#ifndef CHANNEL_CLIENT_H
#define CHANNEL_CLIENT_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>   //inet_addr,inet_aton
#include <unistd.h>        //read,write,close(fd)
#include <string.h>
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
#include "channel.h"
#include <sys/epoll.h>
#include <pthread.h>
#include "chlq.h"
#include <string>
using std::string;
//线程不安全
const int emptyfd_c = -1;
class CHANNEL_CLIENT
{
public:
    CHANNEL_CLIENT();
public:
    bool init(string& ip, int port);
    operator int();
    ~CHANNEL_CLIENT();
    void mycolse();
private:
    int sockfd;

};
#endif // CHANNEL_CLIENT_H
