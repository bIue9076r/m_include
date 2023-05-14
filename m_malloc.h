#ifndef M_MALLOC_H
#define M_MALLOC_H

typedef struct __1024_s {
	double	__[128];
} __1024_s_t ;

long long	offset = 0;
__1024_s_t	STACK[1024];
void*	BASESTACK	=	STACK;
void*	MAX_STACK	=	STACK + (sizeof(__1024_s_t) * 1024);

void*	m_malloc	(int size);
void	m_free		(void* ptr);

#endif