#include <stdio.h>
#define DELTA 0.001
//半円
int inside_halfcircle(double x, double y) { 
	return (x*x+ y*y <=4.0 && y <= 1.0);
}
double area(double x1, double x2, double y1, double y2,
			int (*f)(double,double)){
int b1 = (*f)(x1,y1), b2 = (*f)(x1,y2);
int b3 = (*f)(x2,y1), b4 = (*f)(x2,y2),
 bn = b1+b2+b3+b4; 
 	if(x2-x1< DELTA || bn == 0 || bn == 4) { 
 	return bn*0.25*(x2-x1)*(y2-y1);
 	}else{
	double x3 = 0.5*(x1+x2), y3 = 0.5*(y1+y2);
	return 	area(x1, x3, y1, y3,f) + area(x1, x3, y3, y2,f) 
			+ area(x3, x2, y1, y3,f) + area(x3, x2, y3, y2,f);
	} 
}
int main(void) {
printf("%8.6f\n", area(0, 2,0,2,inside_halfcircle));
return 0;
}