#include <stdio.h>

int count=0;
char kijun;
struct point {int x,y;};

int compare(struct point p1,struct point p2){
	++count;
 	int judge=0,element1,element2,sub1,sub2,sub3,sub4;
	if(kijun=='X'){element1=p1.x;element2=p2.x;sub1=p1.y;sub2=p2.y;}
	else if(kijun=='Y'){element1=p1.y;element2=p2.y;sub1=p1.x;sub2=p2.x;}
	else if(kijun=='D'){element1=p1.x*p1.x+p1.y*p1.y;element2=p2.x*p2.x+p2.y*p2.y;
					sub1=p1.x;sub2=p2.x;sub3=p1.y;sub4=p2.y;}
	if(element1 > element2){judge=1;}
	else if(element1 < element2){judge=-1;}
	else{if(sub1 > sub2){judge=1;}
		 else if(sub1 < sub2){judge=-1;}
		 else if(sub1==sub2&&kijun=='D'){
		 	if(sub3>sub4){judge=1;}
		 	else if(sub3<sub4){judge=-1;}
		 }}
		return judge;
 } 

 void pushdown(struct point a[],int m,int n){
 	int judge,i=2*m+2;struct point check;
 	if(2*m+2<=n){
 		judge=compare(a[2*m+2],a[2*m+1]);
 		if(judge<0){i=2*m+1;}
 		if(compare(a[i],a[m])>0){
 			check=a[i];a[i]=a[m];a[m]=check;
 		pushdown(a,i,n);}

 	}
 	if(2*m+1==n){
 		if(compare(a[2*m+1],a[m])>0){
 			check=a[2*m+1];a[2*m+1]=a[m];a[m]=check;
 		}}
 }

int main(){
	char buf[128];
	struct point p,arr[128];
	int i=0,n;
	scanf("%c ",&kijun);
	while(fgets(buf,sizeof(buf),stdin)!=NULL&&i<128){
		sscanf(buf,"%d %d",&p.x,&p.y);
		arr[i]= p;
		++i;
	}
	n=i;
	pushdown(arr,0,n-1);
	printf("%d\n",count);
	for(i=0;i<n;i++){
		printf("%d %d\n",arr[i].x,arr[i].y);
	}
	return 0;
}