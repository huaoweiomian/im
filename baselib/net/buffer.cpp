#include "buffer.h"

BUFFER::BUFFER()
{
    size = 0;
    buff = NULL;
}

BUFFER::BUFFER(int size, char *b)
{
    this->size = size;
    buff = new char[size];
    memcpy(buff, b, size);
}

BUFFER::BUFFER(const BUFFER &b)
{
    size = b.size;
    buff = new char[size];
    memcpy(buff, b.buff, size);
}

BUFFER &BUFFER::operator=(const BUFFER &b)
{
    if(size != 0){
        delete [] buff;
    }
    size = b.size;
    buff = new char[size];
    memcpy(buff, b.buff, size);
    return *this;
}

BUFFER &BUFFER::operator+(const BUFFER &b)
{
    append(b.sizef(),(char*)b.buff_f());
    return *this;
}

BUFFER::~BUFFER()
{
    clear();
}

bool BUFFER::empty()
{
    return size == 0;
}

void BUFFER::append(int s, char* b)
{
    char* btmp = new char[s+size];
    memcpy(btmp, buff,size);
    memcpy(btmp+size,b,s);
    delete[] buff;
    buff = btmp;
    size += s;
}

void BUFFER::append(BUFFER &b)
{
    append(b.sizef(), (char*)b.buff_f());
}

BUFFER BUFFER::left_cut(int sizea)
{
    BUFFER ret;
    if(sizea >= this->size){
        ret.append(size, buff);
        size = 0;
        delete [] buff;
        return ret;
    }
    if(sizea > 0){
        char* retc = new char[sizea];
        memcpy(retc, buff, sizea);
        char* newbuff = new char[size - sizea];
        memcpy(newbuff, buff+sizea,size - sizea);
        size = size - sizea;
        delete [] buff;
        buff = newbuff;
        ret.append(sizea, retc);
        delete [] retc;
        return ret;
    }
    return BUFFER();
}

BUFFER BUFFER::right_cut(int sizea)
{
    BUFFER ret;
    if(sizea >= this->size){
        ret.append(size, buff);
        size = 0;
        delete [] buff;
        return ret;
    }
    if(sizea > 0){
        char* retc = new char[sizea];
        memcpy(retc, buff+size-sizea, sizea);
        char* newbuff = new char[size - sizea];
        memcpy(newbuff, buff,size - sizea);
        size = size - sizea;
        delete [] buff;
        buff = newbuff;
        ret.append(sizea, retc);
        delete [] retc;
        return ret;
    }
    return BUFFER();
}


void BUFFER::clear()
{
    if(size == 0)
        return;
    size = 0;
    delete[] buff;
    buff = NULL;
}



