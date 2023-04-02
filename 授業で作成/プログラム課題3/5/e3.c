#include <stdio.h>
#include <stdlib.h>
typedef char elementtype;
struct node {
	elementtype element;
	struct node *next;
};
typedef struct node* list;
void insert(list l,elementtype e){
	list add;
	add = (list)malloc(sizeof(list));
	add->element = e;
	add->next = l->next;
	l->next = add;
	//l = l->next;

	//printf("%c\n",l->element);
}

void print_int_list(list l){
	list print;
	print = (list)malloc(sizeof(list));
	print = l;
	print = print->next;
	while(print!= NULL){
		printf("%c",print->element);
		print = print->next;
	}
	printf("\n");
}
int main(){
	int i,t;
	char buf[128],c;
	list l,m;
	l = (list)malloc(sizeof(list));
	l->next = NULL;
	fgets(buf,sizeof(buf),stdin);
	for(i = 0;(c =buf[i])!='\n';++i){
		if(i ==0){m=l;}
		insert(m,c);//printf("%c\n",l->next->element);
		m =m->next;
	}
	print_int_list(l);
	while(fgets(buf,sizeof(buf),stdin)!=NULL){
		sscanf(buf,"%d %c",&i,&c);
		m=l;
		for(t=0;t<i;t++){
			if(m->next == NULL){break;}
			m=m->next;
		}
		insert(m,c);
		print_int_list(l);
	}
	return 0;
}