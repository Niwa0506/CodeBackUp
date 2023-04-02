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
    n->element = x;
    for(;p->next != NULL;){
        p = p->next;
    }
    p->next =n;

}

void printlist(struct node *p) {
    if(p->next == NULL) {
        putchar('\n');
    }else {
        p = p->next;
        putchar(p->element);
        printlist(p);
        putchar(p->element);
    }
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

    printlist(list);
    printf("\n");
    for (; list; ) {
        head = list;
        list = list->next;
        free(head);
    }
    return 0;
}


