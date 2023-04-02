#include <stdio.h>
#include <string.h>
#define MAXLEN 128 /* 文字列の最大長 */
char buf[MAXLEN+2]; /* 文字列を読み込む配列 (改行文字とNULL 文字を含む) */
char answer[81];
int main(void) {
  char *p,*q;int i,j;
  for(j =0;j < 80;j++){
  	answer[j] = ' ';
  }
  answer[j] = '\0';
  while( fgets(buf, sizeof(buf), stdin) != NULL ) {
    p = strchr(buf, '\n');
    if (p != NULL) *p = '\0';
    q = buf;
    i =0;
    while(sscanf(q,"%d",&i) !=EOF){
    	//if(n ==1){printf("%s\n",buf);n=0;}
      		answer[i] = '#';//printf("%d %s\n",i,answer);
    	q = strchr(q,' ');
    	if(q == NULL)break;
    	else while(*q == ' ')++q;
    }
    if(i != 0){answer[i] = '\0';}
    else{
    answer[i+1] = '\0';}
    //printf("%s\n",buf);
    printf("%s\n",answer);
    for(j = 0;j < 80;j++){
    answer[j] = ' ';
	}
    answer[j] = '\0';

   // printf("%s\n", buf);
  }
return 0; 
}