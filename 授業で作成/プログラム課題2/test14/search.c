#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 20000

typedef int elementtype;

int N;

int binarysearch(elementtype x, elementtype a[]){
int l,r,m,n=0;
l = 0;r = N-1;//printf("%f\n",floor(log2(N))+1);
while(l<r){
  m=(l+r)/2;
  if(a[m] < x){l = m+1;}
  else if(a[m] > x){r = m-1;}
  else{l = r=m;}
  n+=1;
}
printf("%d\n",n);
return (l== r && a[l] ==x);
}

int loaddata(char *filename, int data[]){
  FILE *fp;
  char line[20];
  int pos;

  fp = fopen(filename, "r");
  if(fp == NULL){
    fprintf(stderr, "No such file: %s\n", filename);
    exit(1);
  }

  pos = 0;
  while(fgets(line, sizeof(line), fp) != NULL){
    sscanf(line, "%d", &data[pos]);
    pos++;
  }

  fclose(fp);

  return pos;
}

int main(int ac, char **av){
  int ndata;
  int data[SIZE];

  if(ac != 3){
    fprintf(stderr, "Usage: %s <datafile> <key>\n", av[0]);
    exit(1);
  }

  N = loaddata(av[1], data);

  printf("%s\n", binarysearch(atoi(av[2]), data) == 0 ? "not found." : "found.");

  return 0;
}
