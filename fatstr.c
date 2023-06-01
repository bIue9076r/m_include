#ifndef FATSTR_C
#define FATSTR_C
#include "fatstr.h"

Bool inRange(char check){
    return (check < 127 && check > 31);
}

int getlen(char ptr[]){
    int r = 0;
    for (int i = 0; inRange(ptr[i]); i++){r++;}
    return r;
}

int fstn(char ptr[]){
    int len = getlen(ptr);
    int ret = 0;
    for (int i = 0; i < len; i++){
        ret = ret + ptr[i];
    }
    return ret;
}

fatstr newString(int sz){
    char* ptr = (char*) m_malloc(sz);
    fatstr ret = {sz,ptr};
    return ret;
}

void fcpy(fatstr* self,char* str){
    for (int i = 0; (i < self->len && str[i] != '\0') ; i++){
        self->data[i] = str[i];
    }
}

void fcpyn(fatstr* self,char* str,int n){
    for (int i = 0; ((i + n) < self->len) && (str[i] != '\0') ; i++){
        self->data[i + n] = str[i];
    }
}

Bool fcmp(fatstr* self,fatstr* other){
    if(self->len != other->len)
        return False;
    int n1 = fstn(self->data);
    int n2 = fstn(other->data);
    
    return (n1 - n2);
}

Bool fcmps(fatstr* self,char other[]){
    int olen = getlen(other);
    if(self->len != olen)
        return False;
    
    int n1 = fstn(self->data);
    int n2 = fstn(other);
    
    return (n1 - n2);
}


#endif