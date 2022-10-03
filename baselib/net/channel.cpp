#include "channel.h"

CHANNEL::CHANNEL(int afd)
{
    fd = afd;

}

CHL_STATUS CHANNEL::status()
{
    return stat;
}

bool CHANNEL::init()
{
    if(0 != pthread_cond_init(&cond, NULL))
        return false;
    if(0 != pthread_mutex_init(&mutex,NULL))
        return false;
    if(0 != pthread_mutex_init(&cmutex,NULL))
        return false;
    stat = VALID;
    return true;
}

void CHANNEL::recv(BUFFER &barg)
{
    pthread_mutex_lock(&mutex);
    char b[1024];
    int size = 1024;
    while(true){
        int count = ::recv(fd, b, size, MSG_DONTWAIT);
        if(count > 0){
            barg.append(count, b);
            continue;
        }
        if(errno == EINTR || errno == EAGAIN || errno == EWOULDBLOCK){
            break;
        }
        if(count < 0)
        {
            //有异常
            //fixme
            stat = INVALID;
            close(fd);
            pthread_mutex_unlock(&mutex);
            return;
        }
        //EAGAIN,表示当前缓冲区已无数据可读

        if(count == 0)
        {
            // 这里表示对端的socket已正常关闭.
            stat = INVALID;
            close(fd);
            pthread_mutex_unlock(&mutex);
            return;
        }
    }
    pthread_mutex_unlock(&mutex);
}

void CHANNEL::send(const BUFFER &b)
{
    int size = ::send(fd, b.buff_f(), b.sizef(), 0);
    if(size > 0){
    //发送了。暂时不考虑 size < b.sizef()的情况
    }else if(size == 0){
    //表示对方主动关闭了连接过程
    }else{
        //有错误
    }
}

void CHANNEL::set_status(CHL_STATUS st)
{
    stat = st;
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
