#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "../baselib/net/buffer.h"

#pragma pack(1)
const int buff_size_c = 1024;
struct HEADER{
    int len;//包总长
    int type;//协议类型
    unsigned int count;//包计数
    int id;//协议体的内容
};
//{{HEADER::type: xml json protobuff raw(就是普通结构体)
const int XML_c = 0;
const int JSON_c = 1;
const int PROTOBUFF_c = 2;
const int RAW_c = 3;
//}}

//{{HEADER::id
const int LOGIN_c = 0;
const int MSG_c = 1;
//}}

//登录时上报服务信息
struct LOGIN{
    int uid;//用户id
    int msgid;//消息服务id
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
    int id();
    void get_header(HEADER& h);
    void set_header(HEADER& h);
    void set_content(int id, void* content,int sizea);
    void get_content(void* dest, int sizea);
    BUFFER buf;
private:
    HEADER h;
};
#pragma pack()

#endif // PROTOCOL_H
