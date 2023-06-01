#ifndef S_M_MATH_C
#define S_M_MATH_C
#include "m_math.h"

// SLOW Sine Radians
double __s__sin__(double r,int pres){
	double ret = r;
	for (int i = 1; i <= pres; i++){
		ret = ret + ( ( mpow(-1.0,i) ) * (( mpow(r,2*i) ) / ( factorial(2*i) )) );
	}
	return ret;
}

// SLOW Cosine Radians
double __s__cos__(double r,int pres){
	double ret = 1;
	for (int i = 1; i <= pres; i++){
		ret = ret + ( ( mpow(-1.0,i) ) * (( mpow(r,2*i+1) ) / ( factorial(2*i+1) )) );
	}
	return ret;
}

// Tangent Radians
double __s__tan__(double r,int pres){
	return (__s__sin__(r,pres)/__s__cos__(r,pres));
}

double s_m_sqrt(double n, int pres){
	if (n < 1.0){return 0.0;}
	Bool cmn = commonSquare(n);
	if (cmn){ return cmn; }
	
	double a = n, b = n/a, c = (a+b)/2;
	for (int i = 0; i < pres; i++){
		c = (c+b)/2;
		b = n/c;
	}
	return b;
}

#endif