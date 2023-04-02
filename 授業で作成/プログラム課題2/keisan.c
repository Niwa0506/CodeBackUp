#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define NACCESS (1024*1024*128)

int *v;

int main(int ac, char **av){
  int size = atoi(av[1]);	/* 第一引数 */
  v = (int *)malloc(size * 4);

  int upto = 100;
  int delta;
  int n;
  int i;
  clock_t start, end;
  double cpu_time;
  int sum;
  

  for(delta = 0; delta <= upto; delta++){
    sum = 0;
    start = clock();
    for(n = NACCESS; n>0; n--){
      sum += v[i];//printf("%d %d\n",i,v[i]);
      i = (i + delta)& (size-1);//printf("%d %d\n",i,v[i]);

    }
     // printf("%d\n",sum); // k+=1;
     // if(k == 10){break;}
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", cpu_time);
  }
  return(sum);
}