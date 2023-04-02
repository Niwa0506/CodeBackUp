#include <stdio.h>
#include <stdlib.h>

struct node{
    char element;
    struct node *next;
};

struct node *initlist() {
    struct node *n;
  n = (struct node *)malloc(sizeof(struct node));
  n->next = NULL;
    return n;
}

void insert(struct node *p, char x) {
  struct node *n;
  n = (struct node *)malloc(sizeof(struct node));
    n->element = x;n->next = NULL;
    while(p->next != NULL){
        p = p->next;
    }
    p->next =n;
}

void printlist(struct node *p) {
    p = p->next;
    while (p) {
        putchar(p->element);
        p = p->next;
    }
    putchar('\n');
}

void remove_1st(struct node *p) {

    char x = p->next->element;
    struct node *n;struct node *s;
    n = (struct node *)malloc(sizeof(struct node));
    s = (struct node *)malloc(sizeof(struct node));
    s =p;
    while(p->next != NULL){
        if(p->next->element !=x){
            insert(n,p->next->element);
        }
        p ->next = p->next->next; 
    }
    p = s;
        p->next = n->next;
    

}

int main(int argc, char *argv[]) {
    struct node *list, *head;
    char *p;

    if (argc<2)
        exit(-1);

    list = initlist();
    p = argv[1];
    for (; *p; p++)
        insert(list, *p);

    remove_1st(list);
    printlist(list);

    for (; list; ) {
        head = list;
        list = list->next;
        free(head);
    }
    return 0;
}

