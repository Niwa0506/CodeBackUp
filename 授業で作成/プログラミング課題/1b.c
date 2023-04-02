#include <stdio.h>
#include <math.h>
int main(void) {
	int n,i,result =1;
	printf("n>");scanf("%d",&n);
	if(n >= 0){
		for(i = 0;i < n;++i) {
			result *= 2;
		}
		printf("%d\n",result);
	}else{
		printf("%lf\n",pow(2,n));
	}
}