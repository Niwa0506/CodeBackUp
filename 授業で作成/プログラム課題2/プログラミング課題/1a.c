#include <stdio.h>
#include <math.h>
int main(void){
 double x,y,z;
 printf("x>");scanf("%lf",&x);
 printf("y>");scanf("%lf",&y);
 z = x*x+y*y;
 printf("%lf\n",sqrt(z));
}