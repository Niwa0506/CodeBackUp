#include <stdio.h>
#define DELTA 0.001
//四角形
int inside_rect(double x, double y) { 
	return x <=2 && y <=4;
}
double area(double x1, double x2, double y1, double y2,
			int (*f)(double,double)){
int b1 = (*f)(x1,y1), b2 = (*f)(x1,y2);
int b3 = (*f)(x2,y1), b4 = (*f)(x2,y2);
int bn = b1+b2+b3+b4,count;
if(x1-x2 == 2){int count = 0;} count +=1;
 	if(x2-x1< DELTA || bn == 0 || bn == 4) { 
 	return bn*0.25*(x2-x1)*(y2-y1);}else{
	double x3 = 0.5*(x1+x2), y3 = 0.5*(y1+y2);
	return area(x1, x3, y1, y3,f) + area(x1, x3, y3, y2,f) +
	 area(x3, x2, y1, y3,f) + area(x3, x2, y3, y2,f)+count;
	} 
}
int main(void) {
printf("%8.0f\n",area(0,4,0,4,inside_rect)-8);
return 0;
}