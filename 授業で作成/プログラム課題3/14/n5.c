#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
char buf[256];

int diameter(int n,int adjmat[n][n]){
	int reach[n+1][n][n],i,j,k,max;
	//reachの初期化
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)reach[0][i][j]=0;
			else{
				reach[0][i][j]=adjmat[i][j];
			}
		}
	}

	for(k=1;k<=n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
					if(i==j)reach[k][i][j]=0;
					else{
						if(reach[k-1][i][j]>reach[k-1][i][k-1]+reach[k-1][k-1][j]){
							reach[k][i][j]=reach[k-1][i][k-1]+reach[k-1][k-1][j];
						}
						else{reach[k][i][j]=reach[k-1][i][j];}
					}
			}
		}
	}
	int result[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			result[i][j]=reach[n][i][j];
	max=result[0][0];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(result[i][j]>max)
				max=result[i][j];
		}
	}
	return max;
}
int main() {
 	int ekisu,i,j,eki1,eki2,rosen;
 	float kyori;
 	scanf("%d ", &ekisu);
 	int adjmat[ekisu][ekisu]; /* ← 隣接行列を表す 2次元配列 */
 	/* ※ここを適切なプログラムで埋める */
 	for(i=0;i<ekisu;++i) 
 		for(j=0;j<ekisu;j++){
 			if(i==j)adjmat[i][j]=0;
 			else
 				adjmat[i][j] = INT_MAX/2; 
 		}
 	while(fgets(buf,sizeof(buf),stdin)!=NULL) {
		/* 隣り合う駅の情報を読取り */
		sscanf(buf,"%d:%d:%d:%f ",&eki1,&eki2,&rosen,&kyori); 
		/* そのデータを隣接リスト表現のグラフに追加 */ 
		adjmat[eki1][eki2]=1;adjmat[eki2][eki1]=1;
	}
	printf("%d\n",diameter(ekisu,adjmat));
 	return 0;
}
