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
	iarray_print(a,n);iarray_print(b,n);
}
void expect_int(int b1,int b2,char *msg){
	printf("%s %d:%d %s\n",(b1 == b2)?"OK":"NG",b1,b2,msg);
}

void iarray_sort(int *a, int n) {
	int m;
	for(int i = 0;i <n;++i){
	for(int i = 0;i <n;++i){
			if(a[i] > a[i+1]){
				m = a[i];a[i]=a[i+1];a[i+1] =m;
			}
		}
	}
}



int main(void) {
	int a[] = {8,5,4,2,1},b[] = {1,2,4,5,8},c[]={3,2,3,6,4,6,4},d[]={2,3,3,4,4,6,6};
	iarray_sort(a,5);expect_iarray(a,b,5,"85421 -> 12458");
	iarray_sort(c,7);expect_iarray(c,d,7,"3236464->233446");　

}