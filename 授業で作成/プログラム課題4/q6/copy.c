#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort(char *a[],int n){
	int i = 0,q,j = 0;char top[20],*str[20],non,au;int k,h =0;
	for(;i < n;++i){
		top[i] = *a[i];
		}
		for(i = 0;i <n;++i){
			non = top[i];
			for(int k =i+1;k<n;++k){
				if(non > top[k]){
					au = non;non = top[k];top[k] = au;
				}
			}
			top[i] = non;non= 1;//printf("%c\n",top[i]);
		}
		for(int s=0;s<n;s++){
			au = top[s];
			for(int e=s+1;e<n;e++){
				if(au == top[e]){
					top[e] = '.';
				}
			}
		}
		for(q=0;q<n;q++){
			au = top[q];
			for(k=0;k<n;k++){
				if(au ==*a[k]&& non ==1){str[h]=a[k];h+=1;}
	     }
	     }
	     for(i=0;i < n;++i){
	     	a[i]=str[i];
	     }
		}


		
int main(int argc,char *argv[]){
	char *dic[20];int i;
	for(i=1;i < argc;++i){
		dic[i-1] = argv[i];
		//printf("%s\n",dic[i-1]);
	}	sort(dic,i-1);
	for(int j= 0;j < i-1; ++j){
		printf("%s\n",dic[j]);}
	return 0;
	
}
