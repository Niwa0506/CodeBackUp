#include <stdio.h>
#include <stdlib.h>

typedef char elementtype;

struct node {
  elementtype element;
  struct node *next;
};

struct node *initlist(void){
  struct node *n;

  n = (struct node *)malloc(sizeof(struct node));
  n->next = NULL;
  return n;
}

void insert(struct node *p, elementtype x){
  struct node *n;

  n = (struct node *)malloc(sizeof(struct node));
  n->element = x;
  n->next = p->next;
  p->next = n;
}

void delete(struct node *p){
  if(p->next != NULL){
    p->next = p->next->next;
  }
}

void printlist(struct node *l){
  l = l->next; /* skip a head */
  while(l != NULL){
    printf("%c ", l->element);
    l = l->next;
  }
  printf("\n");
}

typedef struct node * stack;

void initstack(stack *s){
  *s = initlist();
}

int stackempty(stack s){
  return s->next == NULL;
}

void push(stack s, elementtype x){
  insert(s, x);
}

elementtype pop(stack s){
  elementtype work;

  if(stackempty(s)){
    printf("underflow\n");
    exit(1);
  }else{
    work = s->next->element;
    delete(s);
    return work;
  }
}

int search(stack p,elementtype x){
  while(p->next != NULL){
    p = p->next;
    if(p->element == x){
      return 1;
    }
  }
  return 0;
}

int main(int ac,char *av[]){
  stack s;elementtype k;
  k = *av[1];
  initstack(&s);

  push(s, 'A');
  push(s, 'M');
  push(s, 'U');
  push(s, 'Z');
  push(s, 'A');
  push(s, 'K');
  push(s, 'A');
  push(s, 'W');
  push(s, 'I');
  push(s, 'N');
  

  /*while(!stackempty(s)){
    printf("%c", pop(s));
  }
  printf("\n");*/
  
   if(search(s,k)){
      while(!stackempty(s)){
    printf("%c", pop(s));
  }
  printf("\n");
  
   }
   else{printf("指定された文字は存在しません。\n");}

  return 0;
}
