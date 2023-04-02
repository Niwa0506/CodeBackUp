#include <stdio.h>
#include <math.h>
#define DELTA 0.001
//円
int inside_rect(double x, double y, double z) { 
	return x*x+y*y+z*z <= 4;
}
double area(double x1, double x2, double y1, double y2,
			double z1,double z2,int (*f)(double,double,double)){
int b1 = (*f)(x1,y1,z1), b2 = (*f)(x1,y1,z2);
int b3 = (*f)(x1,y2,z1), b4 = (*f)(x1,y2,z2);
int b5 = (*f)(x2,y1,z1), b6 = (*f)(x2,y1,z2);
int b7 = (*f)(x2,y2,z1), b8 = (*f)(x2,y2,z2);
int bn = b1+b2+b3+b4+b5+b6+b7+b8;
 	if(x2-x1< DELTA || bn == 0 || bn == 8) { 
 	return bn*(0.125)*(x2-x1)*(y2-y1)*(z2-z1);}else{
	double x3 = 0.5*(x1+x2), y3 = 0.5*(y1+y2),z3 = 0.5*(z1+z2);
	return 	area(x1, x3, y1, y3,z1,z3,f) + area(x1, x3, y1, y3,z3,z2,f)+
			area(x1, x3, y3, y2,z1,z3,f) + area(x1, x3, y3, y2,z3,z2,f)+
			area(x3, x2, y1, y3,z1,z3,f) + area(x3, x2, y1, y3,z3,z2,f)+
			area(x3, x2, y3, y2,z1,z3,f) + area(x3, x2, y3, y2,z3,z2,f);
	} 
}

double check(int r){
	return (4*M_PI/3)*r*r*r/8;
}
int main(void) {
printf("%8.6f\n",area(0,2,0,2,0,2,inside_rect));
//printf("%8.6f\n",check(2));
return 0;
}