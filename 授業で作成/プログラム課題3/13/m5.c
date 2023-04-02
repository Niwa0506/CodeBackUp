#include <stdio.h>
#include <stdlib.h>

char buf[128];

struct student {int id;char name[32];int score;};
typedef struct student datatype;
struct rb_node{datatype data;struct rb_node *left,*right;int black;};

struct rb_node*get_rbtree(){
	struct rb_node *t;
	char c;
	/* ドットだけなら葉 (NULL) を返す */ 
	if(fgets(buf,sizeof(buf),stdin)==NULL || buf[0]=='.')
    	return NULL;
    else{
		/* ドットでなければ節点を表す構造体のアドレス t を用意 */
		t = (struct rb_node*)malloc(sizeof(struct rb_node));
		/* 色を表す文字を c に，学籍番号，名前，得点を t->data に格納 */ 
		sscanf(buf,"[%c]%d,%[^,],%d",&c,&t->data.id,t->data.name,&t->data.score); /* 色の文字が b なら 1，r なら 0 */
		t->black = (c=='b');
		/* 左の子を t->left に，右の子を t->right に格納 */
		t->left = get_rbtree(); t->right = get_rbtree();
		/* t を返す */
		return t;
	}
}

int is_red(struct rb_node *t) {
      return (t != NULL && !t->black);
}

struct rb_node *rotate_right(struct rb_node *t){
struct rb_node *c,*l,*r;
	c=t;
	if(t==NULL)
		return t;
	else{
		l=t->left;r=t->right;
		if(l==NULL)
			return t;
		else{
		t->left=l->right;l->right=t;
		return l;}
	}
}

struct rb_node *rotate_left(struct rb_node *t){
struct rb_node *c,*l,*r;
	c=t;
	if(t==NULL){
		return t;}
	else{
		l=t->left;r=t->right;
		if(r==NULL)
			return t;
		else{
		t->right=r->left;r->left=t;
		return r;
		}
	}
}
void print_rbtree(struct rb_node*t){
 if(t==NULL) printf(".\n");
      else {
printf("[%c]%d,%s,%d\n",t->black?'b':'r',t->data.id,t->data.name,t->data.score);
        print_rbtree(t->left); print_rbtree(t->right);
      }
}

struct rb_node *resolve_red_pair(struct rb_node *t){
	struct rb_node *s;
		if(is_red(t->left)){
			if(is_red(t->left->left)){//printf("0K4\n");
				if(!is_red(t->right)){
					t=rotate_right(t);}
				if(is_red(t)){t->black=1;t->left->black=0;t->right->black=0;}
				else{t->black=0;t->left->black=1;t->right->black=1;}
			}
			else if(is_red(t->left->right)){//printf("0K3\n");
				if(!is_red(t->right)){t->left=rotate_left(t->left);t = rotate_right(t);}
				if(is_red(t)){t->black=1;t->left->black=0;t->right->black=0;}
				else{t->black=0;t->left->black=1;t->right->black=1;}
			}
		}
		if(is_red(t->right)){
			if(is_red(t->right->left)){//printf("0K2\n");
				if(!is_red(t->left)){
					t->right=rotate_right(t->right);
					t=rotate_left(t);}
				if(is_red(t)){t->black=1;t->left->black=0;t->right->black=0;}
				else{t->black=0;t->left->black=1;t->right->black=1;}
			}
			else if(is_red(t->right->right)){//printf("0K1\n");
				if(!is_red(t->left)){
					t=rotate_left(t);}
				if(is_red(t)){
					t->black=1;t->left->black=0;t->right->black=0;}
				else{t->black=0;t->left->black=1;t->right->black=1;}
			}
		}
		//printf("0K5\n");
	return t;
}

struct rb_node *rb_insert_rec(struct rb_node *t,struct student d){
	if(t==NULL){
		struct rb_node *s = (struct rb_node *)malloc(sizeof(struct rb_node));
		s->data = d;t=s;s->left=s->right=NULL;s->black=0;
		return s;
	}
	else{
		if(t->data.id>d.id){
			t->left=rb_insert_rec(t->left,d);t=resolve_red_pair(t);}
		else if(t->data.id<d.id){
			t->right=rb_insert_rec(t->right,d);t=resolve_red_pair(t);
		}else{
			t->data.score+=d.score;
		}
		return t;
	}
}
struct rb_node* rb_update(struct rb_node *t, struct student d) {
  t = rb_insert_rec(t, d);
  t->black = 1;
  return t;
}
int main() {
 struct student d;
 struct rb_node *t=NULL;
 while(fgets(buf,sizeof(buf),stdin)!=NULL){
 	sscanf(buf,"%d,%[^,],%d",&d.id,d.name,&d.score);
 	t= rb_update(t,d);//print_rbtree(t);printf("----\n");
 }
 print_rbtree(t);
 return 0;
 }
