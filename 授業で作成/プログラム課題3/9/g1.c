#include <stdio.h>

char kijun;
struct point {int x,y;};

int compare(struct point p1,struct point p2){
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

 int is_heap(struct point a[],int n){
 	int i,flag=1;
 	for(i=0;i<n;i++){
 		if(2*i+2<n){
 			if(compare(a[i],a[2*i+2])<0)flag=0;
 		}
 		if(2*i+1<n){
 			if(compare(a[i],a[2*i+1])<0)flag=0;
 		}
 	}
 	return flag;
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
	if(is_heap(arr,n))printf("Yes.\n");
	else printf("No.\n");
	return 0;
}