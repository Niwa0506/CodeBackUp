#include <stdio.h>
#include <stdlib.h>
 #define DIGITS 126
 char buf[DIGITS+2]; 
 int main() {
 int i, len,next=0,flag=1,len1;
 int arr[2*DIGITS] = {}; 
 
 for(i=0;i<128;i++){buf[i]='0';}
 i=0;
 fgets(buf,sizeof(buf),stdin); 
while(buf[i]!='\n') ++i;
len = i; len1=i;
 for(i=0; i<len; ++i)
 arr[i] = (int)(buf[len-1-i]-'0');
 i=0;
 fgets(buf,sizeof(buf),stdin); /* ←改行までの文字列を buf に格納 */
while(buf[i]!='\n') ++i;
len = i; /* ←改行の位置を len に保存 */
if(len1<len){len1=len;}//printf("%d %d\n",len,len1);
 for(i=0; i<len; ++i){//printf("%d %d %d\n",arr[i],(int)(buf[len-1-i]-'0'),next);
 	if(arr[i]+(int)(buf[len-1-i]-'0')+next>=10&&next==0){
 	arr[i]=arr[i]+(int)(buf[len-1-i]-'0')-10;next=1;}
 	else if(arr[i]+(int)(buf[len-1-i]-'0')+next>=10&&next==1){
 		arr[i]=arr[i]+(int)(buf[len-1-i]-'0')+next-10;}
	else {arr[i] += (int)(buf[len-1-i]-'0')+next;next=0;}
	//printf("%d\n",arr[i]);
 }
	if(next!=0){
		arr[i]+=1;
		if(arr[len1]!=0){len1+=1;}
	}
 for(i=len1-1;i>=0;--i) printf("%d",arr[i]); 
 printf("\n");
 return 0;
 }

