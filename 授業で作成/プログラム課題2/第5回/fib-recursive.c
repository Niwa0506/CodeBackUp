#include <stdio.h>
#include <stdlib.h>

int fib(int n){
  if(n == 1 || n == 2){
    return 1;
  }else{
    return fib(n - 1) + fib(n - 2);
  }
}

int main(int ac, char **av){
  if(ac != 2){
    fprintf(stderr, "Usage: %s <num>\n", av[0]);
    exit(1);
  }

  printf("%d\n", fib(atoi(av[1])));

  return 0;
}
