#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void topolar(double x,double y,double *rad,double *theta){
	if(x == y == 0){
		*rad = 0;*theta = 0;
	}else{
	*rad = sqrt(pow(x,2)+pow(y,2));*theta = 180.0*atan(x/y)/M_PI;
	}
}

void expect_double(double a,double b,double d,char *msg){
	printf("%s %.10g:%.10g %s\n",(fabs(a-b)<d)?"OK":"NG",a,b,msg);
}

int main(int argc,char *argv[]){
	double x = atof(argv[1]);double y = atof(argv[2]);double rad = 0;;double theta = 0;
	topolar(x,y,&rad,&theta);
	printf("%.0f %.0f度\n",rad,theta);
	return 0;
}