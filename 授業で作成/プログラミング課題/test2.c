#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int s =0;
int retsu(int n,int *a){
	int c[100] = {};
	for(int i = 0;i < 100;++i){
		c[i] = 0;
	}
	if(s < n){s = n;}
	if(n == 1){
		*a = 1;
		//printf("%d\n",*a);
		for(int i = 0;*(a-i) != s;++i){
			//if(i == 0){printf("%d ",s);}
			c[s-i-1] = *(a-i);c[0] = s;
			//printf("%d ",*(a-i));
		}
		for(int i = 0;i < 100;++i){
			if(c[i] != 0){printf("%d ",c[i]);}
		}
		printf("\n");
	}else if(n > 1){	
		*a = n;
		//printf("%d ",n);
			retsu(n-1,(a+1));
		if(n >2){/*if(s > n){printf("%d ",s);}*///printf("%d ",*a);
			retsu(n-2,(a+1));
		}
		}
		return 0;
}

int main(int argc,char *argv[]){
	int n = atoi(argv[1]),*a,b[100] = {};a =b;
	retsu(n,a);
	//printf("%d \n",*(a+1));
}