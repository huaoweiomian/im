#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "../baselib/net/buffer.h"

#pragma pack(1)
const int buff_size_c = 1024;
struct HEADER{
    int len;//包总长
    int type;//协议类型
    unsigned int count;//包计数
};
//{{HEADER::type: xml json protobuff raw(就是普通结构体)
const int XML_c = 0;
const int JSON_c = 1;
const int PROTOBUFF_c = 2;
const int RAW_c = 3;
//}}

//{{HEADER_MSG_SVR::id
const int MSG_SVR_LOGIN_c = 2;
const int MSG_SVR_MSG_c = 3;
//}}
//router
//
const int HEADER_ROUTER_c = 0;
struct HEADER_ROUTER{
    int len;//包总长
    int id;//协议体是什么内容

};

struct BOTH_HEADER{
    HEADER h;
    HEADER_ROUTER hr;
};

//登录时上报服务信息
struct REPORT_INFO{
    int uid;//用户id
    int msgid;//消息服务id
};

//message_server
typedef HEADER_ROUTER HEADER_MSG_SVR;


struct LOGIN{
    int uid;
};

struct MESSAGE{
    MESSAGE(){
        memset(buff,0,buff_size_c);
    }
    int src;
    int dest;
    int size;
    char buff[buff_size_c];//应该用指针，这应该优化
    int sizef(){
        return size+4*3;
    }
};

class PROTOCOL
{
public:
    PROTOCOL();
    PROTOCOL(BUFFER&b);
    bool parser();
    int type();
    void get_struct(void* dest, int sizea);
    BUFFER buf;
private:
    BOTH_HEADER bh;
};
#pragma pack()

#endif // PROTOCOL_H
