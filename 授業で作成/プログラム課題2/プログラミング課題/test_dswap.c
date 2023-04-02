#include <math.h>
#include <stdio.h>

void dswap(double *x,double *y){
	double z = *x;*x = *y;*y = z;
}

void expect_double(double a,double b,double d,char *msg){
	printf("%s %.10g %.10g %s\n",(fabs(a-b)<d)?"OK":"NG",a,b,msg);
}

int main(void){
	double a = 3.14,b = 2.71;dswap(&a,&b);
	expect_double(a,2.71,1e-10,"a should be 2.71");
	expect_double(b,3.14, 1e-10,"b should be 3.14");
}