#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTACK 520 /* スタックの要素数の最大値 */ 
char buf[MAXSTACK],go[MAXSTACK],back[MAXSTACK];
int top=0,down=0;
void insert(char *p){
	int i;
	for(i = 0;i <=strlen(buf);i++){
		if(p[i] == '{'){go[top++]='}';}
		else if(p[i]=='('){go[top++]=')';}
		else if(p[i]=='['){go[top++]=']';}
		else if(p[i]=='<'){go[top++]='>';}
		else if(p[i]=='}'|| p[i]==')'||p[i]==']'|| p[i]=='>'){
			back[down++]=p[i];
		}
		}
		//printf("%d %d\n",down,top);
	}
void check(char *p){
	int flag =1,i,s=0;
	if(top != down){flag = 0;}
	while(top != 0 && down !=0 &&flag ==1 && s <top){
		for(i=0;i <top;i++){
			if(i == 0){flag = 0;}
			if(go[s]==back[i]){flag = 1;break;}
		}
		s+=1;
	}
	if(flag == 1){printf("Good\n");printf("%d %d\n",down,top);
}
	else{printf("Bad\n");}
}
 int main(int argc, char const *argv[]){
	fgets(buf,sizeof(buf),stdin);
	insert(buf);//printf("%d %d\n",down,top);
	check(buf);
		
}