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

int iadd(int x,int y) {return x+y;}
int imax(int x,int y){return (x > y)?x:y;}
int (*fp)(int,int);

int iarray_inject(int *a,int n,int (*fp)(int,int)){
	int b = 0,m=a[0];
	if((*fp) == iadd){
	for(int i = 0;i < n;++i) {
		b =(*fp)(b,a[i]);
		}
		return b;
	}
	if((*fp) == imax){
	for(int i = 0;i < n;++i){
		if(a[i]> m) {
			m = a[i];
			}
		}
		return m;
	}
	return 0;

}

void expect_int(int b1,int b2,char *msg){
	printf("%s %d:%d %s\n",(b1 == b2)?"OK":"NG",b1,b2,msg);
}

int main(void){
	int a[] = {8,5,2,4,1},b[]={1,-2,3,4,4};
	expect_int(iarray_inject(a,5,iadd),20,"8+5+2+4+1");
	expect_int(iarray_inject(a,5,imax),8,"8,5,2,4,1");
	expect_int(iarray_inject(b,5,iadd),10,"1-2+3+4+4");
	expect_int(iarray_inject(b,5,imax),4,"1,-2,3,4,4");
	}