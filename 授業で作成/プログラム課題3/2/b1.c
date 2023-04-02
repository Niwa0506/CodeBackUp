#include <stdio.h>
int main(void){
	int a,i;
	scanf("%d",&a);
	int fib[100000]={0,1};
	if(a>=2){
	for(i = 0;i <= a;i++){
		if(i >=2){fib[i]=fib[i-1]%2718+fib[i-2]%2718;}
	}
}
	printf("%d\n",fib[a]%2718);
}