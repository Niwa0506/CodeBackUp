#include <stdio.h>
int main(void){
	int m = 9;
	int n = 0;
	int i = 1;
	for(i =1;i*3+1 <= m/9;i = i*3+1){
	printf("%d %d\n",i,m);
	}
}