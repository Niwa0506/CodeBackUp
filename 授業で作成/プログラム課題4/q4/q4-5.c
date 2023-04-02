#include <stdio.h>
#include <stdlib.h>

int* p;
int   N;
int k = 0;
int s = 0;
int o = 0;
void perm(int*p,int n,int*c,int m){
	int l = 0;
	int i;
	int j;
	int e;
	//配列の長さを代入	
	if(s < n){s =n;}
	if(n ==1){
		for(i = 0;i < m;++i){
			int q = 1;
				k= p[i];
				//現在地までの重複チェック
				for(j =-m+1;j <0;++j){
					if(k == c[j]){q =0;
				}
				}

				if(q == 1){
						*c = k;
					
				//printf("%p %c\n",c,*c);
			//for(int j =0;j < s;++j){
			//}
			for(i = 0;i <s;++i){
				l+=1;
				if(l == s){//printf("%d\n",l);
				printf("%d\n",*(c+i-s+1));l = 0;
				}else{printf("%d ",*(c+i-s+1));}
			}
			}
		}

	}else{// o=0;
		for( i = 0;i < m;++i){
				int g = 1; 
				k= p[i];
				//現在地までの重複チェック
				for(e=-o;e< 0 ;e++){
					if(c[e]== k){g = 0;
						//printf("その値は%d\n",e);
					}
				}

				if(g == 1){
					*c = k;o+=1;//printf("%d\n",*c);
			     perm(p,n-1,c+1,m);o -=1;
			      
			 }
			 // printf("%d終わり\n",*c);
				//printf("結果%d\n",o);

		}

	}
}
int main(int argc, char *argv[]){
	N = atoi(argv[1]);int c[10];int m = N;
	int i;
	p = malloc((N+1)*sizeof(int));
	for(i=1; i<=N; i++){
		p[i-1] = i;
	}
	for(i = 0;i < 10;++i){
		c[i] = 0;
	}

	perm(p,N,c,m);
	return 0;
}
