#include <stdio.h>
#include <stdlib.h>
struct node { double data; struct node *next; };
typedef struct node *nodep;
nodep node_new(double d, nodep n) {
 nodep p = (nodep)malloc(sizeof(struct node));
 p->data = d; p->next = n; 
 return p;
}
void plist(nodep p,int n) {
	int count =0;
 while(p != NULL) { 
 	if(count ==n){p=NULL;
 	}else{
 	printf(" %g", p->data); 
 	p = p->next;count +=1;
 	} 
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
	int n = argc-1;nodep k,s;
	nodep p = mklist(argc-1, argv+1); 
	plist(p,n); 
	k = p->next;
	s =p->next->next->next;
	p->next = p->next->next;
	p->next->next = k;
	p->next->next->next = s;
	plist(p,n); 
	p->next->next = node_new(1.0, p->next->next); 
	plist(p,n); 
	return 0;
}