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
	//int a[] = {4,8,2,3,4};
	int *c =ivec_new(a[0]),m;
	for(int i = 0;i <=a[0];++i) {
		for(int j = 1;j <=a[0];++j){
		if(a[j] > a[j+1]){
			m = a[j];a[j] = a[j+1];a[j+1] = m;
		}
			}
	
	}
	for(int i = 1;i <= 4;++i) {
		c[i] =a[i];
		//printf("%d",c[i]);
	}
	//printf("\n");
	return c;
}


int main(void) {
	int a[] = {4,4,3,2,1},c[]={4,1,2,3,4};
	int *p = ivec_concat(a);
	for(int i = 1;i <= 7;++i){
		printf("%d",*(p+i));}
		printf("\n");
	expect_iarray(p,c,8,"[1,2,3,4] -> [4,3,2,1]");
	return 0;
}