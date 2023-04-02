#include <stdio.h>
#include <stdlib.h>
char buf[256];

struct node { int eki, rosen; float kyori; struct node *next; };

void add_edge(struct node *adjlist[], int eki1, int eki2, int rosen, float kyori) { 
 /* ※ここを適切なプログラムで埋める */
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
void print_adjlist(struct node *adjlist[], int n) {
  int i;
  struct node *p;
  for(i=0;i<n;++i) {
    printf("%d:", i);
    p = adjlist[i];
    while(p!=NULL) {
      	printf(" (%d,%d,%.3f)", p->eki, p->rosen, p->kyori);
		p = p->next; }
    printf("\n");
  	}
	return; 
}

int main() {
	int eki1, eki2, rosen, ekisu, i;
	float kyori;
	/* 頂点数 (駅の数) を ekisu に格納 */
	scanf("%d ", &ekisu);
	struct node *adjlist[ekisu];
	/* 隣接リスト表現を初期化.すべての頂点に対する隣接リストを空にする */ 
	for(i=0;i<ekisu;++i) adjlist[i] = NULL; 
	while(fgets(buf,sizeof(buf),stdin)!=NULL) {
	/* 隣り合う駅の情報を読取り */
	sscanf(buf, "%d:%d:%d:%f ", &eki1, &eki2, &rosen, &kyori);
	/* そのデータを隣接リスト表現のグラフに追加 */ 
	add_edge(adjlist, eki1, eki2, rosen, kyori);
  	}
  	print_adjlist(adjlist, ekisu);
  	return 0;
}