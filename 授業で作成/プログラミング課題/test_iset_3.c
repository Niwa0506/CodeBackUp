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
int a[] = { 1, 3, 5, 7 },b[]= {2,4,6,8},c[]={1,2,3,4,5,6,7,8};
isetp s = iset_new();
iset_addelt(s, 1); iset_addelt(s, 3); iset_addelt(s, 5); iset_addelt(s,7);
expect_iset(s, 9, 3, a, "initial: { 1 3 5 }"); 
isetp q = iset_new(); iset_addelt(q,2);iset_addelt(q,4); 
					  iset_addelt(q,6);iset_addelt(q,8);
expect_iset(q,9,4,b,"initial: { 2 4 6 8 }");
isetp r = iset_ex(s, q);
expect_iset(r, 9, 8, c, "+ { 1 2 3 4 5 6 7 8 }: { 1 2 3 4 5 6 7 8 }");
iset_free(s); iset_free(q); iset_free(r);
return 0;
} 