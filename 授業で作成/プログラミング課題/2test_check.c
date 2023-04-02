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
bool iarray_equal(int *a,int *b,int n) {
	for(int i = 0;i < n;++i) {
		if(a[i] != b[i]) {return false;}
		}
		return true;
}
char *bool12str(bool b) {return b ? "true":"false";}

void expect_bool(bool b1,bool b2, char *msg){
	printf("%s %s:%s %s\n",(b1 == b2)?"OK":"NG",bool12str(b1),bool12str(b2),msg);
}

int main(void) {
	int a[] = {0,1,2,3,4,5}, b[] = {9,1,2,3,4,6};
	expect_bool(iarray_equal(a,b,5),false, "01234 : 91234");
	expect_bool(iarray_equal(a+1,b+1,5),false, "12345 : 12346");
    expect_bool(iarray_equal(a+1,b+1,4),true, "1234 : 1234");
    expect_bool(iarray_equal(a+1,b+1,3),true, "123 : 123");
	expect_bool(iarray_equal(a,b,0),true, "[] : []");
	
}