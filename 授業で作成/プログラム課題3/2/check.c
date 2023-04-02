#include <stdio.h>

int c(int n,int k){
	int a[n][k];
	printf("%d %d\n", n,k);
	if( k==0 ||k==n){a[n][k]=1;}
	else if(k==1){a[n][k]=n;}
	else if(k < n){a[n][k]=(c(n-1,k-1)%2718+c(n-1,k)%2718)%2718;}
	return a[n][k];

}

int main(void){
	int n,k;
	scanf("%d %d",&n,&k);
	printf("%d\n",c(n,k));
}