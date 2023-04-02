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
	//printf("list=%ld\n",sizeof(list));
	add->element = e;
	add->next = l->next;
	l->next = add;
	//l = l->next;

	//printf("%c\n",l->element);
}

void print_int_list(list l){
	list print;
	print = l->next;
	while(print!= NULL){
		printf("%c",print->element);
		print = print->next;
	}
	printf("\n");
}
void change(list l){
	list kagi,kako,hajimari,owari,check,s,t;
	check=l;kagi = l;owari=l;hajimari=l;int flag1=0,flag2=0;
	while(owari->next !=NULL){
		owari =owari->next;
	}
	while(check->next!=NULL){
		if(check->next->element == '(')	{
			if(check->next->next->element==')'){check->next=check->next->next->next;
			}
			else{
			kako=kagi->next;
			kagi->next = check->next->next;
			s=check;flag1=1;//printf("答えは%c\n",kagi->next->element);
			}
		}else if(check->next->element == ')'&&flag1==1)	{//printf("%c\n",check->element);
			s->next=check->next->next;check->next=kako;
			flag1=0;kagi=check;check=l;
		}
		else if(check->next->element == '[') {
			if(check->next->next->element==']'){check->next=check->next->next->next;}
			else{owari->next = check->next->next;t=check;flag2=1;}}
		else if(check->next->element == ']'&&flag2==1){
			t->next=check->next->next;
			check->next=NULL;
			flag2=0;owari=check;
			check=l;

		}
		if(check->next != NULL){check=check->next;//printf("%c\n",check->element);
	}
	}
}
int main(){
	int i,t,d=0;
	char buf[128],c;
	list l,m;
	l = (list)malloc(sizeof(list));
	l->next = NULL;
	fgets(buf,sizeof(buf),stdin);
	for(i=0;(c=buf[i])!='\n';++i){
		if(i ==0){m=l;}//printf("%d\n",d++);
		insert(m,c);//printf("%c\n",l->next->element);
		m =m->next;//printf("%c\n",m->element);
	}
	change(l);
	//printf("KURIa\n");
	print_int_list(l);
	return 0;
}