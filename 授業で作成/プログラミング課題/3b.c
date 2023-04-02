#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

bool balance1(char *t){
	istackp s=istack_new(200);int n =0;char answer[10] ={};
	for(int i = 0;t[i] !='\0';++i){
		char c = t[i];
		if(c == '(' || c == '[' || c == '{') {
			istack_push(s,c);answer[n] = c;n+=1;
		}else if(c == ')' || c == ']' || c == '}'){
			n -=1;
			if(istack_isempty(s)){return false;}
			if(c == ')'){c= '(';}
			else if (c == ']'){c = '[';}
			else if (c == '}'){c = '{';}
			//for(int h = 0;h <=n;++h){
			if(c == answer[n]){istack_pop(s);}
			//}
			}
		}
	return istack_isempty(s);
	
} 


char *bool12str(bool b){return b ? "true" :"false";}


 void expect_bool(bool b1,bool b2,char *msg){
	printf("%s %s:%s %s\n",(b1== b2)?"OK":"NG",bool12str(b1),bool12str(b2),msg);
}


int main(int argc,char *argv[]){
	expect_bool(balance1("{()}"),true,"{()}");
	expect_bool(balance1("{(})"),false,"{(})");
	expect_bool(balance1("(((())))"),true,"(((())))");
	return 0;
}