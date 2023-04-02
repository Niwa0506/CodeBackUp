#include <stdio.h>
#include <math.h>
struct golden {
  long long int a;
  long long int b;
};

int main(){
	struct golden x,y;
	scanf("%lld %lld",&x.a,&x.b);
	scanf("%lld %lld",&y.a,&y.b);
	double f = (1+sqrt(5))/2;
	double r=x.a-y.a,t=x.b-y.b;int answer;
	r=r-f*t;
	if(r>0){answer=1;}
	else if(r < 0){answer=-1;}
	else{answer = 0;}
	printf("%d\n",answer);
}
