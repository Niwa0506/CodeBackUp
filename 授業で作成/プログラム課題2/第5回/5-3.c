#include <stdio.h>

int  fib (  int n ) {
     int  i, p1 = 1, p2 = 1, val;
     for (  i = 1;  i <= n;  i++  ){    /* n番目の数をn=1から順に求める */
          if (  i <= 2  ) {  val = 1; }     /* n≦2のときはfib(n)=1 */
          else {
               val = p1 + p2;     /* p1とp2をfib(n-1)とfib(n-2)に見立てる */
               p2 = p1 ;   /* 次のループのためにp1とp2を更新 */
               p1 = val;    /* 次はvalがfib(n-1), p1がfib(n-2)となる */
          }
     }
     return  val;
}

int main(void){
  int i;
  
  for(i=0; i<10; i++)
    printf("fib(%d) = %d\n", i, fib(i));

}
