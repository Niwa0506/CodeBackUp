#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void strtriangle(char *s){
	while(true){
		if(*s == '\0'){return;}
		printf("%s\n",s);
			s +=1;
	}
}

int main(int argc,char *argv[]){
	char s[100] = {};//printf("%lu\n",strlen(argv[1]));
	for(int i = 0;i <strlen(argv[1]);++i){
		s[i] =*(argv[1]+i);
	}
	//printf("%c\n",s);
	strtriangle(s);
	return 0;
}