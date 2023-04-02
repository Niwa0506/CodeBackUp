#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void divide(int a,int b,int *q,int *r){
	if(b == 0){*q = *r = 0;}
	else{*q = a/b;*r = a%b;}
}

int main(int argc,char *argv[]){
	int a = atoi(argv[1]),b = atoi(argv[2]),q = 0,r = 0;
	divide(a,b,&q,&r);
	if(a < 0 && b < 0){printf("Error\n");
	}else{
	printf("%dを%dで割った商は%d,余りは%d\n",a,b,q,r);
	}
}