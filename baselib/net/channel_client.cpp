#include "channel_client.h"

CHANNEL_CLIENT::CHANNEL_CLIENT()
{
    sockfd = emptyfd_c;
}

bool CHANNEL_CLIENT::init(std::string &ip, int port)
{
    //1.创建tcp监听套接字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == sockfd){
        return false;
    }
    struct sockaddr_in my_addr;
    memset(&my_addr,0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    if(connect(sockfd, (struct sockaddr*)&my_addr,sizeof(my_addr)) < 0){
        return false;
    }
    return true;
}

CHANNEL_CLIENT::~CHANNEL_CLIENT()
{
    mycolse();
}

bool CHANNEL_CLIENT::mysend(BUFFER& b)
{
    send(sockfd,b.buff_f(),b.sizef(),0);
    return true;
}

void CHANNEL_CLIENT::mycolse()
{
    if(sockfd == emptyfd_c)
        return;
    close(sockfd);
    sockfd = emptyfd_c;
}



CHANNEL_CLIENT::operator int()
{
    return sockfd;
}
