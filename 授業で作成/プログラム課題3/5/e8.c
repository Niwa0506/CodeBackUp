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
	add->next = l->next;
	add->element = e;
//printf("%d\n",add->element);
	return  add;
}

void printf_int_list(list l){
	list print;
	print = l->next;
	while(print!= NULL){
		printf("%d\n",print->element);
		print = print->next;
	}
	//printf("\n");
}
int check(list l,elementtype e){
	list k;
	k =l;
	while(k->next != NULL){
		if(k->next->element==e){return 1;}
		k=k->next;
	}
	return 0;
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
		while(last->next!= NULL){
			//printf("%d\n",last->next->element);
			if(abs(last->next->element)>abs(i)){//printf("%d %d\n",last->next->element,i);
				last =last->next;
			}else{break;}
		}
			if(check(l,i)==1){/*printf("重複したものが見つかりました\n");*/last=l;continue;}
			if(i<0 &&check(l,abs(i))==1){
					last=last->next;
			}//if(abs(last->element)>abs(i)){printf("1\n");}
			//printf_int_list(l);
		last ->next= cons(i,last);//printf_int_list(l);
		last = l;
	}
	printf_int_list(l);
	return 0;
}