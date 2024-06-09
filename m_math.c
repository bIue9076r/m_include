#ifndef M_MATH_C
#define M_MATH_C
#include "m_math.h"

const double pi = 3.1415f;
const double pi2 = pi/2.0f;

double max(double n, double max){
    return n > max ? (max) : (n);
}

int imax(int n,int max){
    return n > max ? (max) : (n);
}

double amax(double n, double max){
    return n > max ? (max) : ((n > 0) ? (n) : (0));
}

int iamax(int n,int max){
    return n > max ? (max) : ((n > 0) ? (n) : (0));
}

double map(double n, double a, double b, double c, double d){
	// map n from range [a,b] to [c,d]
	return (((n - a)*((d - c)/(b - a))) + c);
}

int imap(int n, int a, int b, int c, int d){
	// map n from range [a,b] to [c,d]
	return (((n - a)*((d - c)/(b - a))) + c);
}

double mpow(double b,int n){
	double r = 1;
	for (int i = 1; i <= n; i++){ r = r * b; }
	return r;
}

double rad(double d){
	return (d * pi)/180.0;
}

double deg(double r){
	return (r * 180.0)/pi;
}

long long int factorial(int n){
	long long int r = 1;
	for(int i = n; i > 0; i--){ r = r * i; }
	return r;
}

/*
1: 1
2: 2
3: 6
4: 24
5: 120
6: 720
7: 5040
8: 40320
9: 362880
10: 3628800
11: 39916800
*/

// Fast Sine Radians
double __fsin__(double r){
	return r - mpow(r,3)/(6) + mpow(r,5)/(120) - mpow(r,7)/(5040);
}

// Fast Cosine Radians
double __fcos__(double r){
	return 1 - mpow(r,2)/(2) + mpow(r,4)/(24) - mpow(r,6)/(720);
}

// Sine Radians
double __sin__(double r){
	return r - mpow(r,3)/(6) + mpow(r,5)/(120) - mpow(r,7)/(5040) + mpow(r,9)/(362880);
}

// Cosine Radians
double __cos__(double r){
	return 1 - mpow(r,2)/(2) + mpow(r,4)/(24) - mpow(r,6)/(720) + mpow(r,8)/(40320);
}

// Fast Sine Radians
double fsin(double r){
	while(r < -pi){r = r + (2*pi);}
	while(r > pi) {r = r - (2*pi);}

	int mode = 0;
	if(r > -pi2){mode = 1;}
	if(r > pi2) {mode = 2;}

	switch(mode){
		case 0:
			return (-__fsin__(r + pi));
		break;

		case 1:
			return (__fsin__(r));
		break;

		case 2:
			return (-__fsin__(r - pi));
		break;

		default:
			return (__fsin__(r));
	}
}

// Fast Cosine Radians
double fcos(double r){
	while(r < -pi){r = r + (2*pi);}
	while(r > pi) {r = r - (2*pi);}

	int mode = 0;
	if(r > -pi2){mode = 1;}
	if(r > pi2) {mode = 2;}

	switch(mode){
		case 0:
			return (-__fcos__(r + pi));
		break;

		case 1:
			return (__fcos__(r));
		break;

		case 2:
			return (-__fcos__(r - pi));
		break;

		default:
			return (__fcos__(r));
	}
}

// Fast Tangent Radians
double ftan(double r){
	return (fsin(r) / fcos(r));
}

// Fast Sine Degrees
double fsind(double d){
	double r = rad(d);
	while(r < -pi){r = r + (2*pi);}
	while(r > pi) {r = r - (2*pi);}

	int mode = 0;
	if(r > -pi2){mode = 1;}
	if(r > pi2) {mode = 2;}

	switch(mode){
		case 0:
			return (-__fsin__(r + pi));
		break;

		case 1:
			return (__fsin__(r));
		break;

		case 2:
			return (-__fsin__(r - pi));
		break;

		default:
			return (__fsin__(r));
	}
}

