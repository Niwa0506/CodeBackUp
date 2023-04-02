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
		//printf("%c %c\n",a[i],b[i]);
		}
	//printf("%s %s\n",a,b);
	if(a[i]> b[i]){n= 1;}
	//printf("ジャッジ終了\n");
	return n;
}

void swap(char a[],char b[]){
	char x[20];int k=strlen(a),l=strlen(b);int i;
		strcpy(x,a);
	//printf("%sと%sを交換した%s\n",a,b,x);
   		strcpy(a,b);//printf("%s %s\n",a,b);
		strcpy(b,x);
}
//int number = 0;
void sort2(char*a[],int n){
	char *str[20],c[20];int minindex;int j,q;char **k,**l;
	for(int i=0;i < 20;i++){
	str[i] =malloc(sizeof(char)*20);}
	for(int i=0;i < n;++i){
		for( j=0;j<strlen(a[i]);j++){
		str[i][j]=a[i][j];}str[i][j] ='\0';
	}
	/*for(int i=0;i<n;++i){
		printf("%d %s\n",i,str[i]);}*/
for(int i=0;i<n;++i){
	minindex=i;//if(i!=0){printf("よって%d番目は%s\n",i,str[i-1]);}
	for(int j=i+1;j<n;++j){
	 if(judge(str[minindex],str[j])){minindex = j;}
	 }//printf("ターン%d終了\n",i);
	 /*for(q=0;q<strlen(a[minindex+1]);q++){
	 	c[q]=a[minindex+1][q];}
	 	c[q]='\0';printf("cは%s\n",c);*///a[minindex+1][0] = 'a';a[minindex+1][1] = 'a';
	 // printf("チェンジ前%s %s\n",str[i],str[minindex]);
	  if(str[minindex]!=str[i]){
	  swap(str[minindex],str[i]);}
	  /*for(q=0;q<strlen(c);q++){
	 	a[minindex+1][q]=c[q];
	 	}a[minindex+1][q] ='\0';*///str[minindex+1][0] = 'a';str[minindex+1][1] = 'a';
	  //printf("チェンジ後%s %s\n",str[i],str[minindex]);
			//number+=1;if(number ==13){break;}
		}
	for(int i=0;i < n;++i){
	a[i] = str[i];
}
	}


		
int main(int argc,char *argv[]){
	char *dic[20];char *kick[20];int i,k,j,w;
	for(i=0;i < 20;++i){
		dic[i]= malloc(sizeof(char)*20);
	}
	for(i=1;i<argc;++i){
		dic[i-1]=argv[i];
		kick[i-1]=argv[i];
	}
	for(i=0;i < argc-1;++i){k=strlen(dic[i]);
		for(j=0;j<k;j++){
			if(dic[i][j] == ' '){break;}
		kick[i][j] = dic[i][j];
		}
		kick[i][j] = '\0';
	}	w=i;
		sort2(kick,i);
	for(int j= 0;j < w; ++j){
		printf("%s\n",kick[j]);
	}
	return 0;
	
}
