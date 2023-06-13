#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complex_s{
    double real;
    double imaginary;
} complex_t;

complex_t complexNew(double,double);
double Real(complex_t*);
double Imaginary(complex_t*);
double Re(complex_t*);
double Img(complex_t*);

complex_t ccadd(complex_t*,complex_t*);
complex_t ccsub(complex_t*,complex_t*);
complex_t ccmul(complex_t*,complex_t*);
complex_t csadd(complex_t*,double);
complex_t cssub(complex_t*,double);
complex_t csmul(complex_t*,double);

typedef struct complex_Class_s {
    struct complex_Class_s (*new)(double,double);
    struct complex_Class_s (*add)(struct complex_Class_s*,struct complex_Class_s*);
    struct complex_Class_s (*sub)(struct complex_Class_s*,struct complex_Class_s*);
    struct complex_Class_s (*mul)(struct complex_Class_s*,struct complex_Class_s*);
    struct complex_Class_s (*sadd)(struct complex_Class_s*,double);
    struct complex_Class_s (*ssub)(struct complex_Class_s*,double);
    struct complex_Class_s (*smul)(struct complex_Class_s*,double);

	/* You have to use the standard libary for this */
	#ifdef _INC_STDIO
    void (*printcall)(struct complex_Class_s*);
	#endif

    double (*Re)(struct complex_Class_s*);
    double (*Img)(struct complex_Class_s*);
    double (*Real)(struct complex_Class_s*);
    double (*Imaginary)(struct complex_Class_s*);

    complex_t number;
} complex_Class;

complex_Class complex_ClassNew(double,double);
complex_Class   Cadd  (complex_Class*,complex_Class*);
complex_Class   Csub  (complex_Class*,complex_Class*);
complex_Class   Cmul  (complex_Class*,complex_Class*);
complex_Class   Csadd (complex_Class*,double);
complex_Class   Cssub (complex_Class*,double);
complex_Class   Csmul (complex_Class*,double);
double   CRe (complex_Class*);
double   CImg (complex_Class*);

/* You have to use the standard libary for this */
#ifdef _INC_STDIO
void    Cprint  (complex_Class*);
#endif

complex_Class Complex = {
    &complex_ClassNew,
    &Cadd,&Csub,&Cmul,
    &Csadd,&Cssub,&Csmul,

    /* You have to use the standard libary for this */
	#ifdef _INC_STDIO
    &Cprint,
	#endif
	
	&CRe,&CImg,&CRe,&CImg,
    {0,0}
};

complex_Class I = {
    &complex_ClassNew,
    &Cadd,&Csub,&Cmul,
    &Csadd,&Cssub,&Csmul,

	/* You have to use the standard libary for this */
	#ifdef _INC_STDIO
    &Cprint,
	#endif
	
	&CRe,&CImg,&CRe,&CImg,
    {0,1}
};

#endif
