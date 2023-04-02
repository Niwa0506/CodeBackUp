#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTACK 514/* スタックの要素数の最大値 */ 
char buf[MAXSTACK];
typedef char elementtype;
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

void check(char*buf){
	struct stack s;int i,flag=1,k,j;char a = '(',b='{',c='[',d='<';
		printf("%lu\n",strlen(buf));
	for(i = 0;i < strlen(buf);i++){
		if(buf[i]== a){push(&s,')');j+=1;}
		else if(buf[i]==b){push(&s,'}');j+=1;}
		else if(buf[i]==c){push(&s,']');j+=1;}
		else if(buf[i]==d){push(&s,'>');j+=1;}
		else if(buf[i]==')'){
			if(s.contents[s.top]== buf[i]){pop(&s);//printf("popしました\n");
			j-=1;}
			else{flag = 0;break;}
		}
		else if(buf[i]=='}'){
			if(s.contents[s.top]== buf[i]){pop(&s);//printf("popしました\n");
			j-=1;}
			else{flag = 0;break;}
		}
		else if(buf[i]==']'){
			if(s.contents[s.top]== buf[i]){pop(&s);//printf("popしました\n");
			j-=1;}
			else{flag = 0;break;}
		}
		else if(buf[i]=='>'){
			if(s.contents[s.top]== buf[i]){pop(&s);//printf("popしました\n");
			j-=1;}
			else{flag = 0;break;}
		}
	/*for(k=0;k<=j;k++){
	printf("%c",s.contents[k]);}
		printf("\n");*/}
		if(j>0){flag=0;}
	if(flag == 1){printf("Good\n");}
	else{printf("Bad\n");}

}
 int main(int argc, char const *argv[]){
	fgets(buf,sizeof(buf),stdin);
	//printf("%s\n",buf);
	check(buf);
		
}
