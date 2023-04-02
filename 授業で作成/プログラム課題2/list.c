#include <stdio.h>
#include <stdlib.h>

typedef char elementtype;

struct node {
  elementtype element;
  struct node *next;
};

struct node2 {
  elementtype  element;
  struct node2 *prev;
  struct node2 *next;
};

struct node *initlist(void){
  struct node *n;

  n = (struct node *)malloc(sizeof(struct node));
  n->next = NULL;
  return n;
}

struct node2 *initlist2(void){
  struct node2 *n;

  n = (struct node2 *)malloc(sizeof(struct node2));
  n->prev = NULL;
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

void insert2(struct node2 *p,elementtype x){
 struct node2 *n;

n = (struct node2*)malloc(sizeof(struct node2));
n->element = x;
if(p->next != NULL){p->next->prev = n;}
n->next = p->next;
p->next = n;
n->prev = p;
//11n p1np 111



}
void delete(struct node *p){
  if(p->next != NULL){
    p->next = p->next->next;
  }
}

void printlist(struct node *I){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->element = I->element;
    n->next = I->next;
  while(n->next != NULL){
    if(n->next->next == NULL){
      printf("%c\n",n->next->element);
    }else{
      printf("%c ",n->next->element);
    }
    n = n->next;
  }

}


int main(void){
  /*struct node *list;
  struct node2 *list2;
  
  list2 = initlist2();
  insert2(list2,'a');
  insert2(list2,'b');

  list = initlist();*/
 /* insert(list, 'a');
  insert(list, 'b');*/
 /*list = initlist();
insert(list, 'a');
insert(list, 'b');
printlist(list);*/
 struct node *list;
  
  list = initlist();

  insert(list, 'a');
  insert(list, 'b');
  insert(list, 'c');
  insert(list, 'd');
  insert(list, 'e');

  //delete(list->next);
  printlist(list);

  delete(list->next->next);
  printlist(list);


  //printf("%c %c\n", list2->next->element, list2->next->next->element);

  return 0;
}


