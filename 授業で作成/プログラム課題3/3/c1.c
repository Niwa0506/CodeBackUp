#include <stdio.h>

struct golden {
  long long int a;
  long long int b;
};

struct golden double_golden(struct golden x) {
struct golden y;
y.a = 2*x.a;y.b=2*x.b;
return y;
}

int main() {
 struct golden x;
 scanf("%lld %lld", &x.a, &x.b); /* &x.a は &(x.a) と同じ意味 */
 x = double_golden(x);
 printf("%lld %lld\n", x.a, x.b);
 return 0;
 }