#ifndef VECTOR_C
#define VECTOR_C
#include "math.h"
#include "vector.h"

vec vadd(vec* A, vec* B){
    return (vec){A->x + B->x,A->y + B->y,A->z + B->z};
}

vec vsub(vec* A, vec* B){
    return (vec){A->x - B->x,A->y - B->y,A->z - B->z};
}

vec vmul(vec* A, double s){
    return (vec){A->x * s,A->y * s,A->z * s};
}

double vdot(vec* A, vec* B){
    return (A->x * B->x) + (A->y * B->y) + (A->z * B->z);
}

vec vcross(vec* A, vec* B){
    return (vec){
        (A->y * B->z) - (A->z * B->y),
        (A->x * B->z) - (A->z * B->x),
        (A->x * B->y) - (A->y * B->x)
    };
}

double vmag(vec* A){
	return m_sqrt((A->x * A->x) + (A->y * A->y) + (A->z * A->z));
}

vec vunit(vec* A){
	return vmul(A,1.0/vmag(A));
}

vec vclamp(vec* A,double num){
    return (vec){
        amax(A->x,num),
        amax(A->y,num),
        amax(A->z,num),
    };
}

vector vec_add(vector* A, vector* B){
    vector ret = vec_new(0,0,0);
    ret.vector = vadd(&A->vector,&B->vector);
    return ret;
}

vector vec_sub(vector* A, vector* B){
    vector ret = vec_new(0,0,0);
    ret.vector = vsub(&A->vector,&B->vector);
    return ret;
}

vector vec_mul(vector* A,double s){
    vector ret = vec_new(0,0,0);
    ret.vector = vmul(&A->vector,s);
    return ret;
}

double vec_dot(vector* A, vector* B){
    return vdot(&A->vector,&B->vector);
}

vector vec_cross(vector* A, vector* B){
    vector ret = vec_new(0,0,0);
    ret.vector = vcross(&A->vector,&B->vector);
    return ret;
}

vector vec_clamp(vector* A, double m){
    vector ret = vec_new(0,0,0);
    ret.vector = vclamp(A,m);
    return ret;
}

double vec_x(vector* A){
    return A->vector.x;
}

double vec_y(vector* A){
    return A->vector.y;
}

double vec_z(vector* A){
    return A->vector.z;
}

/* You have to use the standard libary for this */
#ifdef _INC_STDIO
void vprint(vector* A){
    printf("%f %f %f\n",A->vector.x,A->vector.y,A->vector.z);
}

void vfprint(FILE* out,vector* A){
    fprintf(out,"%d %d %d\n",(int) A->vector.x,(int) A->vector.y,(int) A->vector.z);
}
#endif

vector vec_new(double x, double y, double z){
    return (vector){
        &vec_new,
        &vec_add,&vec_sub,
        &vec_mul,&vec_dot,
        &vec_cross,&vec_clamp,
        &vec_x,&vec_x,
        &vec_y,&vec_y,
        &vec_z,&vec_z,

		/* You have to use the standard libary for this */
		#ifdef _INC_STDIO
        &vprint,&vfprint,
		#endif
        {x,y,z},
    };
}

const vector Vector = {
    &vec_new,
    &vec_add,&vec_sub,
    &vec_mul,&vec_dot,
    &vec_cross,&vec_clamp,
    &vec_x,&vec_x,
    &vec_y,&vec_y,
    &vec_z,&vec_z,

	/* You have to use the standard libary for this*/
	#ifdef _INC_STDIO
    &vprint,&vfprint,
	#endif
    {0,0,0},
};

#endif