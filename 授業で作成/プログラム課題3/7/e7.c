#include <stdio.h>
struct point {int x,y;};
struct point_loc{int loc;struct point p;};
int compare_by(struct point p1,struct point p2,char c,int pos1,int pos2){
	int judge=0,element1,element2,sub1,sub2,sub3,sub4;
	if(c=='X'){element1=p1.x;element2=p2.x;}
	else if(c=='y'){element1=p1.y;element2=p2.y;}
	else if(c=='d'){element1=p1.x*p1.x+p1.y*p1.y;element2=p2.x*p2.x+p2.y*p2.y;
					
	}
	if(element1 > element2){judge=1;}
	else if(element1 < element2){judge=-1;}
	else{
		 	if(pos1>pos2){judge=1;}
		 	else if(pos1<pos2){judge=-1;}
	}
		return judge;
}

int max_index_by(struct point_loc a[],int n,char c){
	int i=1,index=0;
	struct point_loc max;
	max.p.x=a[0].p.x;max.p.y=a[0].p.y;max.loc=a[0].loc;
 while(i<n){
 	if(compare_by(a[i].p,max.p,c,a[i].loc,max.loc)>=0){
 		index=i;max.p.x=a[i].p.x;max.p.y=a[i].p.y;
 	}
 	i++;
 }
 return index;
}

void stable_selection_sort(struct point a[],int n,char c){
	struct point_loc arr[n],max;
	int i=0,k=n,s;
	while(i<n){
		arr[i].loc= i;
		arr[i].p=a[i];
		i++;
	}
	for(;k>1;k--){
		s= max_index_by(arr,k,c);
		max.p.x=arr[s].p.x;max.p.y=arr[s].p.y;
		max.loc=arr[s].loc;
		arr[s].p.x=arr[k-1].p.x;arr[s].p.y=arr[k-1].p.y;
		arr[s].loc= arr[k-1].loc;
		arr[k-1].p.x=max.p.x;arr[k-1].p.y=max.p.y;
		arr[k-1].loc = max.loc;
	}
	i=0;
	while(i<n){
		a[i].x=arr[i].p.x;
		a[i].y=arr[i].p.y;
		i++;
	}
	/*for(i=0;i<n;i++)
		printf("%d %d %d\n",arr[i].p.x,arr[i].p.y,arr[i].loc);*/
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
	stable_selection_sort(arr,n,c);
	//printf("%d\n",count);
	for(i=0;i<n;i++)
		printf("%d %d\n",arr[i].x,arr[i].y);
	return 0;
}