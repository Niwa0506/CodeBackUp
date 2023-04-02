#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct node { double data; struct node *next; };

typedef struct node *nodep;
	nodep node_new(double d, nodep n) {
	nodep p = (nodep)malloc(sizeof(struct node)); 
	p->data = d; p->next = n; 
	return p;
}
nodep mklist(int n, char *a[]) {
	if(n == 0) { return NULL; }
	return node_new(atof(*a), mklist(n-1, a+1)); }
//OK
void plist(nodep p) {
	if(p == NULL) { 
		printf("\n"); return; 
	} printf(" %g", p->data); 
	plist(p->next);
}
//OK
void nconc(nodep p, nodep q) {
	while(p != NULL && p->next != NULL) { 
		p = p->next; 
	} if(p != NULL) { 
		p->next = q; }
}

nodep reverse(nodep p){
	while(p != NULL && p->next != NULL){
		p = p->next;
	}
	return node_new(p->next->data,reverse(p));
}

void right(nodep p){
	nodep q =p;int s = p->data,k = p->next->data,n = 0;
	while(p !=NULL){
		if(p->next == NULL){q->data = k;break;}
		p->next->data = s;
		s= k;
		 if(p->next->next != NULL){k = p->next->next->data;printf("%d\n",k);}
		p = p->next;n+=1;
	}

}


void delnode(nodep p, int n) {
	while(--n > 0 && p != NULL) { 
		p = p->next; 
	}
	if(p != NULL && p->next != NULL) { 
		p->next = p->next->next; 
	}
}

nodep addlist(nodep x, nodep y) {
	if(x == NULL) { return y; }
	if(y == NULL) { return x; }
	return node_new(x->data+y->data, addlist(x->next, y->next));
}

nodep productlist(nodep x,nodep y){
	if(x == NULL){return y;}
	if(y == NULL){return x;}
	return node_new(x->data*y->data,productlist(x->next,y->next));
}
//OK
bool getl(char s[], int lim) {
	int c, i = 0;
	for(c = getchar(); c != EOF && c != '\n'; c = getchar()) {
		s[i++] = c; if(i+1 >= lim) { break; } 
	}
	s[i] = '\0'; return c != EOF; 
}
//OK
int parse(char *a[], char *s) { 
	int i, k = 0, len = strlen(s); 
	for(i = 0; i < len; ++i) {
		if(s[i] == ' ') { s[i] = '\0'; }
		if(s[i] != '\0' && (i == 0 || s[i-1] == '\0')) {
		 a[k++] = s+i; 
		} 
	}
	return k; 
}
int main(int argc, char *argv[]) {
	char buf[200], *cmd[20]; nodep list = NULL; 
	while(true) {
	printf("> "); 
	if(!getl(buf, 200)) { break; } 
	int k = parse(cmd, buf);
	if(k > 0 && strcmp(cmd[0], "q") == 0) {
		break;
	} else if(k > 0 && strcmp(cmd[0], "e") == 0) { // enter list
		list = mklist(k-1, cmd+1);
	} else if(k > 0 && strcmp(cmd[0], "a") == 0) { // append list
			nconc(list, mklist(k-1, cmd+1));

	} else if(k > 1 && strcmp(cmd[0], "add") == 0){ // add list
		list = addlist(list, mklist(k-1, cmd+1));
	} else if(k > 1 && strcmp(cmd[0], "d") == 0) { // delete item
		delnode(list, atoi(cmd[1]));
	} else if(k > 1 && strcmp(cmd[0],"pro") == 0){
		list = productlist(list,mklist(k-1,cmd+1));
	} else if(k > 1 && strcmp(cmd[0],"rev") == 0){
		list = reverse(list);
	} else if(k > 0 && strcmp(cmd[0],"right") == 0) {
		right(list);
	} else{
    plist(list);
}
	}
return 0; 
}
