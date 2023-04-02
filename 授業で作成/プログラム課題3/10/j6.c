#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 101
struct student {int id;char name[32];int score;};
struct node {struct student data;struct node*next;};
int hash(char *s){
	int i,c,S;
	S=(int)s[0]%SIZE;
	for(i=1;i<32;i++){
		c=(int)s[i];
		S=(S*128+c)%101;
	}
	return S;
}
int ch(struct node *table[],struct student st){
	int h =hash(st.name);
	struct node *search = table[h];
	while(search!=NULL){
		if(strcmp(search->data.name,st.name)==0){
			return 1;
		}
		search = search->next;
	}
	return 0;
}
void set_data(struct node *table[],struct student st){
	struct node *check,*new;int h = hash(st.name),i;
	new =(struct node *)malloc(sizeof(struct node));
	new->data = st;
	new ->next = NULL;
	if(table[h]==NULL){
		table[h]=new;}
	else{i=ch(table,st);
		if(i==1){
			check=table[h];
			while(strcmp(check->data.name,new->data.name)!=0){
				check=check->next;
			}
			check->data.score+=new->data.score;
		}
		else{
		check = table[h];
		while(check->next!=NULL)
			check = check->next;
		check->next =new;}
	}
}

int main(){
	int i;
	char buf[128];
	struct student st;
	struct node *table[SIZE],*p,*desk[SIZE];
	for(i=0;i<SIZE;i++)table[i]=NULL;
	while(fgets(buf,sizeof(buf),stdin)!=NULL){
	sscanf(buf,"%[^,],%d",st.name,&st.score);
	set_data(table,st);
	}
	for(i=0;i<SIZE;i++){
		p = table[i];
		while(p!=NULL){
			st = p->data;
			printf("%s,%d\n",st.name,st.score);
			p=p->next;
		}
	}
	return 0;
}