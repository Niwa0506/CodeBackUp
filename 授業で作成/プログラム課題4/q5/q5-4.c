#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 80

typedef char *elementtype;

struct node {
    elementtype element;
    struct node *next;
};

typedef struct node *link;
typedef link list;
typedef link position;


list initlist(void) {
    list l;
    l = malloc(sizeof(struct node));
    l->next = NULL;
    return l;
}

position first(list l) {
    return l;
}

position next(list l, position p) {
    while(l->next != p && l->next != NULL){
        l = l->next;
    }
    return l->next;
}

position end(list l) {
    list n;
    n = malloc(sizeof(struct node));
    n ->next= l->next;
    while(n->next != NULL){
        n= n->next;
    }
    return n->next;
}

elementtype retrieve(list l, position p) {
   while(l->next != p && l->next != NULL){
    l = l->next;
   }
   return l->element;
}

position find(list l, elementtype e) {
    list n;position p;
    n = malloc(sizeof(struct node));
    n ->next=l->next;
    while(n->next != NULL){
        if(*n->next->element < *e){
            n = n->next;
        }else{break;}
    }
    p = n;
    return p;
}

void insert(list l, position p, elementtype e) {
   n = (struct node*)malloc(sizeof(struct node));
  n->element = e;
  n->next = l->next;
  l->next = n;

}

void printlist(list l) {
    position p;
    p = next(l,l);
    while(p){
        printf("%s", (retrieve(l,p)));
        p = next(l,p);}
    }

void freeList(list l) {
    list head;
    for (; l; ) {
        head = l;
        l = l->next;
        free(head);
    }
}

int main(void) {
    list university;
    position p;

    university = initlist();
    while(1) {
        char buf[MAXLENGTH+2];
        fgets(buf, sizeof(buf), stdin);
        if(buf[0] == '.') {
            break;
        }
        p = find(university, buf);
        insert(university, p, buf);printlist(university);
    }
    printlist(university);

    freeList(university);
    return 0;
}


