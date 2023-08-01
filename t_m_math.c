#ifndef T_M_MATH_C
#define T_M_MATH_C
#include "m_math.h"
#include "t_m_math.h"

#include "t_tables.c"

// Table Look Up Sine Radians
double t_sin(double r){
	if(r == pi) {return L_SIN[99];}
	if(r == -pi){return L_SIN[0];}
	while(r < -pi){r = r + pi;}
	while(r > pi) {r = r - pi;}

	int n1 = (int) map(r,-pi,pi,0,STEPS - 1);
	int n2 = (n1 + 1 > STEPS - 1) ? (STEPS - 1) : (n1 + 1);

	double v = L_SIN[n1];
	if(n1 != n2){
		v = map(r,L_IN[n1],L_IN[n2],L_SIN[n1],L_SIN[n2]);
	}

	return v;
}

// Table Look Up Cosine Radians
double t_cos(double r){
	if(r == pi) {return L_COS[99];}
	if(r == -pi){return L_COS[0];}
	while(r < -pi){r = r + pi;}
	while(r > pi) {r = r - pi;}

	int n1 = (int) map(r,-pi,pi,0,STEPS - 1);
	int n2 = (n1 + 1 > STEPS - 1) ? (STEPS - 1) : (n1 + 1);

	double v = L_COS[n1];
	if(n1 != n2){
		v = map(r,L_IN[n1],L_IN[n2],L_COS[n1],L_COS[n2]);
	}

	return v;
}

// Table Look Up Tangent Radians
double t_tan(double r){
	if(r == pi) {return L_TAN[99];}
	if(r == -pi){return L_TAN[0];}
	while(r < -pi){r = r + pi;}
	while(r > pi) {r = r - pi;}

	int n1 = (int) map(r,-pi,pi,0,STEPS - 1);
	int n2 = (n1 + 1 > STEPS - 1) ? (STEPS - 1) : (n1 + 1);

	double v = L_TAN[n1];
	if(n1 != n2){
		v = map(r,L_IN[n1],L_IN[n2],L_TAN[n1],L_TAN[n2]);
	}

	return v;
}

// Table Look Up Sine Degrees
double t_sind(double d){
	double r = rad(d);
	if(r == pi) {return L_SIN[99];}
	if(r == -pi){return L_SIN[0];}
	while(r < -pi){r = r + pi;}
	while(r > pi) {r = r - pi;}

	int n1 = (int) map(r,-pi,pi,0,STEPS - 1);
	int n2 = (n1 + 1 > STEPS - 1) ? (STEPS - 1) : (n1 + 1);

	double v = L_SIN[n1];
	if(n1 != n2){
		v = map(r,L_IN[n1],L_IN[n2],L_SIN[n1],L_SIN[n2]);
	}

	return v;
}

// Table Look Up Cosine Degrees
double t_cosd(double d){
	double r= rad(r);
	if(r == pi) {return L_COS[99];}
	if(r == -pi){return L_COS[0];}
	while(r < -pi){r = r + pi;}
	while(r > pi) {r = r - pi;}

	int n1 = (int) map(r,-pi,pi,0,STEPS - 1);
	int n2 = (n1 + 1 > STEPS - 1) ? (STEPS - 1) : (n1 + 1);

	double v = L_COS[n1];
	if(n1 != n2){
		v = map(r,L_IN[n1],L_IN[n2],L_COS[n1],L_COS[n2]);
	}

	return v;
}

// Table Look Up Tangent Degrees
double t_tand(double d){
	double r = rad(d);
	if(r == pi) {return L_TAN[99];}
	if(r == -pi){return L_TAN[0];}
	while(r < -pi){r = r + pi;}
	while(r > pi) {r = r - pi;}

	int n1 = (int) map(r,-pi,pi,0,STEPS - 1);
	int n2 = (n1 + 1 > STEPS - 1) ? (STEPS - 1) : (n1 + 1);

	double v = L_TAN[n1];
	if(n1 != n2){
		v = map(r,L_IN[n1],L_IN[n2],L_TAN[n1],L_TAN[n2]);
	}

	return v;
}

// Table Look Up Arc-Sine Radians
double t_asin(double y){
	if(y > t_sin(pi2)) {return -0.0;}
	if(y < t_sin(-pi2)){return -0.0;}

	int n1 = -1, n2;
	for(int i = 0; i < STEPS; i++){
		if(y > L_ASIN[i]){n1 = i; n2 = i + 1;}
	}

	if(n1 == -1){n1 = 0; n2 = 0;}
	if(n2 == STEPS){n2 = STEPS - 1;}

	double v = L_IN_2[n1];
	if(n1 != n2){
		v = map(y,L_ASIN[n1],L_ASIN[n2],L_IN_2[n1],L_IN_2[n2]);
	}

	return v;
}

// Table Look Up Arc-Cosine Radians
double t_acos(double y){
	if(y < t_cos(-pi)){return -0.0;}
	if(y > t_cos(0))  {return -0.0;}

	int n1 = -1, n2;
	for(int i = 0; i < STEPS; i++){
		if(y > L_ACOS[i]){n1 = i; n2 = i + 1;}
	}

	if(n1 == -1){n1 = 0; n2 = 0;}
	if(n2 == STEPS){n2 = STEPS - 1;}

	double v = L_IN_N[n1];
	if(n1 != n2){
		v = map(y,L_ACOS[n1],L_ACOS[n2],L_IN_N[n1],L_IN_N[n2]);
	}

	return -v;
}

// Table Look Up Arc-Tangent Radians
double t_atan(double y){
	printf("%f %f %f\n",t_tan(pi2),-t_tan(pi2),y);
	if(y > t_tan(pi2)) {return -0.0;}
	if(y < -t_tan(pi2)){return -0.0;}

	int n1 = -1, n2;
	for(int i = 0; i < STEPS; i++){
		if(y > L_ATAN[i]){n1 = i; n2 = i + 1;}
	}

	if(n1 == -1){n1 = 0; n2 = 0;}
	if(n2 == STEPS){n2 = STEPS - 1;}

	double v = L_IN_2[n1];
	if(n1 != n2){
		v = map(y,L_ATAN[n1],L_ATAN[n2],L_IN_2[n1],L_IN_2[n2]);
	}

	return v;
}

#endif