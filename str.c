#ifndef STR_C
#define STR_C
#include "str.h"

int stl(char str[]){
	int len;
	for (len = 1; str[len - 1] != '\0' ; len++){}
	return len;
}

int stn(char str[]){
	int n = stl(str);
	int _ = n;
	
	for (int i = 0; i < _; i++){
		n = n + str[i];
	}
	
	return n;
}

void scpy(char dst[], char src[]){
	int dlen = stl(dst);

	for (int i = 0; i < dlen; i++){
		dst[i] = src[i];
	}
}

void scpyn(int n, char dst[], char src[]){
	for (int i = 0; i < n; i++){
		dst[i] = src[i];
	}
}

Bool charisof(char chr, char lst[]){
	int len = stl(lst);
	Bool r = False;

	for (int i = 0; i < len; i++){
		r = (chr == lst[i]) ? (r + True) : (r);
	}

	return !!r;
}

sstr_t ssplit(char str[], char del[]){
	int len = stl(str);
	char** ret;
	int retlen = 0;
	char stmp[len];
	for(int _=0;_<len;_++){stmp[_]=0;}
	char* tmp;
	int rd = 0;
	Bool empty = True;

	for (int i = 0; i < len; i++){
		if(!empty && charisof(str[i],del)){
			char** nret = m_malloc(sizeof(char*) * (retlen + 1));
			for (int v = 0; v < retlen; v++){nret[v]=ret[v];}
			nret[retlen] = tmp;
			ret = nret;
			retlen++;

			for(int _=0;_<len;_++){stmp[_]=0;}
			rd = 0;
			continue;
		}

		stmp[rd] = str[i];
		tmp = m_malloc(sizeof(char) * stl(stmp));
		scpyn(stl(stmp),tmp,stmp);
		rd++;
		empty = False;
	}
	
	return (sstr_t){ret,retlen};
}

void Toupper(char str[]){
	int len = stl(str);

	for (int i = 0; i < len; i++){
		str[i] = str[i] + ((str[i] > 96 && str[i] < 127)?(-32):(0));
	}
}

void Tolower(char str[]){
	int len = stl(str);

	for (int i = 0; i < len; i++){
		str[i] = str[i] + ((str[i] > 64 && str[i] < 91)?(32):(0));
	}
}

#endif