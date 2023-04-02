#include <stdio.h>
#include <stdlib.h>
#define N 10
#define MAXQUEUE 128
char buf[N+2];
char heya[N][N];
int kyori[N][N];
struct zahyo{
	int x,y;
};
typedef int elementtype;
struct queue {
int front;
int rear;
elementtype contents[MAXQUEUE]; /* 要素を含む配列.front 番目から rear-1番目がスタックの要素 */
};

void initqueue(struct queue *p){
	p->front = 0;p->rear=0;
}

int queueempty(struct queue *p){
	if(p->front ==p->rear){
		return 1;
	}
	return 0;
}
elementtype getq(struct queue *p){
	if(queueempty(p)){printf("Underflow\n");exit(1);}
	p->front+=1;
	if(p->front == MAXQUEUE){p->front = 0;}
	return p->contents[p->front-1];
}

void putq(struct queue *p,elementtype e){
	p->rear+=1;
	if(p->rear==MAXQUEUE){
		p->contents[p->rear-1]=e;p->rear=0;
		if(p->rear==p->front){printf("Overflow\n");exit(1);}
	}else{
	if(p->rear==p->front){printf("Overflow\n");exit(1);}
	p->contents[p->rear-1]=e;}
}
void check(int startx,int starty){
	struct queue x,y;int i,j;
	for(i= 0;i<N;i++){
	for(j=0;j<N;j++){kyori[i][j]=-1;}}
	initqueue(&x);initqueue(&y);
	putq(&x,startx);putq(&y,starty);
	kyori[startx][starty]=0;
	while(queueempty(&x)!=1){
		startx = getq(&x);starty=getq(&y);
		if(heya[startx][starty+1]!='*' &&kyori[startx][starty+1]==-1){
			putq(&x,startx);putq(&y,starty+1);kyori[startx][starty+1]=kyori[startx][starty]+1;}
	if(heya[startx][starty-1]!='*' &&kyori[startx][starty-1]==-1){
		putq(&x,startx);putq(&y,starty-1);kyori[startx][starty-1]=kyori[startx][starty]+1;}
	if(heya[startx+1][starty]!='*' &&kyori[startx+1][starty]==-1){
		putq(&x,startx+1);putq(&y,starty);kyori[startx+1][starty]=kyori[startx][starty]+1;}
	if(heya[startx-1][starty]!='*' &&kyori[startx-1][starty]==-1){
		putq(&x,startx-1);putq(&y,starty);kyori[startx-1][starty]=kyori[startx][starty]+1;}
	}
}
int main(){
	int i,j;
	struct zahyo start,goal;

	i = 0;
	while(fgets(buf,sizeof(buf),stdin)!=NULL){
		for(j=0;j<N;j++){
			if(buf[j]=='S'){
				start.x=i;start.y=j;
			}else if(buf[j]=='G'){
				goal.x=i;goal.y=j;
			}
			heya[i][j]=buf[j];
		}
		++i;
	}
	check(start.x,start.y);
	printf("%d\n",kyori[goal.x][goal.y]);
	
	return 0;
}