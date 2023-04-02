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
	

void iarray_reverse(int *a,int n) {
	int d[100]={},i;
	for(i = 0;i < n;++i) {
		 d[i] = 0;
	} 
	for( i = 0;i < n;++i) {
		 d[i] =a[n-i-1];
	}
	for( i = 0;i < n;++i) {
		 a[i] =d[i];
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

   int main(void) {
	int a[]={8,5,2,4,1};int b[] = {1,4,2,5,8},c[] ={1,2,3},d[] = {3,2,1};
	iarray_reverse(a,5);iarray_reverse(c,3);
	expect_iarray(a,b,5, "85241 -> 14258");
	expect_iarray(c,d,3,"1 -> 1");
		}
		
