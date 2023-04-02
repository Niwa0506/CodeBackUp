#include <stdio.h>
#include <stdlib.h>

char buf[128];

struct student {int id;char name[32];int score;};
typedef struct student datatype;
struct avl_node{datatype data;struct avl_node *left,*right;int height;};
int height(struct avl_node *t){
	if(t==NULL)
		return 0;
	else
		return t->height;
}
void put_height(struct avl_node *t){
	if(t->right!=NULL&&t->left!=NULL){
			if(height(t->right)>height(t->left))
				t->height=height(t->right)+1;
			else
				t->height=height(t->left)+1;}
		else if(t->left==NULL)
			t->height=height(t->right)+1;
		else
			t->height=height(t->left)+1;
}

struct avl_node *get_avl(){
	struct avl_node *t;
 	if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
        return NULL;
    else {
		t = (struct avl_node*)malloc(sizeof(struct avl_node));
		sscanf(buf,"[%d]%d,%[^,],%d",&t->height,&t->data.id,t->data.name,&t->data.score); /* 左の子を t->left に，右の子を t->right に格納 */
		t->left = get_avl();
		t->right = get_avl();
		return t;
	}
}

struct avl_node* rotate_right(struct avl_node *t){
	struct avl_node *c,*l,*r;
	c=t;
	if(t==NULL)
		return t;
	else{
		l=t->left;r=t->right;
		if(l==NULL)
			return t;
		else{
		t->left=l->right;l->right=t;put_height(t);
		//put_height(l);
		return l;}
	}
}

struct avl_node* rotate_left(struct avl_node *t){
	struct avl_node *c,*l,*r;
	c=t;
	if(t==NULL){
		return t;}
	else{
		l=t->left;r=t->right;
		if(r==NULL)
			return t;
		else{
		t->right=r->left;r->left=t;put_height(t);
		//put_height(r);
		return r;
		}
	}
}

struct avl_node *balance(struct avl_node *t){
	struct avl_node *r=t->right,*l=t->left;
	int rh = height(r),lh=height(l);
	if(rh-lh==2){
		if(height(r->right)>=height(r->left)){
			t=rotate_left(t);}
		else{
			r=rotate_right(r);
			t->right=r;
			t=rotate_left(t);
		}
	}
	else if(lh-rh==2){
		if(height(l->left)>=height(l->right)){
			t=rotate_right(t);}
		else{
			l=rotate_left(l);
			t->left=l;
			t=rotate_right(t);
		}
	}
		return t;
}

void print_avl(struct avl_node *t){
	if(t==NULL)
		printf(".\n");
	else{
		printf("[%d]%d,%s,%d\n",t->height,t->data.id,t->data.name,t->data.score);
		print_avl(t->left);
		print_avl(t->right);
	}
}

int main(){
	struct avl_node *t=get_avl();
	t = balance(t);
	print_avl(t);
	return 0;
}