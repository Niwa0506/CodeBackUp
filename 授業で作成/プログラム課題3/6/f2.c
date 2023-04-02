#include <stdio.h>
#include <stdlib.h>
 #define DIGITS 126
 char buf[DIGITS+2]; 

 int main() {
 int i, len1,len2,next=0,j,k,s,flag1=0;
 int arr[DIGITS] = {},check[2*DIGITS]={}; 
 
 j=0;
 fgets(buf,sizeof(buf),stdin); 
while(buf[j]!='\n') ++j;
len1 = j; 
 for(j=0; j<len1; ++j)
 arr[j] = (int)(buf[len1-1-j]-'0'); 
 i=0;
 fgets(buf,sizeof(buf),stdin); 
while(buf[i]!='\n') ++i;
len2 = i; 
for(i=0;i<len1;++i){
	for(j=0; j<len2; ++j){
		k=(int)(buf[len2-1-j]-'0');
 		if(check[i+j]+arr[i]*k+next>=10 && next>=1){
 			s=(check[i+j]+arr[i]*k+next)%10;
 			next=(check[i+j]+arr[i]*k+next)/10;
 			check[i+j]=s;
 		}
 		else if(check[i+j]+arr[i]*k>=10&&next==0){
 			s=(check[i+j]+arr[i]*k+next)%10;
 			next=(check[i+j]+arr[i]*k)/10;
 			check[i+j]=s;
 		}
 		else{
 			check[i+j]=check[i+j]+arr[i]*k+next;next=0;
 		}
	}
	if(next!=0&&i!=len1-1){check[i+j]=next;next=0;}
	//for(int q=len1+len2-2;q>=0;--q) printf("%d",check[q]); 
 	//printf("\n");
}
if(next!=0){len1+=1;check[i+j-1]=next;next=0;}
if(check[len1+len2-2]==0){len1-=1;flag1=1;
for(j=len1+len2-2;i>=0;--i){
	if(check[j]!=0){flag1=0;}
}
j=0;
}
if(flag1==1){printf("%d\n",j);}
else{
 for(i=len1+len2-2;i>=0;--i) printf("%d",check[i]); 
 	printf("\n");}
 return 0;
 }

