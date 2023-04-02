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
    for(;p->next != NULL;){
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

void halfchange(struct node *p) {

    struct node *n;int k,i;struct node *s;struct node *l;struct node *j;struct node *q;struct node *g;
    n =(struct node*)malloc(sizeof(struct node));
    s =(struct node*)malloc(sizeof(struct node));
    g =(struct node*)malloc(sizeof(struct node));
    j = p;
    for( i =1;p != NULL;i++){
        insert(n,p->element);
        insert(s,p->element);//printf("%c\n",p->element);
        insert(g,p->element);
        p= p->next;
    }
    k = i;i = 1;
    n = n->next;s = s->next;g = g->next;//printlist(g);
    while(i <k/2){
        n->next = n->next->next;
        i +=1;
    }
    l = s;
    while(n->next != NULL){
        s->next->element = n->next->element;
        s = s->next;n = n->next;
    }
    while(s->next != NULL){
        s->next->element = g->next->element;
        s = s->next;g = g->next;
    }
    p = j;
    p->next = l->next;

}

int main(int argc, char *argv[]) {
    struct node *list, *head;
    char *p;

    if (argc<2)
        exit(-1);

    list = initlist();
    p = argv[1];
    for (; *p; p++) {
        insert(list, *p);
    }

    halfchange(list);
    printlist(list);

    for (; list; ) {
        head = list;
        list = list->next;
        free(head);
    }
    return 0;
}


