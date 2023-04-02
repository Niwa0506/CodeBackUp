#include <stdio.h>
#include <stdlib.h>

struct student {int id;char name[32];int score;};
typedef struct student datatype;
struct node {datatype data;struct node *left,*right;};

void bst_insert(struct node *t,struct student d){
	t->left->data=d;
	int j=0;
	struct node *s = t->right,*k,*n;
	n = (struct node *)malloc(sizeof(struct node));
	n->data=d;
	n->left=n->right = t->left;
	if(t->right==t->left){t->right=n;}
	else{
		while(1){
			//printf("%d %d\n",s->data.id,t->left->data.id);
			if(s->data.id>d.id){k=s;s=s->left;j=1;}
			else if(s->data.id<d.id){k=s;s=s->right;j=0;}
			else {break;}
		}
		if(j==1){k->left=n;}
		else{k->right=n;}
	}
}

void print_bst_dummy(struct node *t,struct node *dummy){
	if(t==dummy)
		printf(".\n");
	else{
		printf("%d,%s,%d\n",t->data.id,t->data.name,t->data.score);
		print_bst_dummy(t->left,dummy);
		print_bst_dummy(t->right,dummy);
	}
	return ;
}

void print_bst(struct node *t){
	print_bst_dummy(t->right,t->left);
	return ;
}

int main(){
	char buf[128];
	struct node *t  = (struct node *)malloc(sizeof(struct node)),
				*dummy = (struct node *)malloc(sizeof(struct node));
	struct student st ;
	t->left=t->right = dummy->left = dummy->right = dummy;
	while(fgets(buf,sizeof(buf),stdin)!=NULL){
		sscanf(buf,"%d,%[^,],%d",&st.id,st.name,&st.score);
		bst_insert(t,st);
	}
	print_bst(t);
	return 0;
}