#include <stdio.h>
#include <stdbool.h>

int array_max(int *a,int n) {
	int max = a[0];
	for(int i = 0;i < n;++i) {
		if(a[i] > a[0]){
			max = a[i];
		}
	}
	return max;
}

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

void expect_int(int b1,int b2,char *msg){
	printf("%s %d:%d %s\n",(b1 == b2)?"OK":"NG",b1,b2,msg);
}

int main(void){
	int a[] = {9,0,0,1,2,3},b[] = {-1,-2,-3,-4,-1},c[] ={1};
	expect_int(array_max(a,6),9,"9 0 0 1 2 3");
	expect_int(array_max(a+1,5),3,"0 0 1 2 3");
	expect_int(array_max(b,5),-1,"-1 -3 -2 -4 -1");
	expect_int(array_max(b+1,4),-1,"-2 -3 -4 -1");
	expect_int(array_max(c,1),1,"1");

}