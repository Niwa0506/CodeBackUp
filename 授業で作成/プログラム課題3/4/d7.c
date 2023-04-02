#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXQUEUE 128
char buf[MAXQUEUE];
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

int main(){
 struct queue s;
 int i;
 /* スタック s の初期化 */
 initqueue(&s);
 while(fgets(buf,sizeof(buf),stdin) != NULL) {
 	if(buf[0]=='g') {
 	getq(&s);
 	}else{
 	sscanf(buf,"%d", &i);
 	putq(&s,i);
 	}
 	//printf("%d %d \n",s.front,s.rear);
 	if(s.front <= s.rear){
 	for(i=s.front;i <s.rear;i++){
 		printf("[%d]",s.contents[i]);
 		}
 		printf("\n");}
 	else if(s.front>s.rear){
 	for(i=s.front;i<128;i++)
 		printf("[%d]",s.contents[i]);
 	for(i= 0;i<s.rear;i++)
 		printf("[%d]",s.contents[i]);
 	printf("\n");
 	}
 }

 }