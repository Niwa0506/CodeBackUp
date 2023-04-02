#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ROSENZU "rosenzu.txt" /* 路線図データファイル */
#define SETMAX 10600
char buf[256];
int dist[SETMAX];
int prev[SETMAX];
int hop[SETMAX];
/* 集合の要素数の最大値 (駅の数) */
/* 入力された文字列を格納するグローバル変数 */
/* 指定された駅から各駅までの最短距離を格納するグローバル変数 */ /* 各駅までの最短経路における 1つ前の駅を格納するグローバル変数 */ /* 各駅までの最短経路における駅の数を格納するグローバル変数 */
struct node { int eki, rosen, kyori; struct node *next; };
struct set { int elements[SETMAX]; int size; };
void init_set(struct set *p, int n, int e) { /* ※ここは問題1と同じ */
	p->size=n-1;
	int i,k=0;
	for(i=0;i<n;i++){
		if(i==e)k+=1;
		p->elements[i]=k++;
	}
}
int delete_min(struct set *p) {
	if(p->size==0)return -1;
	int dist_min=dist[p->elements[0]],min=p->elements[0],hop_min=hop[p->elements[0]],prev_min=prev[p->elements[0]],i=1,j=0;
	while(i<p->size){
		if(dist_min>dist[p->elements[i]]){
			min=p->elements[i];dist_min=dist[min];hop_min=hop[min];prev_min=prev[min];j=i;
		}else if(dist_min==dist[p->elements[i]]){
			if(hop_min>hop[p->elements[i]]){
				min=p->elements[i];dist_min=dist[min];hop_min=hop[min];prev_min=prev[min];j=i;
			}else if(hop_min==hop[p->elements[i]]){
				if(prev_min>prev[p->elements[i]]){
					min=p->elements[i];dist_min=dist[min];hop_min=hop[min];prev_min=prev[min];j=i;
				}
			}
		}
		i++;
	}
	p->elements[j]=p->elements[p->size-1];
	p->size-=1;
	return min;
}

void add_edge(struct node *adjlist[], int eki1, int eki2, int rosen, int kyori) { /* ※ここは問題4と同じ */
	struct node *p1,*p2;
	p1=(struct node *)malloc(sizeof(struct node));
	p2=(struct node *)malloc(sizeof(struct node));
	//路線追加
	p1->rosen=rosen;p2->rosen=rosen;
	//駅番号追加
	p1->eki=eki1;p2->eki=eki2;
	//距離追加
	p1->kyori = kyori;p2->kyori=kyori;
	//ノード追加
	if(adjlist[eki2]!=NULL){
		p1->next=adjlist[eki2];
		adjlist[eki2]=p1;
	}else{
		adjlist[eki2]=p1;p1->next=NULL;}
	if(adjlist[eki1]!=NULL){
		p2->next=adjlist[eki1];
		adjlist[eki1]=p2;
	}else{
		adjlist[eki1]=p2;p2->next=NULL;}
}

int dijkstra_path(struct node *adjlist[], int eki1, int eki2, int ekisu) { 
	int i,cur=eki1;
	//printf("1\n");
	while(i<ekisu){
		if(i==eki1){dist[i]=0;hop[i]=0;}
		else{
			dist[i]=INT_MAX;hop[i]=INT_MAX;}
		i++;
	}
	struct set *unknown=(struct set*)malloc(sizeof(struct set));
	init_set(unknown,ekisu,eki1);
	//printf("3\n");
	while(cur!=eki2&&unknown->size>0){
	struct node *p=adjlist[cur];
		while(p!=NULL){
			if(p->eki!=eki1){
				if(dist[p->eki]>p->kyori+dist[cur]){
					dist[p->eki]=p->kyori+dist[cur];
					hop[p->eki]=hop[cur]+1;prev[p->eki]=cur;
				}else if(dist[p->eki]==dist[cur]+p->kyori){
					if(hop[p->eki]>hop[cur]+1){
						dist[p->eki]=p->kyori+dist[cur];
						hop[p->eki]=hop[cur]+1;prev[p->eki]=cur;
					}else if(hop[p->eki]==hop[cur]+1){
						if(prev[p->eki]>cur){
							dist[p->eki]=p->kyori+dist[cur];
							hop[p->eki]=hop[cur]+1;prev[p->eki]=cur;
						}
					}
				}
			}
			p=p->next;
		}
		cur=delete_min(unknown);
	}
	return dist[eki2];
}

int main() {
	int eki, eki1, eki2, rosen, ekisu, i, kyori;
	FILE *fp = fopen(ROSENZU,"r"); /* 路線図ファイルの読取り開始 */ 
	fscanf(fp, "%d ", &ekisu); /* 1行目の駅数を読取り */
	struct node *adjlist[ekisu];
	/* 隣接リスト表現を初期化.すべての頂点に対する隣接リストを空にする */
	for(i=0;i<ekisu;++i) adjlist[i] = NULL;
	while(fgets(buf,sizeof(buf),fp)!=NULL) {
	/* 隣り合う駅の情報を読取り */
	sscanf(buf, "%d:%d:%d:%d ", &eki1, &eki2, &rosen, &kyori);
	/* そのデータを隣接リスト表現のグラフに追加 */
	add_edge(adjlist, eki1, eki2, rosen, kyori);
	}
	fclose(fp); /* 路線図ファイルの読取り終了 */
	scanf("%d %d ", &eki1, &eki2);
	kyori = dijkstra_path(adjlist, eki1, eki2, ekisu);
	/* 最短距離を出力 */
	printf("%d:", kyori);
	eki = eki2;
	/* hop[eki]の数だけ前に戻って出力 */
	for(i=0;i<hop[eki2];++i) {
	printf(" %d <-", eki); /* 1つ手前の駅を出力 */
	eki = prev[eki]; /* さらに 1つ手前の駅へ */
	}
	/*プログラムが正しければ，ここでekiが開始駅eki1なっているはず(違っていたら異常終了)*/
	if(eki!=eki1) { fprintf(stderr,"hop or prev is invalid.\n"); exit(1); }
	printf(" %d\n", eki); /* 開始駅を出力 */
	return 0;
}
