#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

bool balance1(char *t){
	istackp s=istack_new(200);int n = 0,m =0;char charge[10]={},answer;
	for(int i = 0;t[i] !='\0';++i){
		char c = t[i];
		//最初
		if(c == '(' || c == '[' || c == '{') {
			//if(istack_isempty(s)){
			istack_push(s,c);//answer = c;
			//}
			//else if(c == '(' || c == '[' || c == '{'){
			charge[n] = c;n+=1;
		//終わり
		}else if(c == ')' || c == ']' || c == '}'){
			if(istack_isempty(s)){return false;}
			//変換
			if(c == ')'){c= '(';}
			else if (c == ']'){c = '[';}
			else if (c == '}'){c = '{';}
			for(int i = 0;i < n;++i){
				if(c == charge[i]){
					istack_pop(s);charge[i] = 0;
					break;
				}
			/*if(c == answer){istack_pop(s);
				if(charge[m] == '(' || charge[m] == '[' || charge[m] == '{')
					istack_push(s,charge[m]);answer = charge[m];m+=1;*/
			}
			//for(int h= 0;h < n;++h) {
			//	if(c==charge[h]){
			//		charge[h] =0;
			//	}
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
	expect_bool(balance1("((a)())"),true,"((a)())");
	expect_bool(balance1(")(a)()("),false,")(a)()(");
	expect_bool(balance1("((a)()"),false,"((a)()");
	expect_bool(balance1("(a)())"),false,"(a)())");
	expect_bool(balance1("({[{[a}}]])"),true,"({[{[a}}]])");
	expect_bool(balance1("(((())))"),true,"(((())))");
	expect_bool(balance1(""))
	return 0;
}
