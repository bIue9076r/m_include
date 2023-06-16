#ifndef M_MALLOC_C
#define M_MALLOC_C
#include "m_malloc.h"

__1024_s_t	STACK[0x10000];
long long	_m_offset = 0;
void*	BASESTACK	=	STACK;
void*	MAX_STACK	=	STACK + (sizeof(__1024_s_t) * 1024);

void* m_malloc(int size){
	if ((BASESTACK + _m_offset + size) > MAX_STACK){
		_m_offset = 0;}
	
	void* ptr = BASESTACK + _m_offset;
	_m_offset = _m_offset + size;
	return ptr;
}

void m_free(void* ptr){
	ptr = 0;
}

#endif