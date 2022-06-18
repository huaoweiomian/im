#ifndef PROTOCOL_H
#define PROTOCOL_H


class PROTOCOL
{
public:
    PROTOCOL();
};

struct __attribute__ ((__packed__)) HEADER{
    int len;//包总长
    int type;//协议类型
    unsigned int count;//包计数
};

#endif // PROTOCOL_H
