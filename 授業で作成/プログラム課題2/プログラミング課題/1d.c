#include <stdio.h>

int judge(int x) {
	int i,n =1;
	if(x == 1) {
		n = 0;
				}else{
	for(i = 2; i <= x;++i) {
		if(x%i == 0 && x != i) {n = 0;}						}
					}
	return n;
}
int main(void) {
	int n,i;
	printf("n>");scanf("%d",&n);
	for(i = 1;i < n;++i) {
		if( judge(i) == 1){printf("%d ",i);
	}
	}
	printf("\n");
}