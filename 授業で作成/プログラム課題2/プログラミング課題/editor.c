#include <stdio.h>
#include "ebuf.h"
#include <string.h>
bool getl(char s[], int lim) {
	int c, i = 0;
	for(c = getchar(); c != EOF && c != '\n'; c = getchar()) {
		s[i++] = c; 
		if(i+1 >= lim) { break; } 
	}
	s[i] = '\0'; 
	return c;
}

bool readfile(ebufp e, char *fname) { char str[200];
	FILE *f = fopen(fname, "r");
	if(f == NULL) { return false; } 
	while(fgets(str, 200, f) != NULL) {
		int len = strlen(str);
		if(len > 0) { str[len-1] = '\0'; } ebuf_insert(e, str);
	}
	fclose(f); 
	return true; 
}

bool writefile(ebufp e, char *fname) { FILE *f = fopen(fname, "w");
	if(f == NULL) { 
		return false; 
	} 
	ebuf_top(e);
	while(!ebuf_iseof(e)) {
		fprintf(f, "%s\n", ebuf_str(e)); ebuf_forward(e);
	}
	fclose(f); return true; 
}

int main(void) {
	char buf[200];
	ebufp e = ebuf_new(); 
	printf("> "); 
	while(getl(buf, 200)){
		if(buf[0] == 'q') { break;
		} else if(buf[0] == 'p'){
			printf("%s\n",ebuf_str(e));
		} else if(buf[0] =='t') {
			ebuf_top(e);
		} else if(buf[0] =='f') {
			ebuf_forward(e);
		} else if(buf[0] == 'b') {
			ebuf_backward(e);
		} else if(buf[0] =='i') {
			ebuf_insert(e, buf+1);
		} else if(buf[0] =='r'){
			readfile(e,buf+1);
			if(readfile(e,buf+1) == false){printf("読み込みに失敗しました。\n");}
		}else if(buf[0] == 'w'){
			writefile(e,buf+1);
			if(writefile(e,buf+1)== false){printf("書き込みに失敗しました。\n");}
		}else {
	 	ebuf_forward(e); printf("%s\n",ebuf_str(e));
  		}
  		printf(">");
  	}
	return 0; 
}