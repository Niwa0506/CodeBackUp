#include <stdio.h>
#include <math.h>
int check(int a,int b){
	if(b ==0){return 1;}
	else{
		if(b%2 ==0){
			return (check(a,b/2)*check(a,b/2))%2718;
		}else{return (check(a,b-1)%2718*a%2718)%2718;}
	}
}
int main(void){
	int a,b;
	scanf("%d %d",&a,&b);
printf("%d\n",check(a,b));
}