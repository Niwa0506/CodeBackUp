#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 128 /* スタックの要素数の最大値 */ 
char buf[MAXSTACK];
typedef int elementtype;
struct stack {
int top; /* 最後に入れた要素の位置 (添字)，スタックが空なら -1  */
elementtype contents[MAXSTACK]; /* 要素を含む配列.0番目からtop 番目までがスタックの要素  */ 
};
void initstack(struct stack *p){
		//p = (struct stack*) malloc(sizeof(struct stack));
	p->top =-1;//printf("%d\n",p->top);
}
int  stackempty(struct stack *p){
	if(p->top ==-1){return 1;}
	else{return 0;}
}
elementtype pop(struct stack *p){
	if(p->top == -1){printf("Underflow\n");exit(1);}
	else{p->top -=1;return p->contents[p->top+1];}
}
void push(struct stack *p,elementtype e){
	//printf("%d\n",p->top);
	if(p->top == MAXSTACK-1){printf("Overflow\n");exit(1);}
	else{p->top+=1;p->contents[p->top]=e;}
}

 int main(int argc, char const *argv[]){
	struct stack s;
	int i;//s.top =-1;
	initstack(&s);
	while(fgets(buf,sizeof(buf),stdin)!= NULL){
		if(buf[0]=='p'){
			pop(&s);
		}else{
			sscanf(buf,"%d",&i);
			push(&s,i);
		}
		for(i = 0;i <= s.top;i++){
		printf("[%d]",s.contents[i]);}
		printf("\n");
	}
}