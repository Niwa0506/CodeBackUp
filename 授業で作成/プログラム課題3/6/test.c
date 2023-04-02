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
	while(t->next!=NULL){
		printf("%d",t->next->element);
		t=t->next;
	}
	printf("\n");
}
void insert(list s,int d){
	list n;
	n = (list)malloc(sizeof(list));
	n->element = d;
	n->next = s->next;
	s->next = n;
}
void addlist(list h,list i){
	int n=0,next1=0;list l=h,k=i,q=h;
	while(l->next!=NULL&&k->next!=NULL){
	int s=l->next->element,d=k->next->element;
	//printf("%d %d\n",l->next->element,next);
	if(s+d+next1>=10){l->next->element=s+d+next1-10;next1=1;}
	else{l->next->element=s+d+next1;next1=0;}
	l=l->next;k=k->next;
	}
	if(k->next!=NULL){insert(l,k->next->element);}
	if(next1!=0){insert(l,1);}
}

void min2(list l,list k,list w){
	printf("lの経過");printlist(w);

	list h=l,t=k,e,j,i,r,z,a;i=w;int n=0,m=0,d=t->next->element;
	j=(list)malloc(sizeof(list));j->next=NULL;
	a=(list)malloc(sizeof(list));a->next=NULL;
	r=(list)malloc(sizeof(list));r->next=NULL;
	e=(list)malloc(sizeof(list));e->next=NULL;
	z=j;
	/*代入*/
	while(h->next!=NULL){
		int s=h->next->element;
		if(s*d+next>=10){insert(j,(s*d+next)%10);next=(next+s*d)/10;}
		else{insert(j,s*d+next);next=0;}
		h=h->next;
	}
	if(next!=0){insert(j,next);next=0;}
	printf("jは");printlist(j);
	/*ここまで*/
	while(j->next!=NULL){
		insert(a,j->next->element);
		j=j->next;
	}
	/*zを逆転*/
		while(i->next!=NULL){
			printf("通過\n");
			insert(e,i->next->element);
			i=i->next;
		}
	printf("e");printlist(e);z=e;
	while(a->next!=NULL){
		printlist(e);printlist(a);
		if(e->next==NULL){insert(e,a->next->element);}
		else{
		addlist(e,a);printf("結果は");printlist(e);break;
		}//printf("結果は");printlist(e);
		a=a->next;e=e->next;
	}
	printf("結果は");printlist(e);
	printf("z=");printlist(z);
	z=z->next;
	//w->next=z->next;610856
	w->next=NULL;
	w->next=z->next;
	/*while(z->next!=NULL){
	insert(w,z->next->element);
	z=z->next;
	}*/
	printlist(w);
	printf("answer=");printlist(w);
}

int main(){
	int d,q=0,p=0;list s,t,k,l,e,z,west,m;
	char c;
	s=(list)malloc(sizeof(list));
	t=(list)malloc(sizeof(list));
	k=(list)malloc(sizeof(list));
	z=(list)malloc(sizeof(list));
	m=(list)malloc(sizeof(list));
	s->next=NULL;t->next=NULL;k->next=NULL;z->next=NULL;m->next=NULL;
	west=k;
	while((c=getchar())!='\n'){
		d=(int)c-'0';
		insert(s,d);
		p++;
	}
	while((c=getchar())!='\n'){
		d=(int)c-'0';
		insert(t,d);
		q++;
	}
	if(p<q){
		while(s->next!=NULL){
			min2(t,s,k);
			printf("途中経過");printlist(west);
			s=s->next;
			if(k->next!=NULL){k=k->next;}
		}
		printlist(l);
	}else{
		while(t->next!=NULL){
			min2(s,t,k);
			printf("途中経過");printlist(west);
			t=t->next;
			if(k->next!=NULL){k=k->next;}	
		}
		e=z;
		while(l->next!=NULL){
			insert(z,l->next->element);
			l=l->next;
			printf("途中経過");printlist(west);
			if(k->next!=NULL){k=k->next;}
		}
		//printf("answer");
		//printlist(e);
	}
}