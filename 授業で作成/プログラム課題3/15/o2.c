#include <stdio.h>
#define SETMAX 10600
char buf[256];
struct set{int elements[SETMAX];int size;};

int delete_min_int(struct set*p){
	if(p->size==0)return -1;
	int min=p->elements[0],i=1,j=0;
	while(i<p->size){
		if(min>p->elements[i]){
			min=p->elements[i];j=i;
		}
		i++;
	}
	p->elements[j]=p->elements[p->size-1];
	p->size-=1;
	return min;

}

void print_set(struct set*p){
	int i;
	printf("{");
	for(i=0;i<p->size;i++)printf(" %d",p->elements[i]);
		printf(" }\n");
}

int main(){
	int i,m;
	struct set s;
	i=0;
	while(fgets(buf,sizeof(buf),stdin)!=NULL) {
		sscanf(buf, "%d ", &s.elements[i]); /* 入力された整数値を集合 s に格納 */
		++i; /* 添字を 1 つ増やす */ 
	}
	s.size = i; /* ← この時点で i に要素の数が格納されているはず */ 
	while(1) {
		m = delete_min_int(&s);
		if(m<0) break; /* m が負なら集合が空なので終了 */ 
		printf("%d : ",m); print_set(&s); /* 最小値と集合を出力 */
	}
	return 0;
}