#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

int main(int argc,char *argv[]){
	istackp s = istack_new(200);
	char *t = argv[1];
	for(int i = 0;t[i] != '\0';++i){istack_push(s,t[i]);}
	while(!istack_isempty(s)){putchar(istack_pop(s));}
	putchar('\n');
	return 0;
	
}