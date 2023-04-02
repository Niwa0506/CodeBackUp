#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void iarray_read(int *a,int n) {
	for(int i = 0;i < n;++i) {
		printf("%d> ",i+1);scanf("%d",a+i);
	}
}

void iarray_print(int *a,int n) {
	for(int i = 0;i < n;++i) {
		printf(" %2d",a[i]);
		printf("\n");
	}
}

void *ivec_new(int size) {
	int *a = (int*)malloc((size+1)*sizeof(int));
	a[0] = size;
	return a;
}

bool iarray_equal(int *a,int *b,int n){
	for(int i = 0;i < n;++i){
		if(a[i] !=b[i]){return false;}
		}	
		return true;
	
}

void expect_iarray(int *a,int *b,int n,char *msg){
	printf("%s %s\n", iarray_equal(a,b,n)?"OK":"NG",msg);
	iarray_print(a,n);iarray_print(b,n);}

void ivec_read(int *a) {
	iarray_read(a+1,a[0]);
}
void ivec_print(int *a) {
	iarray_print(a+1,a[0]);
}
int *ivec_concat(int *a,int *b) {
	int *c =ivec_new(a[0]+b[0]),al=1,bl=1;
	c[0] = a[0]+b[0];
	for(int i = 1;i <=a[0]+b[0];++i) {
		if(al <=a[0]){
			if(a[al] < b[bl]){
				c[i] = a[al];al+=1;
			}else{c[i] = b[bl];bl+=1;
			}
		}
		else{
			c[i]=b[bl];bl+=1;
		}
	}
	return c;
}


int main(void) {
	int a[] = {4,1,2,3,4},b[]={4,3,4,5,6},c[]={8,1,2,3,3,4,4,5,6};
	int f[] = {4,1,1,1,1},d[]={4,2,2,2,2},e[]={8,1,1,1,1,2,2,2,2};
	int k[] ={0},l[]= {0},i[]={0};
	int *p = ivec_concat(a,b);
	expect_iarray(p,c,9,"[1,2,3,4]+[3,4,5,6] -> [1,2,3,3,4,4,5,6]");
	int *q= ivec_concat(f,d);
	expect_iarray(q,e,9,"[1,1,1,1]+[2,2,2,2] -> [1,1,1,1,2,2,2,2]");
	int *w = ivec_concat(k,l);
	expect_iarray(w,i,2,"");
	return 0;
}