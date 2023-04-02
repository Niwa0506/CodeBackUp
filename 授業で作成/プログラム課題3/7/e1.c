#include <stdio.h>

int max_index(int a[],int n){
int i=0,max=a[0],index=0;
while(i<n){
	if(max <=a[i]){
		max=a[i];index=i;
	}
	i++;
}
return index;
}
int main(){
	char buf[128];
	int arr[128],i=0;
	while(fgets(buf,sizeof(buf),stdin)!=NULL && i<128)
		sscanf(buf,"%d",&arr[i++]);

	printf("%d\n",max_index(arr,i));
	return 0;
}