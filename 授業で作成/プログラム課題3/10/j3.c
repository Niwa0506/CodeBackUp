#include <stdio.h>
#define SIZE 101
int hash(char *s){
	int i,c,S;
	S=(int)s[0]%SIZE;
	for(i=1;i<32;i++){
		c=(int)s[i];
		S=(S*128+c)%101;
	}
	return S;
}

int main(){
	char s[32];
	scanf("%[^\n]",s);
	printf("%d\n",hash(s));
	return 0;
}