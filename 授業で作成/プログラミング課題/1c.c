#include <stdio.h>
#include <string.h>
int main(void){
	int n,i;
	printf("n>");scanf("%d",&n);
	for(i = 2;i <= n;i++) {
		if(n == i){printf("%d\n",i);
		}else{
		if(n%i == 0) {
		n = n/i;
		printf("%d ",i);

		//重複調査
		if(n%i == 0) {
			while(n%i == 0) {
				n = n/i;
				printf("%d ",i);
			}
		}
		}
		}
	}	
}