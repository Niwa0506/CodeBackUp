#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ROSENZU "rosenzu.txt" /* 路線図データファイル */
#define SETMAX 10600 /* 集合の要素数の最大値 (駅の数) */
char buf[256]; /* 入力された文字列を格納するグローバル変数 */
int dist[SETMAX]; /* 指定された駅から各駅までの最短距離を格納するグローバル変数 */
struct node { int eki, rosen, kyori; struct node *next; };
 struct set { int elements[SETMAX]; int size; };

void init_set(struct set *p, int n, int e) {
	p->size=n-1;
	int i,k=0;
	for(i=0;i<n;i++){
		if(i==e)k+=1;
		p->elements[i]=k++;
	}
}

int delete_min(struct set *p) {
	if(p->size==0)return -1;
	int dist_min=dist[p->elements[0]],min=p->elements[0],i=1,j=0;
	while(i<p->size){
		if(dist_min>dist[p->elements[i]]){
			min=p->elements[i];dist_min=dist[min];j=i;
		}
		i++;
	}
	p->elements[j]=p->elements[p->size-1];
	p->size-=1;
	return min;
}
void add_edge(struct node *adjlist[], int eki1, int eki2, int rosen, int kyori) {
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
int dijkstra(struct node *adjlist[], int eki1, int eki2, int ekisu) {
	int i=0,cur=eki1;
	//printf("1\n");
	while(i<ekisu){
		if(i==eki1)dist[i]=0;
		else
			dist[i]=INT_MAX;
		i++;
	}
	struct set *unknown=(struct set*)malloc(sizeof(struct set));
	init_set(unknown,ekisu,eki1);
	//printf("3\n");
	while(cur!=eki2&&unknown->size>0){
	struct node *p=adjlist[cur];
		while(p!=NULL){
			if(p->eki!=eki1){
				if(dist[p->eki]>p->kyori+dist[cur])
					dist[p->eki]=p->kyori+dist[cur];
			}
			p=p->next;
		}
		cur=delete_min(unknown);
	}
	return dist[eki2];
}

int main() {
	int eki1, eki2, rosen, ekisu, i, kyori;
	FILE *fp = fopen(ROSENZU,"r"); 
	fscanf(fp, "%d ",&ekisu);
	struct node *adjlist[ekisu];
	for(i=0;i<ekisu;++i) adjlist[i] = NULL; 
	while(fgets(buf,sizeof(buf),fp)!=NULL) {
		sscanf(buf, "%d:%d:%d:%d ", &eki1, &eki2, &rosen, &kyori); 
		add_edge(adjlist,eki1,eki2,rosen,kyori);
	}
  	fclose(fp);
  	scanf("%d %d ", &eki1, &eki2);
  	printf("%d\n", dijkstra(adjlist, eki1, eki2, ekisu));
  	for(i=0;i<ekisu;++i)
    if(dist[i] < INT_MAX)
      printf("%d: %d\n", i, dist[i]);
	return 0; 
}