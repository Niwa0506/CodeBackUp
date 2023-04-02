#include <stdio.h>
#include <stdlib.h>
struct node { double data; struct node *next; };
typedef struct node *nodep;
nodep node_new(double d, nodep n) {
 nodep p = (nodep)malloc(sizeof(struct node));
 p->data = d; p->next = n; 
 return p;
}
void plist(nodep p) {
 while(p != NULL) { 
 	printf(" %g", p->data); 
 	p = p->next; 
 }
 printf("\n");
  }
nodep mklist(int n, char *a[]) {
nodep p = NULL;
	for(int i = n-1; i >= 0; --i) { 
		p = node_new(atof(a[i]), p); 
	} 
	return p;
}
int main(int argc, char *argv[]) {
	nodep p = mklist(argc-1, argv+1); 
	plist(p); 
	p->next->next = p->next->next->next; 
	plist(p); 
	p->next->next = node_new(1.0, p->next->next); 
	plist(p); 
	return 0;
}