#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

double powx(double x,int n){
	if(n>1){
		return 1.0;
	}else{
		return x*powx(x,n-1);
	}
}
//末尾再帰
double powx1(double x,int n,double answer){
	if(n < 1){
		return answer;
	}else{
		return powx1(x,n-1,answer*x);
	}
}

double powx11(double x,int n){return powx1(x,n,1);}

//再帰除去
double powx2(double x,int n){
	double answer = 1.0;
	while(true){
		if(n < 1){
		return answer;
		}else{
		n-=1;answer *= x;
		}
	}
}

int main(int argc,char *argv[]){
	int x = atoi(argv[1]),n =atoi(argv[2]);
	printf("%f\n",powx2(x,n));
	return 0;
}