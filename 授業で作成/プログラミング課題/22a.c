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
//int main(void){
	//int a[] = {4,1,2,3,4},b[] = {3,1,2,3};
	int *c =ivec_new(a[0]+b[0]),al=1,bl=1;
	for(int i = 1;i <=a[0]+b[0];++i) {
		if(a[0]>b[0]){
			if(i%2 == 0){c[i] = b[bl];bl+=1;
			}else{c[i] = a[al];al+=1;}
		}
		else{
			if(i%2 == 0) {c[i] = a[al];al+=1;
			}else{c[i] =b[bl];bl+=1;}
			}
	
	}
	/*for(int i = 1;i <= 7;++i) {
		printf("%d",c[i]);
	}
	printf("\n");*/
	return c;
}


int main(void) {
	int a[] = {4,1,2,3,4},b[] ={3,1,2,3},c[]={7,1,1,2,2,3,3,4};
	int *p = ivec_concat(a,b);
	for(int i = 1;i <= 7;++i){
		printf("%d",*(p+i));}
		printf("\n");
	expect_iarray(p,c,8,"[1,2,3,4]+[1,2,3] -> [1,1,2,2,3,3,4]");
	return 0;
}