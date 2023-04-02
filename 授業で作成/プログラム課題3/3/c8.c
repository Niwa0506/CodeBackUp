#include <stdio.h>
struct golden {
  long long int a;
  long long int b;
};

int number1 = 0,number2=0;
 /* mult_golden: 第 1引数と第 2引数の積を返す関数 */
 struct golden mult_golden(struct golden x, struct golden y) {
 //number2 += 5;number1 += 3;//printf("計算は%d回目 %lld\n",number,x.a);
struct golden z;int a1=x.a,a2=x.b,a3=y.a,a4=y.b;
if(a1 <0){a1=2718+a1;}else{a1=a1%2718;}
if(a2 <0){a2=2718+a2;}else{a2=a2%2718;}
if(a3 <0){a3=2718+a3;}else{a3=a3%2718;}
if(a4 <0){a4=2718+a4;}else{a4=a4%2718;}
int b1=a1*a3,b2=a2*a4,b3=a1*a4,b4=a2*a3,b5=a2*a4;
if(b1 <0){b1=2718+b1;}else{b1=b1%2718;}
if(b2 <0){b2=2718+b2;}else{b2=b2%2718;}
if(b3 <0){b3=2718+b3;}else{b3=b3%2718;}
if(b4 <0){b4=2718+b4;}else{b4=b4%2718;}
if(b5 <0){b5=2718+b4;}else{b5=b5%2718;}
z.a=b1+b2;
z.b=b3+b4+b5;
if(z.a < 0){z.a=2718+z.a;}else{z.a=z.a%2718;}
if(z.b < 0){z.b=2718+z.b;}else{z.b=z.b%2718;}
//			printf("z.bの値は%lld\n",x.a*y.b+x.b*y.a+x.b*y.b);
/*z.b = 	x.a%2718*y.b%2718;z.b*=-1;z.b=z.b%2718;
q.b =	x.b%2718*y.a%2718;z.b*=-1;z.b=z.b%2718;z.b+=q.b;z.b=z.b%2718;
z.b+=	(x.b%2718*y.b%2718)%2718;z.b=z.b%2718;*///printf("%lld\n",z.a);
return z;
}
struct golden power_golden(struct golden x, int n) {
 struct golden z;
 if(n==0){z.a = 1;z.b=0;}
 else if(n%2==0){struct golden q=power_golden(x,n/2);	//printf("前%lld\n",q.b);
 								struct golden w=mult_golden(q,q);
 														//printf("後%lld\n",w.b);
 		z.a =w.a;z.b=w.b;
 		}
 else if(n%2==1){struct golden q=mult_golden(power_golden(x,n-1),x);
 		z.a =q.a;z.b=q.b;}
 return z;
}
struct golden fib(int n){
	struct golden z = {1,-1};
	return power_golden(z,n-1);
}
int main() {
 struct golden x;
 int n;
 scanf("%d", &n);
 x=fib(n);

 printf("%lld\n", x.a);
 return 0;
 }
