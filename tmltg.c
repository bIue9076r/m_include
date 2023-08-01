// Look Up Table Generator
#include <stdio.h>
#include "m_math.h"
#include "m_math.c"
#include "t_m_math.h"

int main(void){
	FILE* OUT = fopen("t_tables.c","w");

	fprintf(OUT,"#ifndef T_TABLES_C\n");
	fprintf(OUT,"#define T_TABLES_C\n");
	fprintf(OUT,"#include \"t_m_math.h\"\n\n");
	

	fprintf(OUT,"// -pi to pi domain: [-pi, pi]\ndouble L_IN[STEPS] = {\n");
	for(int i = 0; i < STEPS; i++){
		double s = map(i,0,STEPS,-pi,pi);
		fprintf(OUT,"\t%f,\n",s);
	}
	fprintf(OUT,"};\n\n");

	fprintf(OUT,"// -pi/2 to pi/2 domain: [-pi/2, pi/2]\ndouble L_IN_2[STEPS] = {\n");
	for(int i = 0; i < STEPS; i++){
		double s = map(i,0,STEPS,-pi2,pi2);
		fprintf(OUT,"\t%f,\n",s);
	}
	fprintf(OUT,"};\n\n");

	fprintf(OUT,"// -pi to 0 domain: [-pi, 0]\ndouble L_IN_N[STEPS] = {\n");
	for(int i = 0; i < STEPS; i++){
		double s = map(i,0,STEPS,-pi,0);
		fprintf(OUT,"\t%f,\n",s);
	}
	fprintf(OUT,"};\n\n");

	fprintf(OUT,"// Sine Range\ndouble L_SIN[STEPS] = {\n");
	for(int i = 0; i < STEPS; i++){
		double s = map(i,0,STEPS,-pi,pi);
		fprintf(OUT,"\t%f,\n",msin(s));
	}
	fprintf(OUT,"};\n\n");

	fprintf(OUT,"// Cosine Range\ndouble L_COS[STEPS] = {\n");
	for(int i = 0; i < STEPS; i++){
		double s = map(i,0,STEPS,-pi,pi);
		fprintf(OUT,"\t%f,\n",mcos(s));
	}
	fprintf(OUT,"};\n\n");

	fprintf(OUT,"// Tangent Range\ndouble L_TAN[STEPS] = {\n");
	for(int i = 0; i < STEPS; i++){
		double s = map(i,0,STEPS,-pi,pi);
		fprintf(OUT,"\t%f,\n",mtan(s));
	}
	fprintf(OUT,"};\n\n");

	fprintf(OUT,"// Arc-Sine Domain: [-1, 1]\ndouble L_ASIN[STEPS] = {\n");
	for(int i = 0; i < STEPS; i++){
		double s = map(i,0,STEPS,-pi2,pi2);
		fprintf(OUT,"\t%f,\n",msin(s));
	}
	fprintf(OUT,"};\n\n");

	fprintf(OUT,"// Arc-Cosine Domain: [-1, 1]\ndouble L_ACOS[STEPS] = {\n");
	for(int i = 0; i < STEPS; i++){
		double s = map(i,0,STEPS,-pi,0);
		fprintf(OUT,"\t%f,\n",mcos(s));
	}
	fprintf(OUT,"};\n\n");

	fprintf(OUT,"// Arc-Tangent Domain\ndouble L_ATAN[STEPS] = {\n");
	for(int i = 0; i < STEPS; i++){
		double s = map(i,0,STEPS,-pi2,pi2);
		fprintf(OUT,"\t%f,\n",mtan(s));
	}
	fprintf(OUT,"};\n\n");
	fprintf(OUT,"#endif\n");

	fclose(OUT);
	return 0;
}