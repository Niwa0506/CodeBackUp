 #include <stdio.h>
 #include <stdlib.h>
 
int count=0,xray=0;
char kijun;
struct point {int x,y;};
typedef struct point elementtype;
struct node {elementtype element;struct node *next;};
typedef struct node* list;
int compare(struct point p1,struct point p2){
	++count;
	int judge=0,element1,element2,sub1,sub2,sub3,sub4;
	if(kijun=='X'){element1=p1.x;element2=p2.x;sub1=p1.y;sub2=p2.y;}
	else if(kijun=='Y'){element1=p1.y;element2=p2.y;sub1=p1.x;sub2=p2.x;}
	else if(kijun=='D'){element1=p1.x*p1.x+p1.y*p1.y;element2=p2.x*p2.x+p2.y*p2.y;
					sub1=p1.x;sub2=p2.x;sub3=p1.y;sub4=p2.y;}
	if(element1 > element2){judge=1;}
	else if(element1 < element2){judge=-1;}
	else{if(sub1 > sub2){judge=1;}
		 else if(sub1 < sub2){judge=-1;}
		 else if(sub1==sub2&&kijun=='D'){
		 	if(sub3>sub4){judge=1;}
		 	else if(sub3<sub4){judge=-1;}
		 }}
		return judge;
}

void split(list l1,list l2){
	list l3,l4;struct point p;
	l3=l4=l1;
	while(l4->next!=NULL){
		l4=l4->next;
		if(l4->next!=NULL){l4=l4->next;}l3=l3->next;
	} 
	//printf("ここまではOK\n");
	l2->next=l3->next;
	l3->next=NULL;
}

void merge(list l1,list l2){
	list last,s=l1,start;int flag=1;struct point p;
	last= (list)malloc(sizeof(struct node));
	last->next=NULL;
	s=l1->next;
	while(s->next!=NULL){s=s->next;}
	s->next=last;start=last;
	while(l2->next!=NULL){
		if(start==l1->next){flag=0;}
		if(flag==1){
			//printf("0K\n");
			if(compare(l1->next->element,l2->next->element)==1){last->next=l2->next;l2->next=l2->next->next;last->next->next=NULL;}
			else{last->next=l1->next;l1->next=l1->next->next;last->next->next=NULL;}
		}else{last->next=l2->next;l2->next=l2->next->next;last->next->next=NULL;}
		last=last->next;//printf("ループは0K\n");
		//printf("%d %d\n",last->element.x,last->element.y);
	}
	//printf("%d %d\n",start->next->element.x,start->next->element.y);
	while(l1->next!=start){
		last->next=l1->next;
		l1->next=l1->next->next;
		last=last->next;last->next=NULL;
	}
	//printf("0K\n");
	l1->next=l1->next->next;
	//printf("0K\n");
	/*while((start=start->next)!=NULL){
		p=start->element;
		printf("解答3:%d %d\n",p.x,p.y);}*/
}

void merge_sort(list l){
	list l1=l,l2,l3,l4,l5;struct point p;int flag1=0,flag2=0,n=0;
	l2=(list)malloc(sizeof(struct node));l2->next = NULL;

	if(l->next->next!=NULL){xray++;
		//printf("%d\n",xray);
		split(l,l2);
		l3=l;l4=l2;
		/*while((l3=l3->next)!=NULL){
		p=l3->element;flag1=1;n++;
		printf("解答1:%d %d %d\n",p.x,p.y,n);}*/
		//printf("%d\n",n);
		//printf("\n");
		n=0;
		/*while((l4=l4->next)!=NULL){
		p=l4->element;flag2=1;n++;
		printf("解答2:%d %d %d\n",p.x,p.y,n);}*/
		l5=l;
		//printf("%d\n",n);
		//printf("\n");
		merge_sort(l);merge_sort(l2);
		merge(l,l2);

		/*while((l5=l5->next)!=NULL){
		p=l5->element;
		printf("それは%d %d\n",p.x,p.y);
		}*/
	}
}

int main(){
	char buf[128];
	struct point p;
	list l,last;
	scanf("%c ",&kijun);
	last = l = (list)malloc(sizeof(struct node));
	while(fgets(buf,sizeof(buf),stdin)!=NULL){
		sscanf(buf,"%d %d",&p.x,&p.y);
		last = last->next=(list)malloc(sizeof(struct node));
		last->element= p;
	}
	last->next = NULL;
	merge_sort(l);
	list l2;
	l2=(list)malloc(sizeof(struct node));l2->next = NULL;
	printf("%d\n",count);
	while((l=l->next)!=NULL){
		p=l->element;
		printf("%d %d\n",p.x,p.y);
	}
	return 0;
}