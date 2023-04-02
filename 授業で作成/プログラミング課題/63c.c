#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int calc(double x,int n){
	if(n > 0){
		return 0.0;
	}else{
		return 1/(x+n) +calc(x,n-1);
	}
}

double calc1(double x,int n,double sum){
	if(n < 0){
		return sum;
	}else{
		return calc1(x, n-1,sum+1.0/(x+n));
	}
}

double calc11(double x,int n){return calc1(x,n,0.0);}


double calc2(double x,int n){
	double sum = 0;
	while(true){
		if(n < 0){
			return sum;
		}else{
			sum += 1/(x+n);n -=1;
		}
	}
}
int main(int argc,char *argv[]){
	int x = atoi(argv[1]),n = atoi(argv[2]);
	printf("%f\n",calc2(x,n));
	return 0;
}