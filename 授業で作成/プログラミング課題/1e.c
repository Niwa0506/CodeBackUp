#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main(void) {
	srand((unsigned int)time(NULL));
	int i,b =rand(),n;double c,a;
	int answer;
	printf("n>");scanf("%d",&n);
	printf("%d\n",b);
	a = fmod(b,pow(10,n));c =  fmod(b,pow(10,n-1));
	answer = (a-c)/10;
		printf("%lf\n",a);
		printf("%lf\n",c);
		printf("%d\n",answer);
}