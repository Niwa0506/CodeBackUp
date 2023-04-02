#include <stdio.h>
#include <stdlib.h>
int count=0;
char kijun;

struct point{int x,y;};

int compare(struct point p1,struct point p2){
 	int judge=0,element1,element2,sub1,sub2,sub3,sub4;
 	++count;
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

int partion(struct point a[],int m,int n){
 	int l=m+1,r=n,set=m+rand()%(n-m+1);
 	struct point pos;
 	pos=a[m];a[m]=a[set];a[set]=pos;
 	/*for(int i=0;i<n;i++)
 	printf("結果1は%d %d %d\n",set,a[i].x,a[i].y);*/
 	for(int i=l;i<=n;i++){
             if(compare(a[m],a[i])==1)
             	{/*printf("0K\n");*/pos=a[l];a[l]=a[i];a[i]=pos;l++;}
 	}
 	pos=a[m];a[m]=a[l-1];a[l-1]=pos;
 	/*for(int i=0;i<n;i++)
 	printf("結果2は%d %d %d\n",set,a[i].x,a[i].y);*/
 	return l-1;
}

void quicksort(struct point a[],int m, int n){
	if(m<n){
		int p = partion(a,m,n);
		/*printf("%d\n",p);
		for(int i=0;i<n;i++)
 		printf("%d %d\n",a[i].x,a[i].y);*/
		quicksort(a,m,p-1);
		quicksort(a,p+1,n);
	}
}
 int main(){
 	char buf[128];
 	struct point p,arr[128];
 	int i=0,n;
 	scanf("%c ",&kijun);
 	while(fgets(buf,sizeof(buf),stdin)!=NULL&&i<128){
 		sscanf(buf,"%d %d",&p.x,&p.y);
 		arr[i]=p;
 		++i;
 }
 n=i;
 quicksort(arr,0,n-1);
 printf("%d\n",count);
 for(i=0;i<n;i++)
 	printf("%d %d\n",arr[i].x,arr[i].y);
 return 0;
 }