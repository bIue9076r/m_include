#ifndef FATSTR_H
#define FATSTR_H
#include "Bool.h"
#include "m_malloc.h"

typedef struct _fatstr_s {
    int     len;
    char*   data;
} fatstr;

Bool inRange(char);
int getlen(char[]);
fatstr newString(int);
void fcpy(fatstr*,char*);
void fcpyn(fatstr*,char*,int);
Bool fcmp(fatstr* self,fatstr* other);
Bool fcmps(fatstr* self,char other[]);

#endif