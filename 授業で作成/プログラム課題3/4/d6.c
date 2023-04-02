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
	return p->contents[p->front-1];
}

void putq(struct queue *p,elementtype e){
	if(p->rear == MAXQUEUE){printf("Sorry\n");exit(1);}
	else{p->contents[p->rear]=e;p->rear+=1;}
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
 	for(i=s.front;i <s.rear;i++){
 		printf("[%d]",s.contents[i]);
 		}
 		printf("\n");
 }

 }