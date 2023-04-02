#include <stdio.h>
#include <stdlib.h>
int evensum(int n){
	int sum = 0;
	for(int i = 0;i < n;++i){
		sum += 2*i+1;
	}
	return sum;
}

int main(int ac,char **agv){
	int n = atoi(agv[1]);
	printf("%d\n",evensum(n));
}