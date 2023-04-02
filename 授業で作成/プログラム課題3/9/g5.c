#include <stdio.h>
#include <math.h>
struct point {int x,y;};
void radix_sort(struct point a[],int n,int r,int dmax){
int i,s=1,j,k=1;
for(i=0;i<r;i++){
	s=s*2;
}
int c[s];
struct point b[n],d[n],e[n],f[n];
	//桁用配列
	for(i=0;i<n;i++)
		b[i]=a[i];

	for(j=0;j<dmax;j++){
		//作業配列の作成
		for(i=0;i<n;i++){
			d[i].x=b[i].x%s;
			d[i].y=b[i].y;
		}
		//度数分布表の初期化
		for(i=0;i<s;i++)
			c[i]=0;
		//度数分布表作成
		for(i=0;i<n;i++)
			c[d[i].x]+=1;
		//累積分布表作成
		for(i=1;i<s;i++)
			c[i]+=c[i-1];
		//printf("0K\n");
		for(i=0;i<n;i++){
			c[d[n-i-1].x]-=1;
			e[c[d[n-i-1].x]]=b[n-i-1];
			f[c[d[n-i-1].x]] = a[n-i-1];
		}
		//元の配列の更新
		for(i=0;i<n;i++)
			a[i]=f[i];
		//作業配列の更新
		for(i=0;i<n;i++)
			b[i]=e[i];
		for(i=0;i<n;i++)
			b[i].x=b[i].x/s;

		for(i=0;i<n;i++)
			printf("%d %d\n",a[i].x,a[i].y);
			printf("--\n");
	}
}

int main(){
	char buf[128];
	struct point p,arr[128];
	int i=0,n,r,dmax;
	scanf("%d %d ",&r,&dmax);
	while(fgets(buf,sizeof(buf),stdin)!=NULL&&i<128){
		sscanf(buf,"%d %d",&p.x,&p.y);
		arr[i]=p;
		i++;
	}
	n=i;
	radix_sort(arr,n,r,dmax);
	return 0;
}