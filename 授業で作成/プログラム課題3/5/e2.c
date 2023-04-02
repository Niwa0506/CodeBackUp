#include <stdio.h>
#include <stdlib.h>
typedef int elementtype;
struct node {
	elementtype element;
	struct node *next;
};
typedef struct node* list;
list cons(elementtype e,list l){
	list add;
	add = (list)malloc(sizeof(list));
	add->next = l;
	add->element = e;
//printf("%d\n",add->element);
	return  add;
}
int length(list l){
	list check;int n=0;
	check = (list)malloc(sizeof(list));
	check = l;
	while(check->next!= NULL){
		n+=1;
		check = check->next;
	}
	return n;
}
void printf_int_list(list l){
	list print;
	print = (list)malloc(sizeof(list));
	print = l;
	print = print->next;
	while(print!= NULL){
		printf("[%d]",print->element);
		print = print->next;
	}
	printf("\n");
}
int main(){
	int i;
	char buf[128];
	list l,last;
	l = (list)malloc(sizeof(list));
	l->next = NULL;
	last = l;
	while(fgets(buf,sizeof(buf),stdin)!= NULL){
		sscanf(buf,"%d",&i);
		last->next = cons(i,NULL);
		last = last->next;//printf("%d\n",last->element);
	}
	printf("length=%d\n",length(l));
	printf_int_list(l);
	return 0;
}