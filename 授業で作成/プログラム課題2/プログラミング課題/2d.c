#include <stdio.h>
#include <stdbool.h>

void iarray_read(int *a,int n){
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

bool iarray_equal(int *a,int *b,int n){
	for(int i = 0;i < n;++i){
		if(a[i] !=b[i]){return false;}
		}	
		return true;
	
}

void expect_iarray(int *a,int *b,int n,char *msg){
	printf("%s %s\n", iarray_equal(a,b,n)?"OK":"NG",msg);
	iarray_print(a,n);iarray_print(b,n);}

void iarray_add(int *a,int *b,int n){
	for(int i = 0;i < n;++i) {
		*(a+i) += *(b+i);
		if(*(a+i) >=10){*(a+i-1) += 1;*(a+i) -=10;}
	}
	}

	int main(void){
	int a[] = {8,5,2,4,1},b[] = {1,1,2,2,3},c[] = {9,6,4,6,4},d[] = {9,9,8,8,7},e[]={1,1,1,1,0};
		iarray_add(a,b,5);expect_iarray(a,c,5, "85241+11223 -> 96464");
		expect_iarray(a+1,c+1,4,"5241+1223 ->6464");
		iarray_add(d,b,5);expect_iarray(d, e, 5, "11110");
	}