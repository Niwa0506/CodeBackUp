#include <stdio.h>
#include <stdlib.h>

typedef int elementtype ;
struct node {
	elementtype element;
	struct node *next;
};

typedef struct node*list;
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
	while(check!= NULL){
		n+=1;
		check = check->next;
	}
	return n;
}
void print_int_list(list l){
	list print;
	print = (list)malloc(sizeof(list));
	print = l;
	while(print != NULL){
		printf("[%d]",print->element);
		print = print->next;
	}
	printf("\n");
}
int main(){
	int i;
	char buf[128];
	list l = NULL;
	while(fgets(buf,sizeof(buf),stdin)!=NULL){
		sscanf(buf,"%d",&i);
		l = cons(i,l);
	}
	printf("length=%d\n",length(l));
	print_int_list(l);
	return 0;
}