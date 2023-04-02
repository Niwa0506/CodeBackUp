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
			if(istack_isempty(s)){return false;}
			if(c == ')'){c= '(';}
			else if (c == ']'){c = '[';}
			else if (c == '}'){c = '{';}
			for(int h = 0;h <n;++h){
			if(c == answer[h]){istack_pop(s);c= 0;}
			}
			}
		}
	return istack_isempty(s);
	
} 

int judge(char *t){
	int n =0,answer[100]={};
	for(int i = 0;t[i] !='\0';++i){
		char c = t[i];
		if(c == '(') {
			for(int j= i;t[j] !='\0';++j){
				if(t[j] == ')'){answer[i]=0;
					break;
				}else{answer[i]=i+1;}
			}
		}
		if(c == '[') {
			for(int j = i;t[j]!='\0';++j){
				if(t[j] == ']'){answer[i]=0;
					break;
				}else{answer[i]=i;}
			}
		}
		if(c == '{') {
			for(int j= i;t[j] !='\0';++j){
				if(t[j] == '}'){answer[n]=0;
					break;
				}else{answer[n]=i;}
			}
		}
		if(c == ')') {
			for(int j= i;t[j] !='\0';--j){
				if(t[j] == '('){answer[i]=0;
					break;
				}else{answer[i]=i+1;}
			}
		}
		if(c == ']') {for(int j= i;t[j] !='\0';--j){
				if(t[j] == '['){answer[i]=0;
					break;
				}else{answer[i]=i+1;}
			}
		}
		if(c == '}') {for(int j= i;t[j] !='\0';--j){
				if(t[j] == '{'){answer[i]=0;
					break;
				}else{answer[i]=i;}
			}
		}
		}
for(int i = 0;t[i] !='\0';++i){
			if(answer[i]!=0){printf("この間違いは%d文字目にある\n",answer[i]);}				
}
return  0;
} 
	

int main(int argc,char *argv[]){
	for(int i = 0;i < argc;++i) {
		printf("%s : %s\n",argv[i],balance1(argv[i])?"OK":"NG");
		judge(argv[i]);
	}
	return 0;
}