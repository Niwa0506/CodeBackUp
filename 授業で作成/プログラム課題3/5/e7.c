#include <stdio.h>
#include <stdlib.h>
typedef int elementtype;
struct dlnode {
	elementtype element;
	struct dlnode *prev,*next;
};
void insert(struct dlnode *p,elementtype e){
	struct dlnode *s;
	s = (struct dlnode*)malloc(sizeof(struct dlnode));
	s->element=e;
	s->next=p;
	p->prev->next=s;
	s->prev=p->prev;
	p->prev = s;
	//printf("%d %d %d\n",p->prev->element,p->prev->prev->element,p->prev->prev->prev->element);

}
void delete(struct dlnode *p){
	struct dlnode *s,*t;
	s = p->prev;t = p->next;
	s->next = t;
	t->prev = s;
	free(p);
	p = s;
}
void print_dllist(struct dlnode *p){
	struct dlnode *d1,*d2;
	d1=p->next;
	d2=p->prev;
	while(d1!=p){
		printf("[%d]",d1->element);
		d1=d1->next;
	}
	//printf("\n");
	while(d2!=p){
		printf("{%d}",d2->element);
		d2=d2->prev;
	}
	printf("\n");
}

void append_dllist(struct dlnode *d1,struct dlnode *d2){
	d2->next->prev=d1->prev;
	d1->prev->next = d2->next;
	d2->prev->next = d1;
	d1->prev =d2->prev;
	free(d2);
}

int main(){
	char buf[128];
	int i;
	struct dlnode *d1,*d2;
	d1 = (struct dlnode*)malloc(sizeof(struct dlnode));
	d2 = (struct dlnode*)malloc(sizeof(struct dlnode));
	d1->next = d1;d1->prev=d1;d2->next=d2;d2->prev=d2;
	while(fgets(buf,sizeof(buf),stdin)!=NULL){
		sscanf(buf,"%d",&i);
		insert(d1,i);
		insert(d2,i);
	}
	print_dllist(d1);
	print_dllist(d2);
	struct dlnode *s;
	s = d1->next;i=0;
	while(s!=d1||i==0){
		i=1;
		if(s->element%2!=0){//printf("1\n");
			delete(s);//printf("2\n");
		}
		s = s->next;
	}
	//printf("終了\n");
	s = d2->next;i=0;
	print_dllist(d1);//printf("終了\n");
	while(s!=d2||i==0){
		i=1;
		if(s->element%2==0){
			delete(s);
		}
		s = s->next;
	}
	print_dllist(d2);
	append_dllist(d1,d2);
	print_dllist(d1);
	return 0;
}