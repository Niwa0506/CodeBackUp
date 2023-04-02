
#include <stdio.h>
#include <stdlib.h>

typedef char elementtype;

typedef struct _node {
    elementtype element;
    struct _node * next;
}  node;

node* initList(){
    node * n;
    n = (node*) malloc(sizeof(node));
    n->next = NULL;
    return n;
}

node* newNode(elementtype e){
    node* n = (node*)malloc(sizeof(node));
    n->element = e;
    n->next = NULL;
    return n;
}

node* buildList(char *p) {
    node * h = initList();
    node * n = h;
    while (*p) {
        n->next = newNode(*p++);
        n = n->next;
    }
    return h;
}

void freeList(node* list) {
    node *head;
    for (; list; ) {
        head = list;
        list = list->next;
        free(head);
    }
}


int findMaxRemoval(node *head){
    int n =0,i =0,j,s=0;char sum[20],k;
    while(head->next != NULL){
        if(head->element == 'A'){sum[i] = 'A';i +=1;}
        else if(head->element == 'T'){sum[i] = 'T';i+=1;}
        else if(head->element == 'C'){sum[i] = 'C';i+=1;}
        else if(head->element == 'G'){sum[i] = 'G';i+=1;}
        head = head->next;
    }
    if(head->element == 'A'){sum[i] = 'A';i +=1;}
    else if(head->element == 'T'){sum[i] = 'T';i+=1;}
    else if(head->element == 'C'){sum[i] = 'C';i+=1;}
    else if(head->element == 'G'){sum[i] = 'G';i+=1;}
    head = head->next;sum[i] = '\0';
    i = 0;
    while(sum[i+1] != '\0'){
        k = sum[i]; 
        for(j = i+1;sum[j] != '\0';j++){
            if(sum[j] == k){s+=1;}
            else{n +=s;break;}
        }
        s = 0;
    }
    printf("%s\n",sum);
   
    printf("終了\n");
    return n;
}

int main(int argc, char *argv[]){
    if (argc<2)
        exit(-1);

    node *head = buildList(argv[1]);
    //int m = 
    findMaxRemoval(head);
    //printf("%d\n",m);
    freeList(head);
    return 0;
}

