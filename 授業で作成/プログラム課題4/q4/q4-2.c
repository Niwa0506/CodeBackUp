#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
	if(n == 1){
		return 1;
	}else{
		return factorial(n-1)*n;
	}
}

int main(int argc, char *argv[]){
	printf("%d\n", factorial(atoi(argv[1])));
	return 0;
}