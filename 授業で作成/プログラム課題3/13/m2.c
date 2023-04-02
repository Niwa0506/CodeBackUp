#include <stdio.h>
#include <stdlib.h>

char buf[128];

struct student {int id;char name[32];int score;};
typedef struct student datatype;
struct rb_node{datatype data;struct rb_node *left,*right;int black;};
int judge=0;
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
//条件1 葉は必ず黒
//条件 2 赤の節点の子は必ず黒 (黒の節点の子は赤でも黒でもよい)
//条件 3 根から葉にたどり着くまでに通る黒い節点の数がすべて同じ

int is_rbtree(struct rb_node *t){
	if(t==NULL)
		return 1;
	else{
		judge+=1;int flag=0;
		if(is_red(t)){
			if(!is_red(t->left)&&!is_red(t->right)){
				flag=1;
			}
		}
		else{flag=1;}

		if(flag==1){
			int number1=is_rbtree(t->left),number2=is_rbtree(t->right);
			if(judge==1){
				if(number1==number2)
					return 1;
				else
					return 0;
			}
			else{
				if(number1==number2){
					if(!is_red(t) &&number1!=0&&number2!=0)
						return number1+1;
					else if(number1!=0&&number2!=0)
						return number1;
					else 
						return 0;
				}
				else 
					return 0;
			
			}
		}
		else
			return 0;
	}
}

int main() {
 struct rb_node *t= get_rbtree();
 if(is_rbtree(t))	printf("YES.\n");
 else				printf("NO.\n");
 return 0;
 }
