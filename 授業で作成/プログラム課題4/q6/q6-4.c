#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*void swap(char *n,int *s,int x, int y){
     char  tmp;
     tmp = *x; *x = *y; *y = tmp;
}*/

/* 選択ソート */
void selection_sort( int a[], char b[],int n ){
    int i,j,minindex,number;char x;
    for(i = 0;i<n;i++){
      minindex = i;
      for(j = i+1;j <=n;j++){
        if(a[j] > a[minindex]){minindex = j;}
      }
      number = a[i];x = b[i];
      a[i] = a[minindex];b[i] = b[minindex];
      a[minindex] = number;b[minindex]= x;
    }
}

int main(int ac,char*av[]){
	char *filename;
	filename = av[1];
	FILE *fp;int n=0,i=0,j=0,q=0,s=0,r=0,sum[300],pos=0,
	week1[50],week2[50],week3[50],week4[50],week5[50],week6[50],total[50];
    char line[5],check[51],cweek1[51],cweek2[51],cweek3[51],cweek4[51],cweek5[51],cweek6[51],ctotal[51];
    fp = fopen(filename,"r");  
    if(fp == NULL){
    fprintf(stderr, "No such file: %s\n", filename);
    exit(1);
  }
      while( ( pos = fscanf(fp,"%4s",line)) != EOF ){
      	if(n%7==0){check[s]=*line;s+=1;printf("文字は%c\n",check[s-1]);}
      	sum[i] = atoi(line);
    printf( "%d\n",sum[i]);i++;n+=1;
  }printf("終了\n");check[s] = '\n';
  for(j=0;j < s;j++){
  	cweek1[j] = check[j];
  	cweek2[j] = check[j];
  	cweek3[j] = check[j];
  	cweek4[j] = check[j];
  	cweek5[j] = check[j];
  	cweek6[j] = check[j];
  	ctotal[j] = check[j];
  	//printf("%c\n",cweek1[j]);
  }
    cweek1[j] =  '\n';
  	cweek2[j] =  '\n';
  	cweek3[j] =  '\n';
  	cweek4[j] =  '\n';
  	cweek5[j] =  '\n';
  	cweek6[j] =  '\n';
   
  	for(j=1;j < i/7+1;j++){
  		week1[j-1] = sum[7*j-6];
  		week2[j-1] = sum[7*j-5];
  		week3[j-1] = sum[7*j-4];
  		week4[j-1] = sum[7*j-3];
  		week5[j-1] = sum[7*j-2];
  		week6[j-1] = sum[7*j-1];
  		total[j-1] =week1[j-1]+week2[j-1]+week3[j-1]+week4[j-1]+week5[j-1]+week6[j-1]; 
  		//printf("%d\n",week6[j-1]);
  	}
  	selection_sort(week1,cweek1,s-1);
  	selection_sort(week2,cweek2,s-1);
  	selection_sort(week3,cweek3,s-1);
  	selection_sort(week4,cweek4,s-1);
  	selection_sort(week5,cweek5,s-1);
  	selection_sort(week6,cweek6,s-1);
  	selection_sort(total,ctotal,s-1);
  	printf("Week 1: ");
  	for(i = 0;i < s;i++){
  		printf("%c ",cweek1[i]);
  	}printf("\n");
  	printf("Week 2: ");
  	for(i = 0;i < s;i++){
  		printf("%c ",cweek2[i]);
  	}printf("\n");
  	printf("Week 3: ");
  	for(i = 0;i < s;i++){
  		printf("%c ",cweek3[i]);
  	}printf("\n");
  	printf("Week 4: ");
  	for(i = 0;i < s;i++){
  		printf("%c ",cweek4[i]);
  	}printf("\n");
  	printf("Week 5: ");
  	for(i = 0;i < s;i++){
  		printf("%c ",cweek5[i]);
  	}printf("\n");
  	printf("Week 6: ");
  	for(i = 0;i < s;i++){
  		printf("%c ",cweek6[i]);
  	}printf("\n");
  	printf("Total : ");
  	for(i = 0;i < s;i++){
  		printf("%c ",ctotal[i]);
  	}printf("\n");






      

    fclose(fp);
    return 0;
}