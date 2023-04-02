#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256

typedef struct node{
  int value;
  struct node *left;
  struct node *right;
} *Node;

typedef Node elemtype;

/* stackを構造体で表現 */
struct stack{
  int top;
  elemtype elem[BUFSIZE];
};

/* データを格納 */
void push(struct stack *s, elemtype val){
  s->top++;
  if(s->top >= BUFSIZE){
    printf("stack overflow\n");
    exit(1);
  }else{
    s->elem[s->top] = val;
  }
}

/* データを取得 */
elemtype pop(struct stack *s){
  elemtype val;
  if(s->top < 0){
    printf("stack underflow\n");
    exit(1);
  }else{
    val = s->elem[s->top];
    s->top--;
    return val;
  }
}

/* stackを初期化 */
void initstack(struct stack *s){
  s->top = -1;
}

/* stackが空なのか確認  (空ならば真(1)を返す)*/
int stackempty(struct stack *s){
  return s->top < 0;
}


int search_depth1(int key, struct stack *remain){
  struct node *target;
  while(!stackempty(remain)){
    target = pop(remain);printf("%d\n",target->value);
    if(target->value==key){
      return 1;
    }else{
      if(target->right != NULL){push(remain,target->right);} 
      if(target->left != NULL){push(remain,target->left);} 
   }
  }

  return 0;
}

int search_depth(struct node *root, int key){
  struct stack remain;

  initstack(&remain);
  push(&remain, root);

  return search_depth1(key, &remain);
}

struct node *addnode(struct node *root, int depth, int val){
  struct node *n, *new;

  new = (struct node *)malloc(sizeof(struct node));
  new->value = val;
  new->left = new->right = NULL;

  if(root == NULL){
    return new;
  }else{
    n = root;
  }

  for( ; depth > 1; depth--){
    if(n->right != NULL){
      n = n->right;
    }else if(n->left != NULL){
      n = n->left;
    }else{
      return NULL;
    }
  }

  if(n->left == NULL){
    n->left = new;
  }else if(n->right == NULL){
    n->right = new;
  }else{
    return NULL;
  }

  return root;
}

struct node *loaddata(char *filename){
  int depth, val;
  FILE *input;
  struct node *root = NULL;
  char line[BUFSIZE];

  input = fopen(filename, "r");
  if(input == NULL){
    fprintf(stderr, "Can't open file: %s\n", filename);
    exit(1);
  }

  while(fgets(line, sizeof(line), input) != NULL){
    depth = 0;
    while(line[depth] == ' '){
      depth++;
    }

    sscanf(&line[depth], "%d", &val);
    root = addnode(root, depth, val);
    if(root == NULL){
      fprintf(stderr, "illegal input file: %s\n", line);
      exit(1);
    }
  }

  fclose(input);

  return root;
}

int main(int ac, char **av){
  int result;
  struct node *root;

  if(ac != 3){
    fprintf(stderr, "Usage: %s <datafile> <key>\n", av[0]);
    exit(1);
  }

  root = loaddata(av[1]);//printf("%d %d %d %d %d %d %d %d %d\n",root->value,root->left->value,root->left->left->value,root->left->right->value,root->right->value,root->right->left->value,root->right->left->left->value,root->right->left->left->left->value,root->right->left->right->value);

  result = search_depth(root, atoi(av[2]));

  printf("Key \"%s\" is %s.\n", av[2], result == 1 ? "found" : "not found");

  return 0;
}
