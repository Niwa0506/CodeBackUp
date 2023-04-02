#include <stdio.h>
#include <stdlib.h>
typedef int elementtype;
struct node {
	elementtype element;
	struct node *next;
};
typedef struct node* list;
void insert(list l,elementtype e){
	list add;
	add = (list)malloc(sizeof(list));
	add->element = e;
	add->next=l->next;
	l->next =add;
}

void print_int_list(list l){
	list print;int flag=0,i;
	print = l;
	while(print!= l||flag==0){
		flag=1;//printf("%d周目\n",i++);
		printf("[%d]",print->element);
		print = print->next;
	}
	printf("\n");
}

list sort(list l){
	list s=l,k=l;int flag=0,max=l->element;
	while(s!=l||flag==0){
		flag=1;
		if(max<=s->element){k=s;max=s->element;}
		s=s->next;
	}
	//printf("%d\n",max);
	return k;
}
int main(){
	int i;
	char buf[128];
	list l,m;
	l = (list)malloc(sizeof(list));
	l->next = l;m=l;
	fgets(buf,sizeof(buf),stdin);
	sscanf(buf,"%d",&i);
	l->element=i;
	while(fgets(buf,sizeof(buf),stdin)!= NULL){
		sscanf(buf,"%d",&i);
		insert(m,i);
		m = m->next;//printf("入れたのは%d\n",l->element);
	}
	l=sort(l);//printf("%d\n",l->element);
	//printf("ループ終了\n");
	print_int_list(l);
	return 0;
}