#ifndef STR_C
#define STR_C
#include "Bool.h"
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

char* ssplit(char str[], char del[]){
	int len = stl(str);
	char st[len];
	char* ret;
	for (int i = 0; i < len; i++){
		
	}
}

void Toupper(char str[]){
	int len = stl(str);

	for (int i = 0; i < len; i++){
		str[i] = str[i] + ((str[i] > 96 && str[i] < 127)?(32):(0));
	}
}

void Tolower(char str[]){
	int len = stl(str);

	for (int i = 0; i < len; i++){
		str[i] = str[i] + ((str[i] > 64 && str[i] < 91)?(-32):(0));
	}
}

#endif