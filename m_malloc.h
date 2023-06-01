#ifndef M_MALLOC_H
#define M_MALLOC_H

typedef struct __1024_s {
	double	__[128];
} __1024_s_t ;

extern __1024_s_t	STACK[1024];
extern long long	offset;
extern void*	BASESTACK;
extern void*	MAX_STACK;

void*	m_malloc	(int size);
void	m_free		(void* ptr);

#endif