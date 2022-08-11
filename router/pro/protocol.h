#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "baselib/net/buffer.h"


struct __attribute__ ((__packed__)) HEADER{
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


//router
//

const int HEADER_ROUTER_c = 0;
struct __attribute__ ((__packed__)) HEADER_ROUTER{
    int len;//包总长
    int id;//协议体是什么内容

};
//{{HEADER_ROUTER::id
const int ROUTER_c = 0;
const int REPORT_INFO_c = 1;
//}}

struct __attribute__ ((__packed__)) BOTH_HEADER{
    HEADER h;
    HEADER_ROUTER hr;
};
#pragma pack(push)
#pragma pack(1)
struct ROUTER{
    int src;//发送方用户id
    int dest;//接收方用户id
};
//登录时上报服务信息
struct REPORT_INFO{
    int uid;//用户id
    int msgid;//消息服务id
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
#pragma pack(pop)

#endif // PROTOCOL_H
