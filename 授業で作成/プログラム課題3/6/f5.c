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
	list t=s;int n=0;
	while(t->next!=NULL){
		if(n==0){printf("%d",t->next->element);n+=1;}
		else{printf("%04d",t->next->element);}
	t=t->next;}
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
	list q=s,e=k;int i,j;
	while(q->next!=NULL){
		if(e->next==NULL){insert(e,0);}
		i =q->next->element;j=e->next->element+i*(t->next->element)+next;
		//printf("%d %d %d\n",i,t->next->element,j);
		if(j>=10000){next=j/10000;e->next->element=j%10000;}
		else{next=0;e->next->element=j%10000;}
		e=e->next;q=q->next;}
		if(next!=0){insert(e,next);next=0;}
		//printlist(k);
}

int main(){
	int i=0,d,d1=0,d2=0,d3=0,d4=0,flag=1;list s,t,k,l,m,st1,st2,ss,tt,r,z;
	char c;
	s=(list)malloc(sizeof(list));
	t=(list)malloc(sizeof(list));
	l=(list)malloc(sizeof(list));
	k=(list)malloc(sizeof(list));
	m=(list)malloc(sizeof(list));
	ss=(list)malloc(sizeof(list));
	tt=(list)malloc(sizeof(list));
	r=(list)malloc(sizeof(list));
	z=(list)malloc(sizeof(list));
	s->next=NULL;t->next=NULL;l->next=NULL;m->next=NULL;ss->next=NULL;
	tt->next=NULL;
	/*sとtの代入*/
	while((c=getchar())!='\n'){
		d=(int)c-'0';insert(ss,d);}
	while(ss->next!=NULL){
		d = ss->next->element;
		if(i==0){d1=ss->next->element;i++;}
		else if(i==1){d2=ss->next->element;i++;}
		else if(i==2){d3=ss->next->element;i++;}
		else if(i==3){d4=ss->next->element;
			d=d4*1000+d3*100+d2*10+d1;
			insert(r,d);i=0;d1=0;d2=0;d3=0;d4=0;
		}ss=ss->next;}
	if(i==1){d=d1;insert(r,d);}
	else if(i==2){d=10*d2+d1;insert(r,d);}
	else if(i==3){d=100*d3+d2*10+d1;insert(r,d);}
	i=0;
	while((c=getchar())!='\n'){
		d=(int)c-'0';insert(tt,d);}
		while(tt->next!=NULL){
		if(i==0){d1=tt->next->element;i++;}
		else if(i==1){d2=tt->next->element;i++;}
		else if(i==2){d3=tt->next->element;i++;}
		else if(i==3){d4=tt->next->element;
			d=d4*1000+d3*100+d2*10+d1;
			insert(z,d);i=0;d1=0;d2=0;d3=0;d4=0;}
		tt=tt->next;}
	if(i==1){d=d1;insert(z,d);}
	else if(i==2){d=d2*10+d1;insert(z,d);}
	else if(i==3){d=d3*100+d2*10+d1;insert(z,d);}
	while(r->next!=NULL){insert(s,r->next->element);r=r->next;}
	while(z->next!=NULL){insert(t,z->next->element);z=z->next;}
	/*ここまで*/
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
	}//printlist(s);printlist(t);
	/*通常の処理*/
	if(flag==0){printf("%d\n",flag);}
	else{
	while(s->next!=NULL){min(t,s,k);/*printlist(k);*/s=s->next;k=k->next;/*printlist(k);*/}
	k=m;
	while(k->next!=NULL){insert(l,k->next->element);k=k->next;}
	printlist(l);
	}
}