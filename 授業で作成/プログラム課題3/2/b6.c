#include <stdio.h>
#include <string.h>

int main(void){
	char a[128],k,m;
	fgets(a,128,stdin);
	int n = strlen(a),i;
	a[n-1] = '\0';
	printf("%d\n",n);
	for(i = 0;i < n-1;i++){
		k = a[i];m = a[i+1];
		if(k == '/' && m == '/'){
			break;
		}
	}
	printf("%d\n",i);
	//a[i]='\0';
	//printf("%s\n",a);
}