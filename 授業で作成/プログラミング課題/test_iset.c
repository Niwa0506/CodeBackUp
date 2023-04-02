#include <stdbool.h>
#include <stdio.h>
#include "iset.h"


void expect_iset(isetp s, int m, int n, int a[], char *msg) { 
	bool ok = true; int p = 0;
	for(int i = 0; i <= n; ++i) {
		if(p < n && i == a[p]) { ++p;
			if(!iset_isin(s, i)) { printf(" NG: %d not in set.\n", i); ok = false;} 
		}else{
			if(iset_isin(s, i)) { printf(" NG: %d in set.\n", i); ok = false; 
			}
		}
	}
	printf("%s %s\n", ok?"OK":"NG", msg); 
}

int main(void) {
int a[] = { 1, 3, 5, 7 },b[]= {7,5};
isetp s = iset_new();
iset_addelt(s, 1); iset_addelt(s, 3); iset_addelt(s, 5); 
expect_iset(s, 9, 3, a, "initial: { 1 3 5 }"); 
//iset_subelt(s, 1); 
//expect_iset(s, 9, 2, a+1, "- { 1 }: { 3 5 }");
isetp q = iset_new(); iset_addelt(q, 7); iset_addelt(q, 5);
expect_iset(q,9,2,b,"initial: { 7 5 }");
isetp r = iset_int(s, q);
expect_iset(r, 9, 1, b+1, "+ { 5 }: { 5 }");
iset_free(s); iset_free(q); iset_free(r);
return 0;
}