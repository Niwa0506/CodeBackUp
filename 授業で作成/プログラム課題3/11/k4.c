#include <stdio.h>
#include <stdlib.h>

char buf[128];

struct student {int id;char name[32];int score;};
typedef struct student datatype;
struct node {datatype data;struct node *left,*right;};

struct node *get_tree(){
	struct node *t;
	if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
		return NULL;
	else{
		t=(struct node *)malloc(sizeof(struct node));
		sscanf(buf,"%d,%[^,],%d",&t->data.id,t->data.name,&t->data.score);
		t->left = get_tree();
		t->right = get_tree();
		return t;
	}
}

void find_info(struct node *t,int id){
while(t!=NULL){
	if(t->data.id==id){
		break;
	}else if(t->data.id > id){
		t=t->left;
	}
	else{t=t->right;}
	}
	if(t==NULL)printf("Not found.\n");
	else printf("%s,%d\n",t->data.name,t->data.score);
}

int main(){
	int id;
	struct node *t = get_tree();
	scanf("%d ", &id);
	find_info(t,id);
	return 0;
}
