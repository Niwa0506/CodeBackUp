#include <stdio.h>
#include <string.h>
int main(void){
	char a[1000];
	fgets(a,1000,stdin);
	int n=strlen(a),check[1000],i,j;
	for(i=0;i < n-1;i++){
		check[i]=i;
	}
	for(j = 3;j < n-1;j++){
		for(i = 2;i < j;i++){
			if(j%i==0){check[j]=0;}
		}
	}check[1] =0;
	for(int i =0;i < n-1;i++){
		if(check[i] !=0){
			printf("%c",a[check[i]-1]);
		}
	}
	printf("\n");
	/*for(i = 0;i < n;i++){
		if(check[i] != 0){printf("素数は以下である。%d\n",check[i]);}
	}*/
	//printf("%d %s",n,a);
}