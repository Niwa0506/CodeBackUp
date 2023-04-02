#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int s = 0;
int k = 0;
char abc(int n,int m,char *a,char *c){
	int l = 0;
	//配列の長さを代入	
	if(s < n){s =n;}
	if(n ==1){
		for(int i = 0;i < m;++i){
				k= a[i];*c = k;//printf("%p %c\n",c,*c);
			//for(int j =0;j < s;++j){
			//}
			for(int i = 0;i< s;++i){
				l+=1;
				if(l == s ){//printf("%d\n",l);
				printf("%c\n",*(c+i-s+1));l = 0;
				}else{printf("%c",*(c+i-s+1));}
			}
		}
	}else{
		for(int i = 0;i < m;++i){
			k= a[i];*c = k;//printf("%p %c\n",c,*c);
			abc(n-1,m,a,c+1);
		}

	}
	
	return 0;
}

int main(void){
	int n = 3,m = 3; char a[3]="abc",c[10]={};
		abc(n,m,a,c);
}