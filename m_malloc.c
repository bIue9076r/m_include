#ifndef M_MALLOC_C
#define M_MALLOC_C
#include "m_malloc.h"

void* m_malloc(int size){
	if ((BASESTACK + offset + size) > MAX_STACK){
		offset = 0;}
	
	void* ptr = BASESTACK + offset;
	offset = offset + size;
	return ptr;
}

void m_free(void* ptr){
	ptr = 0;
}

#endif