#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int mul(int a,int b){
	if(b == 0){
		return 0;
	}else{
		return a+mul(a,b-1);
	}
}
//末尾再帰
int mulre1(int a,int b,int pro){
	if(b < 1){
		return pro;
	}else{
		return mulre1(a,b-1,pro+a);
	}
}

//再帰除去
int mulre2(int a,int b,int pro){
	while(true){
		if(b == 0){
			return pro;
		}else{pro+=a;b-=1;}
	}
}

int mulre(int a,int b){return (mulre2(a,b,0));}


int main(int argc,char *argv[]){
	int a = atoi(argv[1]),b = atoi(argv[2]);
	printf("%d\n",mulre(a,b));
}

