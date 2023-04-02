#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int sum(int x,int y){
	while(x >= 0){
		if(x == 0){
			return y;
		}else{
			x -=1;y+=1;
		}
	}
	return 0;
}
		


int main(int argc,char *argv[]){
	int a  = atoi(argv[1]),b = atoi(argv[2]);
	printf("%d\n",sum(a,b));
	
	return 0;
}