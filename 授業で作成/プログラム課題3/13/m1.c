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

int main() {
 struct rb_node *t;
 char c;
 scanf("%c ",&c);
 t = get_rbtree();
 if(c=='R') t = rotate_right(t);
 else if(c=='L') t = rotate_left(t); /* L なら左回転 */
 print_rbtree(t);
 return 0;
 }
