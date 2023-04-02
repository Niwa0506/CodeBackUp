#include <stdio.h>
struct golden {
  long long int a;
  long long int b;
};

int number = 0;
 /* mult_golden: 第 1引数と第 2引数の積を返す関数 */
 struct golden mult_golden(struct golden x, struct golden y) {
 number += 1;
struct golden z;
z.a = x.a*y.a+x.b*y.b;
z.b = x.a*y.b+x.b*y.a+x.b*y.b;
return z;
}
struct golden power_golden(struct golden x, int n) {
 struct golden z;
 if(n==0){z.a = 1;z.b=0;}
 else{	struct golden q=mult_golden(power_golden(x,n-1),x);
 		z.a =q.a;z.b=q.b;
 		}
 return z;
}

int main() {
 struct golden x;
 int n;
 scanf("%lld %lld", &x.a, &x.b);
 scanf("%d", &n);
 x = power_golden(x, n);
 printf("%lld %lld\n", x.a, x.b);
 printf("%d\n", number);
 return 0;
 }
