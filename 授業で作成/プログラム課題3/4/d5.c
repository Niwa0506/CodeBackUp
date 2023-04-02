#include <stdio.h>
#include <stdlib.h>
#define N 11
#define MAXSTACK 121
char buf[N+2]; char canvas[N][N];
struct zahyo { int x, y; };
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

 int main() {
int i, j;
i = 0;
/* 入力を 1行ずつ読み込んで heya へ格納 */
while( fgets(buf,sizeof(buf),stdin) != NULL ) {
    for(j=0;j<N;++j)
      	canvas[i][j] = buf[j];
		++i; 
}
struct stack x,y;
initstack(&x);
initstack(&y);//printf("%d\n",N/2);
push(&x,N/2);
push(&y,N/2);
canvas[N/2][N/2]='.';
while(x.top>-1 && y.top>-1){
	i=pop(&x);j=pop(&y);//printf("%d %d\n",i,j);
		if(canvas[i+1][j]==' ' && i+1 <N){push(&x,i+1);push(&y,j);canvas[i+1][j]='.';}
		if(canvas[i-1][j]==' '&& i-1 >=0){push(&x,i-1);push(&y,j);canvas[i-1][j]='.';}
		if(canvas[i][j+1]==' ' && j+1 <N){push(&x,i);push(&y,j+1);canvas[i][j+1]='.';}
		if(canvas[i][j-1]==' '&& j-1>=0){push(&x,i);push(&y,j-1);canvas[i][j-1]='.';}
		//printf("check\n");
}

/* canvas の出力 */ 
	for(i=0;i<N;++i) { for(j=0;j<N;++j)
      printf("%c",canvas[i][j]);
    printf("\n");
}
return 0; 
}
