#include <stdio.h>
struct golden {
  long long int a;
  long long int b;
};

int number1 = 0,number2=0;
 /* mult_golden: 第 1引数と第 2引数の積を返す関数 */
 struct golden mult_golden(struct golden x, struct golden y) {
 number2 += 5;number1 += 3;//printf("計算は%d回目 %lld\n",number,x.a);
struct golden z;
z.a = x.a*y.a+x.b*y.b;
z.b = x.a*y.b+x.b*y.a+x.b*y.b;
return z;
}
struct golden power_golden(struct golden x, int n) {
 struct golden z;
 if(n==0){z.a = 1;z.b=0;}
 else if(n%2==0){	struct golden q=power_golden(x,n/2);struct golden w=mult_golden(q,q);
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
 //scanf("%lld %lld", &x.a, &x.b);
 scanf("%d", &n);
 //x = power_golden(x, n);
 x=fib(n);
 printf("%lld\n", x.a);
 printf("%d\n", number1);
 printf("%d\n",number2);
 return 0;
 }
