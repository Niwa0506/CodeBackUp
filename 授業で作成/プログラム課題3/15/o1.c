#include <stdio.h>
#define SETMAX 10600

struct set{int elements[SETMAX];int size;};

void init_set(struct set*p,int n,int e){
	p->size=n-1;
	int i,k=0;
	for(i=0;i<n;i++){
		if(i==e)k+=1;
		p->elements[i]=k++;
	}
}

void print_set(struct set*p){
	int i;
	printf("{");
	for(i=0;i<p->size;i++)printf(" %d",p->elements[i]);
		printf(" }\n");
}

int main(){
	int n,e;
	struct set s;
	scanf("%d %d ", &n, &e); /* 入力から n と e を読み込み */ 
	init_set(&s, n, e); /* s のアドレスと n と e を渡す */ 
	print_set(&s);
	return 0;
}