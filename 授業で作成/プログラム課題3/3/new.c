#include <stdio.h>
#include <math.h>
struct golden {
  long long int a;
  long long int b;
};

int main(){
	struct golden x,y;
	scanf("%lld %lld",x.a,x.b);
	scanf("%lld %lld",y.a,y.b);
	printf("%lld\n",)
	double f = 1+sqrt(5);
	double r=2*(x.a-y.a),t=y.b-x.b;int answer;
	if(t!=0){r=-r/t;}
	else{f=0;}
	if(r>0){answer=1;}
	else if(r < 0){answer=-1;}
	else{answer = 0;}
	printf("%d\n",answer);
}
