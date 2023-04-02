#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void rotate(double *a,double *b,double *c){
	double number;
	number = *c;*c = *b;*b = *a;*a = number;
}

void expect_double(double a,double b,double d,char *msg){
	printf("%s %.10g:%.10g %s\n",(fabs(a-b)<d)?"OK":"NG",a,b,msg);
}

/*int main(int argc,char *argv[]){
	double a = atof(argv[1]),b = atof(argv[2]),c =atof(argv[3]);*/
int main(void){
	double a= 0,b = 1,c = 2;
	printf("%f %f %f\n",a,b,c);
	expect_double(a,0,1e-10,"a should be 0");
	expect_double(b,1,1e-10,"a should be 1.");
	expect_double(c,2,1e-10,"a should be 2");
	rotate(&a,&b,&c);
	printf("%f %f %f\n",a,b,c);
	expect_double(a,2,1e-10,"a should be 2");
	expect_double(b,0,1e-10,"a should be 0.");
	expect_double(c,1,1e-10,"a should be 1");
}	