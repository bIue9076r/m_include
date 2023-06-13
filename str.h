#ifndef STR_H
#define STR_H
#include "Bool.h"
#include "m_malloc.h"

typedef struct sstr_s {
	char**	stbl;
	int		size;
} sstr_t;

int		stl		(char[]);
int		stn		(char[]);
void	scpy	(char[],	char[]);
void	scpyn	(int,		char[],	char[]);
sstr_t	ssplit	(char[],	char[]);
void	Toupper	(char[]);
void	Tolower	(char[]);

#endif