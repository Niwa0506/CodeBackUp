#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

void p5(istackp s, int a, int b, int c, int d, int e) { 
	istack_push(s,e); istack_push(s,d); 
	istack_push(s,c); istack_push(s,b); istack_push(s,a);
}
void hanoiloop(int k, int x, int y, int z) {
	istackp s = istack_new(100); p5(s, 1, k, x, y, z); 
	while(!istack_isempty(s)) {
		int cont = istack_pop(s); k = istack_pop(s);
		x = istack_pop(s); y = istack_pop(s); z = istack_pop(s); 
// printf("%d %d %c %c %c\n", cont, k, x, y, z);
		if(cont == 1) { 
			if(k == 1) {
			printf("move disk %d from %c to %c.\n", k, x, y);
			} else {
			p5(s, 2, k, x, y, z); p5(s, 1, k-1, x, z, y); }
		} else { // cont == 2
		printf("move disk %d from %c to %c.\n", k, x, y); 
		p5(s, 1, k-1, z, y, x);
		}	
 	}
}
int main(int argc, char *argv[]) {
	hanoiloop(atoi(argv[1]), ’A’, ’B’, ’C’); 
	return 0; 
}