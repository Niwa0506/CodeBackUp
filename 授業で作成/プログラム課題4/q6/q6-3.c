#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char a[],char b[]){
	char x[20];
		strcpy(x,a);
   		strcpy(a,b);
		strcpy(b,x);
}

int judge(char a[],char b[]){
	int n= 0,i;
	for( i=0;a[i] == b[i];i++){
		}
	if(a[i]> b[i]){n= 1;}
	return n;
}

int partition( char *a[], int l, int r ){
  int i,j,q;char v[20];//*v[20];
  char *str[20];
	for(i=0;i < 20;i++){
		str[i] =malloc(sizeof(char)*20);
		//v[i]   =malloc(sizeof(char)*20);
	}
	for(i=0;i < r-l+1;++i){
		for(q=0;q<strlen(a[l+i]);q++){
		str[l+i][q]=a[l+i][q];}str[l+i][q] ='\0';
	}i = 0;//printf("%s\n", str[0]);
  /*main*/
  	strcpy(v,str[l]);//printf("%s\n",v[0]);
  i =l;j =r+1;
  do{
     do{i++;}while(judge(v,str[i]) && i <=r);
     do{j--;}while(judge(str[j],v) && j >=l);
     if(i < j){swap(str[i],str[j]);}
  }while(j > i);//printf("iは%d jは%d\n",i,j);
  if(j <l ){j=j+1;swap(str[l],str[j]);j -=1;}
  else if(j >l){swap(str[l],str[j]);}

  for(int i=0;i < r-l+1;++i){
	a[l+i] = str[l+i];
}
  return j;
  
} 

void recursive_sort( char* a[], int l, int r ){
  int i;
   if(l < r){
   	if(r-l == 1){if(judge(a[l],a[r])){swap(a[l],a[r]);}}else{
    i = partition(a,l,r);//printf("%d %d %d %d %s\n",l,r,i,r-l,a[i]);
    //printf("1回目%d %d %s\n",l,i-1,a[i]);
    recursive_sort(a,l,i-1);
   // printf("2回目%d %d %s\n",i+1,r,a[i]);
    recursive_sort(a,i+1,r);}
  }
  
} 

int main(int argc,char *argv[]){
	int l=0,r;
	char *dic[20];char *kick[20];int i,k,j;
	for(i=1;i <argc;++i){
		dic[i-1]=argv[i];
		kick[i-1]=argv[i];
	}
	for(i=0;i < argc-1;++i){k=strlen(dic[i]);
		for(j=0;j<k;j++){
			if(dic[i][j] == ' '){break;}
		kick[i][j] = dic[i][j];
		}
		kick[i][j] = '\0';
	}	r=i-1;
	recursive_sort(kick,l,r);
	for(int j= 0;j < i; ++j){
			printf("%s\n",kick[j]);
		}
	return 0;
}
