#ifndef M_MATH_C
#define M_MATH_C
#include "m_math.h"

const double pi = 3.1415f;
const double pi2 = pi/2.0f;

double max(double n, double num){
    return n > num ? (num) : (n);
}

int imax(int n,int num){
    return n > num ? (num) : (n);
}

double amax(double n, double num){
    return n > num ? (num) : ((n > 0) ? (n) : (0));
}

int iamax(int n,int num){
    return n > num ? (num) : ((n > 0) ? (n) : (0));
}

double map(double n, double a, double b, double c, double d){
	// map n from range [a,b] to [c,d]
	return (((n - a)*((d - b)/(c - a))) + c);
}

int imap(int n, int a, int b, int c, int d){
	// map n from range [a,b] to [c,d]
	return (((n - a)*((d - b)/(c - a))) + c);
}

double mpow(double b,int n){
	double r = 1;
	for (int i = 1; i <= n; i++){ r = r * b; }
	return r;
}

double rad(double r){
	return (r * pi)/180.0;
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
	return r - mpow(r,3)/(6) + mpow(r,5)/(120);
}

// Fast Cosine Radians
double __fcos__(double r){
	return 1 - mpow(r,2)/(2) + mpow(r,4)/(24);
}

// Fast Tangent Radians
double __ftan__(double r){
	return (__fsin__(r)/__fcos__(r));
}

// Sine Radians
double __sin__(double r){
	return r - mpow(r,3)/(6) + mpow(r,5)/(120) - mpow(r,7)/(5040);
}

// Cosine Radians
double __cos__(double r){
	return 1 - mpow(r,2)/(2) + mpow(r,4)/(24) - mpow(r,6)/(720) + mpow(r,8)/(40320);
}

// Tangent Radians
double __tan__(double r){
	return (__sin__(r)/__cos__(r));
}

// Fast Sine Radians
double fsin(double r){
	Bool even = False;
	if(r == pi2 && r == -pi2){return __fsin__(r);}
	while(r >= pi2  || even){r = r - pi2; even = !even; }
	while(r <= -pi2 || even){r = r + pi2; even = !even; }
	
	return (__fsin__(r));
}

// Fast Cosine Radians
double fcos(double r){
	Bool even = False;
	if(r == pi2 && r == -pi2){return __fcos__(r);}
	while(r >= pi2  || even){r = r - pi2; even = !even; }
	while(r <= -pi2 || even){r = r + pi2; even = !even; }
	
	return (__fcos__(r));
}

// Fast Tangent Radians
double ftan(double r){
	Bool even = False;
	if(r == pi2 && r == -pi2){return __ftan__(r);}
	while(r >= pi2  || even){r = r - pi2; even = !even; }
	while(r <= -pi2 || even){r = r + pi2; even = !even; }
	
	return (__ftan__(r));
}

// Fast Sine Degrees
// -140deg <= d <= 140deg :: +- 0.01
// -180deg <= d <= 180deg :: +- 0.1
double fsind(double d){
	double r = rad(d);
	Bool even = False;
	if(r == pi2 && r == -pi2){return __fsin__(r);}
	while(r >= pi2  || even){r = r - pi2; even = !even; }
	while(r <= -pi2 || even){r = r + pi2; even = !even; }
	
	return (__fsin__(r));
}

// Fast Cosine Degrees
// -160deg <= d <= 160deg :: +- 0.01
// -200deg <= d <= 200deg :: +- 0.1
double fcosd(double d){
	double r = rad(d);
	Bool even = False;
	if(r == pi2 && r == -pi2){return __fcos__(r);}
	while(r >= pi2  || even){r = r - pi2; even = !even; }
	while(r <= -pi2 || even){r = r + pi2; even = !even; }
	
	return (__fcos__(r));
}

// Fast Tangent Degrees
// -140deg <= d <= 140deg :: +- 0.01
// -180deg <= d <= 180deg :: +- 0.1
double ftand(double d){
	double r = rad(d);
	Bool even = False;
	if(r == pi2 && r == -pi2){return __ftan__(r);}
	while(r >= pi2  || even){r = r - pi2; even = !even; }
	while(r <= -pi2 || even){r = r + pi2; even = !even; }
	
	return (__ftan__(r));
}

// -2rad <= r <= 2rad :: +- 0.01
// -3rad <= r <= 3rad :: +- 0.1
double msin(double r){
	Bool even = False;
	if(r == pi2 && r == -pi2){return __sin__(r);}
	while(r >= pi2  || even){r = r - pi2; even = !even; }
	while(r <= -pi2 || even){r = r + pi2; even = !even; }
	
	return (__sin__(r));
}

// -2rad <= r <= 2rad :: +- 0.01
// -3rad <= r <= 3rad :: +- 0.1
double mcos(double r){
	Bool even = False;
	if(r == pi2 && r == -pi2){return __cos__(r);}
	while(r >= pi2  || even){r = r - pi2; even = !even; }
	while(r <= -pi2 || even){r = r + pi2; even = !even; }
	
	return (__cos__(r));
}

// -2rad <= r <= 2rad :: +- 0.01
// -3rad <= r <= 3rad :: +- 0.1
double mtan(double r){
	Bool even = False;
	if(r == pi2 && r == -pi2){return __tan__(r);}
	while(r >= pi2  || even){r = r - pi2; even = !even; }
	while(r <= -pi2 || even){r = r + pi2; even = !even; }
	
	return (__tan__(r));
}

double msind(double d){
	double r = rad(d);
	Bool even = False;
	if(r == pi2 && r == -pi2){return __sin__(r);}
	while(r >= pi2  || even){r = r - pi2; even = !even; }
	while(r <= -pi2 || even){r = r + pi2; even = !even; }
	
	return (__sin__(r));
}

double mcosd(double d){
	double r = rad(d);
	Bool even = False;
	if(r == pi2 && r == -pi2){return __cos__(r);}
	while(r >= pi2  || even){r = r - pi2; even = !even; }
	while(r <= -pi2 || even){r = r + pi2; even = !even; }
	
	return (__cos__(r));
}

double mtand(double d){
	double r = rad(d);
	Bool even = False;
	if(r == pi2 && r == -pi2){return __tan__(r);}
	while(r >= pi2  || even){r = r - pi2; even = !even; }
	while(r <= -pi2 || even){r = r + pi2; even = !even; }
	
	return (__tan__(r));
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