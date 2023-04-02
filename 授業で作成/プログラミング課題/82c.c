#include <stdio.h>
#include "ebuf.h"
#include <string.h>
#include <stdlib.h>
bool getl(char s[], int lim) {
	int c, i = 0;
	for(c = getchar(); c != EOF && c != '\n'; c = getchar()) {
		s[i++] = c; 
		if(i+1 >= lim) { break; } 
	}
	s[i] = '\0'; 
	return c;
}


int main(void) {
	char buf[200];int n;
	ebufp e = ebuf_new(); 
	char f[100];
	ebufp d = ebuf_new();
	printf("> "); 
	while(getl(buf, 200)){
		if(buf[0] == 'q') { break;
		} else if(buf[0] == 'p'){printf("%s\n",ebuf_str(e));
		} else if(buf[0] =='t') {ebuf_top(e);
		} else if(buf[0] =='f') {
				ebuf_forward(e);
		} else if(buf[0] == 'b') {
					ebuf_backward(e);
		} else if(buf[0] =='i') {ebuf_insert(e, buf+1);
		}else if(buf[0] == 'd') { 
			ebuf_delete(e);
		}else {ebuf_forward(e); printf("%s\n",ebuf_str(e));
		}
  		printf(">");
  	}
	return 0; 
}