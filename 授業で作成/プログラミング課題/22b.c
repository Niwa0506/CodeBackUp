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
int *ivec_concat(int *a) {
//int main(void){
	//int a[] = {4,1,2,3,4},b[] = {3,1,2,3};
	int *c =ivec_new(a[0]),al;
	for(int i = 1;i <=a[0];++i) {
			c[i] =a[a[0]-i+1];
	
	}
	/*for(int i = 1;i <= 7;++i) {
		printf("%d",c[i]);
	}
	printf("\n");*/
	return c;
}


int main(void) {
	int a[] = {4,1,2,3,4},c[]={4,4,3,2,1};
	int *p = ivec_concat(a);
	for(int i = 1;i <= 7;++i){
		printf("%d",*(p+i));}
		printf("\n");
	expect_iarray(p,c,8,"[1,2,3,4] -> [4,3,2,1]");
	return 0;
}