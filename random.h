#ifndef RANDOM_H
#define RANDOM_H

extern const int randtable[16];
extern const int rt1[256];
extern const int rt2[256];
extern const int rt3[256];
extern const int rt4[256];
extern const int rt5[256];
extern const int rt6[256];
extern const int rt7[256];
extern const int rt8[256];
extern const int rt9[256];
extern const int rt10[256];

extern int *rt;

extern int __r_offset;
extern int __r__offset;

void rand_seed(int);
int rand_i(void);

#endif