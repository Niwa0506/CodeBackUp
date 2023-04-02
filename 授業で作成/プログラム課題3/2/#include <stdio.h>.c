#include <stdio.h>
int main(void){
	int a,i,fib0=0,fib1 = 1,fib;
	scanf("%d",&a);
	if(a>=2){
	for(i = 0;i <= a;i++){
		if(i >=2){fib=fib0+fib1;fib0=fib1,fib1=fib;}
	}
}
else if(a == 0){fib = fib0;}printf("%d\n",a);
else if(a == 1){fib = fib1;}

	printf("%d\n",fib);
}