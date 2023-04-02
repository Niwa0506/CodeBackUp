#include <stdio.h>
int main(void){
	int a[5] = {8,5,4,2,1},n = 5;
	int m;
	for(int i = 0;i < n;++i){
	for(int i = 0;i < n;++i)
			if(a[i] > a[i+1]){
				m = a[i];a[i]=a[i+1];a[i+1] =m;
			}
		}
	for(int i = 0;i < n;++i){
	printf("%d\n",a[i]);
}
}
