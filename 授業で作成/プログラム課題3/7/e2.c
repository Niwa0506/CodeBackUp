#include <stdio.h>

struct point{int x,y;};
int compare_by(struct point p1,struct point p2,char c){
	int judge=0,element1,element2,sub1,sub2,sub3,sub4;
	if(c=='X'){element1=p1.x;element2=p2.x;sub1=p1.y;sub2=p2.y;}
	else if(c=='Y'){element1=p1.y;element2=p2.y;sub1=p1.x;sub2=p2.x;}
	else if(c=='D'){element1=p1.x*p1.x+p1.y*p1.y;element2=p2.x*p2.x+p2.y*p2.y;
					sub1=p1.x;sub2=p2.x;sub3=p1.y;sub4=p2.y;}
	if(element1 > element2){judge=1;}
	else if(element1 < element2){judge=-1;}
	else{if(sub1 > sub2){judge=1;}
		 else if(sub1 < sub2){judge=-1;}
		 else if(sub1==sub2&&c=='D'){
		 	if(sub3>sub4){judge=1;}
		 	else if(sub3<sub4){judge=-1;}
		 }}
		return judge;
}

int max_index_by(struct point a[],int n,char c){
	int i=1,index=0;
	struct point max;
	max.x=a[0].x;max.y=a[0].y;
 while(i<n){
 	if(compare_by(a[i],max,c)>=0){
 		index=i;max.x=a[i].x;max.y=a[i].y;
 	}
 	i++;
 }
 return index;
}

int main(){
	char c,buf[128];
	struct point p,arr[128];
	int i=0;
	scanf("%c ",&c);
	while(fgets(buf,sizeof(buf),stdin)!=NULL && i<128){
		sscanf(buf,"%d %d",&p.x,&p.y);
		arr[i]=p;
		++i;
	}
	printf("%d\n",max_index_by(arr,i,c));
	return 0;
}