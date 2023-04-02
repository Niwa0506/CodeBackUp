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
	printf("> "); 
	while(getl(buf, 200)){
		if(buf[0] == 'q') { break;
		} else if(buf[0] == 'p'){printf("%s\n",ebuf_str(e));
		} else if(buf[0] =='t') {ebuf_top(e);
		} else if(buf[0] =='f') {
			//if(buf[1] == ' ' ){printf("数字が入力されていません。\n");
			//}else{
				n = atoi(&buf[1]);
				while(n > 0 && *ebuf_str(e) != EOF){
				ebuf_forward(e);
				 n-=1;
			//	}
			}
		} else if(buf[0] == 'b') {
			//if(buf[1] == ' ' || (buf[1] <100 && buf[1] > 0)){printf("数字が入力されていません。\n");
			//}else{
				n = atoi(&buf[1]);
				while(n > 0 && *ebuf_str(e) != EOF){
					ebuf_backward(e);
					n-=1;
			//	}
			}
		} else if(buf[0] =='i') {ebuf_insert(e, buf+1);
		}else {ebuf_forward(e); printf("%s\n",ebuf_str(e));
		}
  		printf(">");
  	}
	return 0; 
}
