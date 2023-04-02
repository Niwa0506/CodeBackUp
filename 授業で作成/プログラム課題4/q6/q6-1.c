#include <stdio.h>
#include <stdlib.h>

void sort( int a[], int n ){
    int i,j,minindex,s;
    for(i = 0;i<n;i++){
      minindex = a[i];
      for(j = i+1;j < n;j++){
        if(a[j] < minindex){s = minindex;minindex = a[j];a[j] =s;//printf("%d\n",a[j]);
    }
      }
      a[i]= minindex;a[j] = s;
    }

}

int main(int argc,char *argv[]){
	int i;
	int size = argc - 1;
	int* a=(int*)calloc(size, sizeof(int));
	
	for(i=1; i<argc; i++)
		a[i-1] = atoi(argv[i]);

	sort(a,i-1);
	
	for(i=0; i<size; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
