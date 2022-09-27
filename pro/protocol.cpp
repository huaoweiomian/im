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
    if(buf.sizef()<(int)sizeof(h)){
        return false;
    }
    memcpy(&h, buf.buff_f(),sizeof (h));
    return true;
}

int PROTOCOL::id()
{
    return h.id;
}

void PROTOCOL::get_content(void *dest, int sizea)
{
    memcpy(dest,(char*)buf.buff_f()+sizeof (h),sizea);
}
void PROTOCOL::set_content(int id, void *content, int sizea){
    h.id = id;
    h.len = sizeof (h)+ sizea;
    buf.clear();
    buf.append(sizeof (h),(char*)&h);
    buf.append(sizea, (char*)content);
}

