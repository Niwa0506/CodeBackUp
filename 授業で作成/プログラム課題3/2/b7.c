#include <stdio.h>
int search(char a[],char b[],int n_a,int n_b){
	int i,k=0,flag=0,s=0;
for(i =0;i <n_a;i++){
	if(k >= n_b){break;}
	if(a[i] == b[k] && flag == 0){flag=1;k+=1;s=i;}
	else if(a[i] !=b[k] && flag ==1){flag = 0;k=0;}
	else if(a[i] == b[k] && flag == 1){k+=1;} 
}
if(flag ==0){return -1;}
else{return s;}
}
int main(void){
	char a[256],b[256];
	fgets(a,256,stdin);
	fgets(b,256,stdin);
	int i,n_a=0,n_b=0;
	for(i = 0;a[i] !='\n';i++){
		n_a +=1;
		}
	for(i = 0;b[i] != '\n';i++){
		n_b +=1;
	}
	printf("%d %d\n",n_a,n_b);
	printf("%d\n",search(a,b,n_a,n_b));
}