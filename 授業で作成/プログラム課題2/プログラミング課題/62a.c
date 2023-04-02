#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool iseven(int n){
	while(n >= 0){
		if(n == 0){
			return true;
		}else if(n == 1){
			return false;
		}else{n -=2;}
	}
	return 0;
}


int main(int argc,char *argv[]){
	int n  = atoi(argv[1]);
	if(iseven(n) == 0){printf("false\n");
	}else{printf("true\n");
	}
	return 0;
}
	