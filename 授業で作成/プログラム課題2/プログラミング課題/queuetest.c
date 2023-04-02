#include <stdio.h>
#include <stdlib.h>
#include "iqueue.h"

void readenq(iqueuep q){
	int c;
	printf("s> ");
	for(c = getchar();c !='\n'&& c !=EOF;c = getchar()){
		iqueue_enq(q,c);
	}
}
void expect_int(int b1,int b2,char *msg){
	printf("%s %d:%d %s\n",(b1 == b2)?"OK":"NG",b1,b2,msg);
}

char *bool12str(bool b){return b ? "true":"false";}
void expect_bool(bool b1,bool b2,char *msg){
	printf("%s %s:%s %s\n",(b1 == b2)?"OK":"NG",bool12str(b1),bool12str(b2),msg);
}
int main(void){
	iqueuep q = iqueue_new(4);
	iqueue_enq(q,1);iqueue_enq(q,2);iqueue_enq(q,3);
	expect_bool(iqueue_isfull(q),true,"size =4 queue full");
	iqueue_enq(q,4);
	expect_int(iqueue_deq(q),1,"1st =>1");
	iqueue_enq(q,5);
	expect_int(iqueue_deq(q),2,"2nd =>2");
	expect_int(iqueue_deq(q),3,"3rd =>3");
	expect_bool(iqueue_isempty(q),false,"queue not empty");
	expect_int(iqueue_deq(q),5,"4th =>5");
	expect_bool(iqueue_isempty(q),true,"queue emptied");
	expect_int(iqueue_deq(q),0,"0 returned for empty");
	return 0;
}