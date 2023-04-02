#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

bool balance1(char *t){
	istackp s=istack_new(200);int n = 0,m =0;char charge[10]={},answer;
	for(int i = 0;t[i] !='\0';++i){
		char c = t[i];
		//最初
		if(c == '(' || c == '[' || c == '{') {
			if(istack_isempty(s)){
			istack_push(s,c);answer = c;
			}
			else{charge[n] = c;n+=1;}
		//終わり
		}else if(c == ')' || c == ']' || c == '}'){
			if(istack_isempty(s)){return false;}
			//変換
			if(c == ')'){c= '(';}
			else if (c == ']'){c = '[';}
			else if (c == '}'){c = '{';}

			if(c == answer){istack_pop(s);
				if(charge[m] == '(' || charge[m] == '[' || charge[m] == '{')
					istack_push(s,charge[m]);answer = charge[m];m+=1;
			}
			for(int h= 0;h < n;++h) {
				if(c==charge[h]){
					charge[h] =0;
				}
			}
		}
	}
	return istack_isempty(s);
	
} 

int main(int argc,char *argv[]){
	for(int i = 0;i < argc;++i) {
		printf("%s : %s\n",argv[i],balance1(argv[i])?"OK":"NG");
	}
	return 0;
}