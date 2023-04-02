#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void set(char *a[]){

}
void sort(char *a[],int n){
	int i = 0,q,j = 1,w=0;char top[20],*str[20],*check[20],non,au,bu,no;int k,h =0;
	for(;i < n;++i){
		top[i] = *a[i];
		}
	for(i = 0;i <n;++i){
		non = top[i];
		for(int k =i+1;k<n;++k){
			if(non > top[k]){
				au = non;non = top[k];top[k] = au;
			}
		}
		top[i] = non;
	}
	for(int s=0;s<n;s++){
		bu = top[s];
		for(int e=s+1;e<n;e++){
			if(bu == top[e]){
					top[e] = '.';
			}
		}
		/*for(k=0;k<n;k++){
			if(bu ==*a[k]){str[h]=a[k];h+=1;}
	     }*/
	}
	for(q=0;q<n;q++){
		if(top[q] !='.'){
		bu = top[q];
		for(k=0;k<n;k++){
			if(bu ==*a[k]){str[h]=a[k];h+=1;}
	     }
	    	}
	    	/*for(;j<10;j++){
	     	 	for(k=n;k<h;k++){
	    	 		bu = str[k][j];check[w]= str[k];
	    	 		for(q=k+1;q<h;k++){
	    	 			if(str[q][0] !='.'){
	    					if(bu > str[q][j]){
	    						bu = str[q][j];check[w]= str[q];save = q;
	    					}
	    				}
	    			}
	    			w +=1;str[save][0] ='.';
	   			}	

		}*/
		//n =h;
	    }
	    
	for(i=0;i < n;++i){
	    a[i]=str[i];
	}
}
int judge(char a[],char b[]){
	int n= 0,i;
	for( i=0;a[i] == b[i];i++){
		printf("%c %c\n",a[i],b[i]);
		}
	printf("%s %s\n",a,b);
	if(a[i]> b[i]){n= 1;}
	printf("ジャッジ終了\n");
	return n;
}

void swap(char a[],char b[]){
	char x;int k=strlen(a),l=strlen(b);
	printf("%sと%sを交換した%s\n",a,b,x);
	if(k > l){//printf("%s %s\n",a,b);
       for(int i=0;i <k;i++){
   		x=a[i];a[i]=b[i];b[i]=x;
		}
	}else{
		for(int i=0;i<l;i++){
		//printf("まず%d\n",i);
		x=a[i];
		//printf("次に%d\n",i);
		a[i]=b[i];
		//printf("そして%d\n",i);
		b[i]=x;
	}
	
}
//printf("%sと%sを交換した%s\n",a,b,x);
//	printf("終了\n");
}
void sort2(char*a[],int n){
	char *str[20];int minindex;int j;
	for(int i=0;i < 20;i++){
	str[i] =malloc(sizeof(char)*10);}
	for(int i=0;i < n;++i){
		for( j=0;j<strlen(a[i]);j++){//printf("%dは%lu\n",i,strlen(a[i]));
		str[i][j]=a[i][j];/*printf("%c\n",str[i][j]);*/}str[i][j] ='\0';//printf("%s 終了\n",str[i]);
	}
	/*for(int i=0;i<n;++i){
		printf("%d %s\n",i,str[i]);}*/
for(int i=0;i<n;++i){
	minindex=i;
	for(int j=i+1;j<n;++j){
	if(judge(a[minindex],a[j])){minindex = j;}
	}printf("ターン%d終了\n",i);
	swap(a[minindex],a[i]);
}
}


		
int main(int argc,char *argv[]){
	char *dic[20];char *kick[20];int i,k,j;
	/*for(int i=0;i < 20;++i){
	dic[i] =malloc(sizeof(char)*10);
	kick[i] =malloc(sizeof(char)*10);
	}*/
	for(i=1;i<argc;++i){
		dic[i-1]=argv[i];//printf("%s\n",dic[i-1]);
		kick[i-1]=argv[i];
	}
	for(i=0;i < argc-1;++i){k=strlen(dic[i]);//printf("%d\n", k);
		for(j=0;j<k;j++){
			if(dic[i][j] == ' '){break;}
		kick[i][j] = dic[i][j];
		}
		kick[i][j] = '\0';//printf("%dと%dは%c\n",i,j,kick[i][j-1]);
	}	
	/*for(i=0;i<argc-1;++i){
		printf("%d %s\n",i ,kick[i]);
	}*/
		sort2(kick,i);
	//	printf("%d\n", i);
	for(int j= 0;j < i; ++j){
		printf("%s\n",kick[j]);
	}
	return 0;
	
}
