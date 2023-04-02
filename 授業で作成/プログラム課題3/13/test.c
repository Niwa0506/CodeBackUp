#include <stdio.h>

int main(){
	int A[4][4]={{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			printf("%p\n",&A[i][j]);
		}
	}
	return 0;
}