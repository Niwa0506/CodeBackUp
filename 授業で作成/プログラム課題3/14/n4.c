#include <stdio.h>
#include <stdlib.h>
char buf[256];
void print_shall(int n,int adjmat[n][n]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d",adjmat[i][j]);}
		printf("\n");}
}
void warshall(int n,int adjmat[n][n],int result[n][n]){
	int reach[n+1][n][n],i,j,k;
	//reachの初期化
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)reach[0][i][j]=1;
			else{
				reach[0][i][j]=adjmat[i][j];
			}
		}
	}

	for(k=1;k<=n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
					if(i==j)reach[k][i][j]=1;
					else{
						if(reach[k-1][i][k-1]==1&&reach[k-1][k-1][j]==1){
							reach[k][i][j]=1;
						}
						else{
							reach[k][i][j]=reach[k-1][i][j];
						}
					}
			}
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			result[i][j]=reach[n][i][j];
}
int main() {
 	int ekisu,i,j,eki1,eki2;
 	float kyori;
 	scanf("%d ", &ekisu);
 	int adjmat[ekisu][ekisu],result[ekisu][ekisu]; /* ← 隣接行列を表す 2次元配列 */
 	/* ※ここを適切なプログラムで埋める */
 	for(i=0;i<ekisu;++i) 
 		for(j=0;j<ekisu;j++)adjmat[i][j] = 0; 
 	while(fgets(buf,sizeof(buf),stdin)!=NULL) {
		/* 隣り合う駅の情報を読取り */
		sscanf(buf, "%d:%d:%f ", &eki1, &eki2,&kyori); 
		/* そのデータを隣接リスト表現のグラフに追加 */ 
		adjmat[eki1][eki2]=1;adjmat[eki2][eki1]=1;
	}
	//print_shall(ekisu,adjmat);
	warshall(ekisu,adjmat,result);
	print_shall(ekisu,result);
 return 0;
}
