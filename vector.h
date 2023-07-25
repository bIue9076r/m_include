#ifndef VECTOR_H
#define VECTOR_H

typedef struct vec_s {
    double x;
    double y;
    double z;
} vec ;

vec vadd(vec*,vec*);
vec vsub(vec*,vec*);
vec vmul(vec*,double);
double vdot(vec*,vec*);
vec vcross(vec*,vec*);
vec vclamp(vec*,double);

typedef struct vect_s {
    struct vect_s (*new)(double,double,double);
    struct vect_s (*add)(struct vect_s*,struct vect_s*);
    struct vect_s (*sub)(struct vect_s*,struct vect_s*);
    struct vect_s (*mul)(struct vect_s*,double);
    double (*dot)(struct vect_s*,struct vect_s*);
    struct vect_s (*cross)(struct vect_s*,struct vect_s*);
    struct vect_s (*clamp)(struct vect_s*,double);

    double (*X)(struct vect_s*);
    double (*x)(struct vect_s*);
    double (*Y)(struct vect_s*);
    double (*y)(struct vect_s*);
    double (*Z)(struct vect_s*);
    double (*z)(struct vect_s*);

	/* You have to use the standard libary for this */
	#ifdef _INC_STDIO
    void (*print)(struct vect_s*);
    void (*fprint)(FILE*,struct vect_s*);
	#endif

    vec vector;
} vector;

vector vec_new(double,double,double);
vector vec_add(vector*,vector*);
vector vec_sub(vector*,vector*);
vector vec_mul(vector*,double);
double vec_dot(vector*,vector*);
vector vec_cross(vector*,vector*);
vector vec_clamp(vector*,double);
double vec_x(vector*);
double vec_y(vector*);
double vec_z(vector*);

/* You have to use the standard libary for this */
#ifdef _INC_STDIO
void vprint(vector*);
void vfprint(FILE*,vector*);
#endif

typedef struct ray_s {
    vector origin;
    vector direction;
} ray;

extern const vector Vector;
extern const vector V;

#endif