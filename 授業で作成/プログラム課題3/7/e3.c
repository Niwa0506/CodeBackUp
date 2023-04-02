#include <stdio.h>
int count =0;
struct point {int x,y;};

int compare_by(struct point p1,struct point p2,char c){
	++count;
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

void selection_sort(struct point a[],int n,char c){
	struct point max;int s;
	for(int k=n;k>1;k--){
		s = max_index_by(a,k,c);
		max.x=a[s].x;
		max.y=a[s].y;
		a[s].x=a[k-1].x;
		a[s].y=a[k-1].y;
		a[k-1].x=max.x;
		a[k-1].y=max.y;
	}
}

int main(){
	char c,buf[128];
	struct point p,arr[128];
	int i=0,n;
	scanf("%c ",&c);
	while(fgets(buf,sizeof(buf),stdin)!=NULL && i<128){
		sscanf(buf, "%d %d",&p.x,&p.y);
		arr[i]=p;
		++i;
	}
	n=i;
	selection_sort(arr,n,c);
	printf("%d\n",count);
	for(i=0;i<n;i++)
		printf("%d %d\n",arr[i].x,arr[i].y);
	return 0;
}