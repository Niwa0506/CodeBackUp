#include<stdio.h> 
int count = 0;
char kijun;

struct point { int x, y; }; 
int compare(struct point p1, struct point p2) {
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

void merge(struct point a[], int m, int n, int h) {
 struct point arr[128];
 int first1=m,first2=h+1,q=m;
 	while(first1<=h&&first2<=n){
 		if(compare(a[first1],a[first2])==1){
 			arr[q]=a[first2];first2++;q++;
 		}
 		else{arr[q]=a[first1];first1++;q++;}
 	}
 	if(first1<=h){
 		while(first1<=h)
 			arr[q++]=a[first1++];
 	}
 	if(first2<=n){
 		while(first2<=n)
 			arr[q++]=a[first2++];
 	}
 	first1=m;
 	while(first1<=n){
 		a[first1]=arr[first1];
 	first1++;}
}

int main() {
 char buf[128];
 struct point p, arr[128];
 int i=0,h,n;
 scanf("%c %d ",&kijun, &h); /* 規準をkijun に，前半終了の添字を h に格納する */
 while(fgets(buf,sizeof(buf),stdin)!=NULL && i<128) {
 sscanf(buf,"%d %d",&p.x,&p.y); arr[i] = p;
 ++i;
 }
 n=i;
 merge(arr, 0, n-1, h);
 printf("%d\n", count);
 for(i=0;i<n;++i)
 printf("%d %d\n", arr[i].x, arr[i].y);
 return 0;
 }