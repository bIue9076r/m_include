#ifndef COMPLEX_C
#define COMPLEX_C
#include "comp.h"

complex_t complexNew(double r, double i){
    return (complex_t) {r,i};
}

double Real(complex_t* n){
    return n->real;
}

double Imaginary(complex_t* n){
    return n->imaginary;
}

double Re(complex_t* n){ return n->real; }
double Img(complex_t* n){ return n->imaginary; }

complex_t ccadd(complex_t* a,complex_t* b){
    return (complex_t) {
        (a->real        +   b->real),
        (a->imaginary   +   b->imaginary)
    };
}

complex_t ccsub(complex_t* a,complex_t* b){
    return (complex_t) {
        (a->real        -   b->real),
        (a->imaginary   -   b->imaginary)
    };
}

complex_t ccmul(complex_t* a,complex_t* b){
    return (complex_t) {
        (a->real * b->real)         -   (a->imaginary * b->imaginary),
        (a->real * b->imaginary)    +   (a->imaginary * b->real)
    };
}

complex_t csadd(complex_t* a,double b){
    return (complex_t) {
        (a->real + b),
        (a->imaginary)
    };
}

complex_t cssub(complex_t* a,double b){
    return (complex_t) {
        (a->real - b),
        (a->imaginary)
    };
}

complex_t csmul(complex_t* a,double b){
    return (complex_t) {
        (a->real * b),
        (a->imaginary * b)
    };
}

complex_Class   Cadd  (complex_Class* a,complex_Class* b){
    complex_Class ret = complex_ClassNew(0,0);
    ret.number = ccadd(&a->number,&b->number);
    return ret;
}

complex_Class   Csub  (complex_Class* a,complex_Class* b){
    complex_Class ret = complex_ClassNew(0,0);
    ret.number = ccsub(&a->number,&b->number);
    return ret;
}

complex_Class   Cmul  (complex_Class* a,complex_Class* b){
    complex_Class ret = complex_ClassNew(0,0);
    ret.number = ccmul(&a->number,&b->number);
    return ret;
}

complex_Class   Csadd (complex_Class* a,double b){
    complex_Class ret = complex_ClassNew(0,0);
    ret.number = csadd(&a->number,b);
    return ret;
}

complex_Class   Cssub (complex_Class* a,double b){
    complex_Class ret = complex_ClassNew(0,0);
    ret.number = cssub(&a->number,b);
    return ret;
}

complex_Class   Csmul (complex_Class* a,double b){
    complex_Class ret = complex_ClassNew(0,0);
    ret.number = csmul(&a->number,b);
    return ret;
}

double   CRe (complex_Class* a){
    return Real(&a->number);
}

double   CImg (complex_Class* a){
    return Imaginary(&a->number);
}

/* You have to use the standard libary for this*/
#ifdef _INC_STDIO
void    Cprint  (complex_Class* a){
    char* s;
    s = (a->Img(a) < 0) ? "%.2f %.2fi\n" : "%.2f + %.2fi\n";
    printf(s,a->Re(a),a->Img(a));
    printf("Re: %.2f\n",a->Re(a));
    printf("Img: %.2f\n",a->Img(a));
}
#endif

complex_Class complex_ClassNew(double r, double i){
    complex_Class ret = {
        &complex_ClassNew,
        &Cadd,&Csub,&Cmul,
        &Csadd,&Cssub,&Csmul,

        /* You have to use the standard libary for this*/
		#ifdef _INC_STDIO
    	&Cprint,
		#endif
		
		&CRe,&CImg,&CRe,&CImg,
        (complex_t){r,i}
    };
    return ret;
}

#endif
