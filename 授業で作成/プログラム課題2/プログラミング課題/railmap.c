#include <stdio.h>
#include <stdlib.h>
#include "railmap.h"
#include "istack.h"

int main(int argc,char *argv[]){
	int start = atoi(argv[1]),goal = atoi(argv[2]);
	istackp s = istack_new(100);
	map[start].dist = 0;istack_push(s,start);
	
	while(!istack_isempty(s)){
		int i,n =istack_pop(s);
		struct node *p = map+n;
		printf("%d: %s, %d\n",n,p->name,p->dist);
		if(n ==goal){printf("GOAL.\n");break;}
		
		for(i =0;i < p->num;++i){
			int k = p->edge[i];
			if(map[k].dist < 0){
				map[k].dist = p->dist+1;istack_push(s,k); 
			}
		}
	}
	return 0;
}

