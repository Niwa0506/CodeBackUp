#include <stdio.h>
#include <stdlib.h>
#include "istack.h"
void p3(istackp s, int a, int b, int c) {
	istack_push(s,c); istack_push(s,b); istack_push(s,a);
}
int combloop(int n, int r) {
	int x, ret;
	istackp v = istack_new(100);
	istackp s = istack_new(100); p3(s, 1, n, r); 
	while(!istack_isempty(s)) {
		int cont = istack_pop(s);
		n = istack_pop(s); r = istack_pop(s); 
		// printf("%d %d %d\n", cont, n, r);
		if(cont == 1) {
			if(r == n || r == 0) {
				istack_push(v, 1); 
			} else {
				p3(s, 2, 0, 0); p3(s, 1, n-1, r-1); 
				p3(s, 1, n-1, r); 
			}
		} else { 
		// cont == 2
			istack_push(v, istack_pop(v)+istack_pop(v));
		}
	}
	return istack_pop(v); 
}


int main(int argc, char *argv[]) {
	printf("%d\n", combloop(atoi(argv[1]), atoi(argv[2]))); 
	return 0;
}
