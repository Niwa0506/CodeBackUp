#include <stdio.h>
#include <stdlib.h>

int gcd(int x,int y){
	int r = x%y;
	if(r == 0){
		return y;
	}else{
		return gcd(y,r);
	}
}

int main(int argc,char *argv[]){
	int x = atoi(argv[1]),y = atoi(argv[2]);
	printf("%d\n",gcd(x,y));
}