// Fast Cosine Degrees
double fcosd(double d){
	double r = rad(d);
	while(r < -pi){r = r + (2*pi);}
	while(r > pi) {r = r - (2*pi);}

	int mode = 0;
	if(r > -pi2){mode = 1;}
	if(r > pi2) {mode = 2;}

	switch(mode){
		case 0:
			return (-__fcos__(r + pi));
		break;

		case 1:
			return (__fcos__(r));
		break;

		case 2:
			return (-__fcos__(r - pi));
		break;

		default:
			return (__fcos__(r));
	}
}

// Fast Tangent Degrees
double ftand(double d){
	double r = rad(d);
	return (fsin(r)/fcos(r));
}

// Sine Radians
double msin(double r){
	while(r < -pi){r = r + (2*pi);}
	while(r > pi) {r = r - (2*pi);}

	int mode = 0;
	if(r > -pi2){mode = 1;}
	if(r > pi2) {mode = 2;}

	switch(mode){
		case 0:
			return (-__sin__(r + pi));
		break;

		case 1:
			return (__sin__(r));
		break;

		case 2:
			return (-__sin__(r - pi));
		break;

		default:
			return (__sin__(r));
	}
}

// Cosine Radians
double mcos(double r){
	while(r < -pi){r = r + (2*pi);}
	while(r > pi) {r = r - (2*pi);}

	int mode = 0;
	if(r > -pi2){mode = 1;}
	if(r > pi2) {mode = 2;}

	switch(mode){
		case 0:
			return (-__cos__(r + pi));
		break;

		case 1:
			return (__cos__(r));
		break;

		case 2:
			return (-__cos__(r - pi));
		break;

		default:
			return (__cos__(r));
	}
}

// Tangent Radians
double mtan(double r){
	return (msin(r)/mcos(r));
}

// Sine Degrees
double msind(double d){
	double r = rad(d);
	while(r < -pi){r = r + (2*pi);}
	while(r > pi) {r = r - (2*pi);}

	int mode = 0;
	if(r > -pi2){mode = 1;}
	if(r > pi2) {mode = 2;}

	switch(mode){
		case 0:
			return (-__sin__(r + pi));
		break;

		case 1:
			return (__sin__(r));
		break;

		case 2:
			return (-__sin__(r - pi));
		break;

		default:
			return (__sin__(r));
	}
}

// Cosine Degrees
double mcosd(double d){
	double r = rad(d);
	while(r < -pi){r = r + (2*pi);}
	while(r > pi) {r = r - (2*pi);}

	int mode = 0;
	if(r > -pi2){mode = 1;}
	if(r > pi2) {mode = 2;}

	switch(mode){
		case 0:
			return (-__cos__(r + pi));
		break;

		case 1:
			return (__cos__(r));
		break;

		case 2:
			return (-__cos__(r - pi));
		break;

		default:
			return (__cos__(r));
	}
}

// Tangent Degrees
double mtand(double d){
	double r = rad(d);
	return (msin(r)/mcos(r));
}

int commonSquare(double psqr){
	if (psqr == 1.0)	{return 1;}
	if (psqr == 4.0)	{return 2;}
	if (psqr == 9.0)	{return 3;}
	if (psqr == 16.0)	{return 4;}
	if (psqr == 25.0)	{return 5;}
	if (psqr == 36.0)	{return 6;}
	if (psqr == 49.0)	{return 7;}
	if (psqr == 64.0)	{return 8;}
	if (psqr == 81.0)	{return 9;}
	if (psqr == 100.0)	{return 10;}
	return 0;
}

// Square Root
double m_sqrt(double n){
	if (n < 1){return 0;}
	Bool cmn = commonSquare(n);
	if (cmn){ return cmn; }

	double a = n, b = n/a, c = (a+b)/2;
	for (int i = 0; i < 10; i++){
		c = (c+b)/2;
		b = n/c;
	}
	return b;
}

#endif
