 #include <stdio.h>

 char kijun;

 struct point{int x,y;};

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

 int partion(struct point a[],int m,int n){
 	int l=m,r=n+1,x,y;
 	struct point pivot=a[m];
 	do{
 		do{l++;}while(l<n&& compare(a[l],pivot)==-1);
 		do{r--;}while(r>m&&compare(a[r],pivot)==1);
 		if(l<r){x=a[l].x;y=a[l].y;a[l].x=a[r].x;a[l].y=a[r].y;a[r].x=x;a[r].y=y;}
 	}while(l<r);
 	x=a[m].x;y=a[m].y;a[m].x=a[r].x;a[m].y=a[r].y;a[r].x=x;a[r].y=y;
 	return r;
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
 printf("%d\n",partion(arr,0,n-1));
 for(i=0;i<n;i++)
 	printf("%d %d\n",arr[i].x,arr[i].y);
 return 0;
 }