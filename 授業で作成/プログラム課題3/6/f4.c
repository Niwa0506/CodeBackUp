#include <stdio.h>
#include <stdlib.h>
typedef int elementtype;
struct node {
	elementtype element;
	struct node *next;
};
typedef struct node* list;
int next=0;
void printlist(list s){
	list t=s;
	while(t->next!=NULL){printf("%d",t->next->element);t=t->next;}
	printf("\n");
}

void insert(list s,int d){
	list n;
	n = (list)malloc(sizeof(list));
	n->element = d;
	n->next = s->next;
	s->next = n;
}
void min(list s,list t,list k){
	list q=s,e=k,p=t;int i,j;
	while(q->next!=NULL){
		if(e->next==NULL){insert(e,0);}
		i =q->next->element;j=e->next->element+i*(t->next->element)+next;
		if(j>=10){next=j/10;e->next->element=j%10;}
		else{next=0;e->next->element=j%10;}
		e=e->next;q=q->next;}
		if(next!=0){insert(e,next);next=0;}
		/*while(p->next->element==0&&p->next->next!=NULL){
		p->next=p->next->next;}*/
}
int main(){
	int d,flag=1;list s,t,k,l,m,st1,st2;
	char c;
	s=(list)malloc(sizeof(list));
	t=(list)malloc(sizeof(list));
	l=(list)malloc(sizeof(list));
	k=(list)malloc(sizeof(list));
	m=(list)malloc(sizeof(list));
	s->next=NULL;t->next=NULL;l->next=NULL;m->next=NULL;
	while((c=getchar())!='\n'){d=(int)c-'0';insert(s,d);}
	while((c=getchar())!='\n'){d=(int)c-'0';insert(t,d);}
	m=k;st1=s;st2=t;
	while(st1->next!=NULL){
		if(st1->next->element==0){flag=0;}
		else{flag=1;break;}
		st1=st1->next;
	}
	/*0の場合の処理*/
	if(flag!=0){
		while(st2->next!=NULL){
			if(st2->next->element==0){flag=0;}
			else{flag=1;break;}
			st2=st2->next;
		}
	}
	/*通常の処理*/
	if(flag==0){printf("%d\n",flag);}
	else{
	while(s->next!=NULL){min(t,s,k);s=s->next;k=k->next;}
	k=m;
	while(k->next!=NULL){insert(l,k->next->element);k=k->next;}
	/*while(l->next->element==0&&l->next->next!=NULL){
		l->next=l->next->next;
	}*/
	printlist(l);
	}
}