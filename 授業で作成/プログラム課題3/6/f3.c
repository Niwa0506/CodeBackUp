#include <stdio.h>
#include <stdlib.h>
typedef int elementtype;
struct node {
	elementtype element;
	struct node *next;
};
typedef struct node* list;
int next=0;
void insert(list s,int d){
	list n;
	n = (list)malloc(sizeof(list));
	n->element = d;
	n->next = s->next;
	s->next = n;
}
void addlist(list l,list k){
	int s=l->next->element,d=k->next->element;
	//printf("%d\n",d);
	printf("%d %d %d\n",l->next->element,d,next);
	if(s+d+next>=10){l->next->element=s+d+next-10;next=1;}
	else{l->next->element=s+d+next;next=0;}
}
void printlist(list s){
	list t=s;
	while(t->next!=NULL){
		printf("%d",t->next->element);
		t=t->next;
	}
	printf("\n");
}
int main(){
	int d,tq=0,sp=0,flag=0;list s,t,k,l,m;
	char c;
	s=(list)malloc(sizeof(list));
	t=(list)malloc(sizeof(list));
	l=(list)malloc(sizeof(list));
	m=(list)malloc(sizeof(list));
	s->next=NULL;t->next=NULL;l->next=NULL;m->next=NULL,insert(m,0);//n->next=NULL;n->element=0;
	while((c=getchar())!='\n'){d=(int)c-'0';insert(s,d);sp++;}
	while((c=getchar())!='\n'){d=(int)c-'0';insert(t,d);tq++;}
	printf("%d %d\n",sp,tq);
	if(sp<tq){k=t;
		while(s->next!=NULL){addlist(t,s);t=t->next;s=s->next;}
		while(t->next!=NULL){addlist(t,m);t=t->next;}
		while(k->next!=NULL){insert(l,k->next->element);k=k->next;}
		if(next!=0){insert(l,1);}
		//printf("%d\n",t->next->element);
		printlist(l);
	}else{k=s;
			while(t->next!=NULL){addlist(s,t);s=s->next;t=t->next;}
			while(s->next!=NULL){addlist(s,m);s=s->next;}
			while(k->next!=NULL){insert(l,k->next->element);k=k->next;}
			if(next!=0){insert(l,1);}
		printlist(l);}
}