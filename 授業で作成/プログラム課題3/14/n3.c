#include <stdio.h>
#include <stdlib.h>
char buf[256];

int main() {
 	int ekisu,i,j,eki1,eki2;
 	float kyori;
 	scanf("%d ", &ekisu);
 	int adjmat[ekisu][ekisu]; /* ← 隣接行列を表す 2次元配列 */
 	/* ※ここを適切なプログラムで埋める */
 	for(i=0;i<ekisu;++i) 
 		for(j=0;j<ekisu;j++)adjmat[i][j] = 0; 
 	while(fgets(buf,sizeof(buf),stdin)!=NULL) {
		/* 隣り合う駅の情報を読取り */
		sscanf(buf, "%d:%d:%f ", &eki1, &eki2,&kyori); 
		/* そのデータを隣接リスト表現のグラフに追加 */ 
		adjmat[eki1][eki2]=1;adjmat[eki2][eki1]=1;
	}
	for(i=0;i<ekisu;i++){
		for(j=0;j<ekisu;j++)
				printf("%d",adjmat[i][j]);
		printf("\n");
	}
 return 0;
}
