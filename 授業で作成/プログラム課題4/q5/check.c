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
    l =(list)malloc(sizeof(struct node));
    l->next = NULL;
    return l;
}

position first(list l) {
    return l;
}

position next(list l, position p) {
    l= p;position w;
    w = l->next;
    return w;
}

position end(list l) {
    position p;
    while(l->next != NULL){
        l->next = l->next->next;
    }
    p = l->next;
    return p;
}

elementtype retrieve(list l, position p) {
    l = p;list q;
    q = malloc(sizeof(list));
    q = l;
    return q->element;
}

int judge(char a[],char b[]){
    int n= 0,i;
    for( i=0;a[i] == b[i];i++){
        }
    if(a[i]> b[i]){n= 1;}
    return n;
}

position find(list l, elementtype e) {
    list p;
    p = initlist();
    position q;
    p ->next= l->next;
    //q = l->next;
    while(p->next != NULL){
        if(judge(e,p->next->element)){//printf("%s\n",p->next->element);
         p->next= p->next->next;//printf("%s\n",l->next->element);
        }else{break;}
    }
    q = p->next;
    //l->next=q;
    return q;
}


void printlist(list l) {
    position p;
    p = next(l,l);
    //int n=0;
        //printf("これは");printf("%s",l->next->element);printf("check\n");//}
    while (p) {
        //printf("%d\n",n);
        printf("%s\n", retrieve(l,p));
        p = next(l,p);//n +=1;
    }
}
void insert(list l, position p, elementtype e) {
    list n;char a[MAXLENGTH+2];int i;position q;
    n = initlist();
    n->element = malloc(sizeof(elementtype)*sizeof(a));
    //n->next = malloc(sizeof(position));
    while(l->next != p){
        l = l->next;
    }
    //要素の代入
    for( i = 0;i < strlen(e)-1;i++){
    a[i] = e[i]; //printf("%c %s\n",a[i],e);
    }a[i] = '\0';//e = "TAKUMA";
        strcpy(n->element,a);
         n->next = l->next;l->next = n;
    //printf("%s\n",l->next->element);
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
    position p,q;
    university = initlist();
    while(1) {char buf[MAXLENGTH+2];//printf("%s\n",university->next->element);
        fgets(buf, sizeof(buf), stdin);
        if(buf[0] == '.') {//printf("%s\n",university->next->element);
        break;}
        p = find(university,buf);//printf("Ok\n");
       insert(university,p,buf);//break;//printf("途中経過%s %s\n",university->next->element,buf);
       //printlist(university);
       //printf("途中経過%s\n",university->next->element);
    }
    //printf("%s\n",university->next->element);
    //printf("%s\n",university->next->next->element);
    printlist(university);
    //freeList(university);
    return 0;
}


