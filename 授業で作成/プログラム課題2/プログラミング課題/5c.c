#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void expect_double(double a,double b,double d,char *msg){
	printf("%s %.10g:%.10g %s\n",(fabs(a-b)<d)?"OK":"NG",a,b,msg);
}

void normalize(double *x,double *y,double *norm){
	*norm = pow(*x,2)+pow(*y,2);*x = *x / sqrt(*norm);
	*y = *y / sqrt(*norm);
}

int main(void) {
	double x = 1;double y = 2;double norm = 0;
	normalize(&x,&y,&norm);
	printf("%f %f %.1f\n",x,y,norm);
}