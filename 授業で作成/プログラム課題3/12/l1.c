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
/* ドットだけなら葉 (NULL) を返す */
 if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
        return NULL;
      else {
/* ドットでなければ節点を表す構造体のアドレス t を用意 */
t = (struct avl_node*)malloc(sizeof(struct avl_node));
/* 高さを t->height に，学籍番号，名前，得点を t->data に格納 */ 
sscanf(buf,"[%d]%d,%[^,],%d",&t->height,&t->data.id,t->data.name,&t->data.score); /* 左の子を t->left に，右の子を t->right に格納 */
t->left = get_avl();
t->right = get_avl();
/* t を返す */
return t;
}
}

struct avl_node* rotate_right(struct avl_node *t){
	struct avl_node *c,*l,*r;
	c=t;l=t->left;r=t->right;
	if(t==NULL||l==NULL)
		return t;
	else
		t->left=l->right;l->right=t;t->height=r->height+1;
		put_height(l);
		return l;
}

struct avl_node* rotate_left(struct avl_node *t){
	struct avl_node *c,*l,*r;
	c=t;l=t->left;r=t->right;
	if(t==NULL||r==NULL)
		return t;
	else
		t->right=r->left;r->left=t;t->height=l->height+1;
		put_height(r);
		return r;

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
	struct avl_node *t;
	char c;
	scanf("%c ",&c);
	t=get_avl();
	if(c=='R')
		t=rotate_right(t);
	else if(c=='L')
		t=rotate_left(t);
	print_avl(t);
	return 0;
}