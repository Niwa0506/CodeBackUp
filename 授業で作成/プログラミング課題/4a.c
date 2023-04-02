#include <stdio.h>
#include <stdlib.h>
#include "iqueue.h"

int number=0,wi=0,wo=0;
struct iqueue {int ip,op,size;int *arr;};
iqueuep iqueue_new(int size){
	iqueuep p =(iqueuep)malloc(sizeof(struct iqueue));
	p -> ip =p -> op = 0;p->size = size;
	p-> arr =(int*)malloc(size*sizeof(int));return p;
}
bool iqueue_isempty(iqueuep p){return (p->ip ==p->op && wi == wo);}
bool iqueue_isfull(iqueuep p){return p->size == number;}
void iqueue_enq(iqueuep p,int v){
	if(iqueue_isfull(p)){return;}
	if(p->size == p->ip &&number != p->size){p->ip = 0;wi+=1;}
	p->arr[p->ip++] = v;number+=1;if(p->ip-1 >= p->size){p->ip = 0;}
}
int iqueue_deq(iqueuep p){
	if(iqueue_isempty(p)){return 0;}
	int v = p->arr[p->op++];number -=1;if(p->op==p->size){p->op = 0;wo+=1;}
	return v;
}

//チェッカー
void expect_int(int b1,int b2,char *msg){
	printf("%s %d:%d %s\n",(b1 == b2)?"OK":"NG",b1,b2,msg);
}

char *bool12str(bool b){return b ? "true":"false";}
void expect_bool(bool b1,bool b2,char *msg){
	printf("%s %s:%s %s\n",(b1 == b2)?"OK":"NG",bool12str(b1),bool12str(b2),msg);
}

//実行
int main(void){
	iqueuep q = iqueue_new(4);
	iqueue_enq(q,1);iqueue_enq(q,2);iqueue_enq(q,3);
	expect_bool(iqueue_isfull(q),false,"size =4 queue full");
	iqueue_enq(q,4);	
	expect_int(iqueue_deq(q),1,"1st =>1");printf("%d\n",number);
	iqueue_enq(q,5);printf("%d\n",number);
	expect_int(iqueue_deq(q),2,"2nd =>2");printf("%d\n",number);
	expect_int(iqueue_deq(q),3,"3rd =>3");printf("%d\n",number);
	expect_bool(iqueue_isempty(q),false,"queue not empty");printf("%d\n",number);
	expect_int(iqueue_deq(q),4,"4th =>5");printf("%d\n",number);
	expect_int(iqueue_deq(q),5,"5th =>5");printf("%d\n",number);
	expect_bool(iqueue_isempty(q),true,"queue emptied");printf("%d\n",number);
	expect_int(iqueue_deq(q),0,"0 returned for empty");printf("%d\n",number);
	return 0;
}