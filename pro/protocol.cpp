#include "protocol.h"

PROTOCOL::PROTOCOL()
{

}

PROTOCOL::PROTOCOL(BUFFER &b)
{
    buf = b;
}

bool PROTOCOL::parser()
{
    if(buf.sizef()<(int)sizeof(bh)){
        return false;
    }
    memcpy(&bh, buf.buff_f(),sizeof (bh));
    return true;
}

void PROTOCOL::get_struct(void *dest, int sizea)
{
    memcpy(dest,(char*)buf.buff_f()+sizeof (bh),sizea);
}
