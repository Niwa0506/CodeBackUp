#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void selection_sort( double a[], char b[],double c[],double d[],int n ){
    int i,j,minindex;
    double n1,n2,n3;char x;
    for(i = 0;i<n;i++){
      minindex = i;
      for(j = i+1;j <=n;j++){
        if(a[j] > a[minindex]){minindex = j;
        }else if(a[j] == a[minindex]){
      		if(c[j] > c[minindex]){minindex = j;
      		}else if(c[j] == c[minindex]){
      			if(d[j] < d[minindex]){minindex = j;}
      		}
      	}
      }
      n1 = a[i];x = b[i];n2 = c[i];n3 = d[i];
      a[i] = a[minindex];b[i] = b[minindex];c[i]= c[minindex];d[i]=d[minindex];
      a[minindex] = n1;b[minindex]= x;c[minindex]= n2;d[minindex] = n3; 
    }
}

int main(int ac,char*av[]){
	char *filename;
	filename = av[1];
	FILE *fp;int n=0,i=0,j=0,q=0,s=0,r=0,sum[300],pos=0;
	double win[50],lose[50],draw[50],last[50],total[50];
    char line[5],check[51],pwin[51],plose[51],pdraw[51],plast[51],ptotal[51];
    fp = fopen(filename,"r");  
    if(fp == NULL){
    fprintf(stderr, "No such file: %s\n", filename);
    exit(1);
  }
      while( ( pos = fscanf(fp,"%4s",line)) != EOF ){
      	if(n%5==0){check[s]=*line;s+=1;printf("文字は%c\n",check[s-1]);
      	}
      	sum[i] = atoi(line);
    printf( "%d\n",sum[i]);
      	i++;n+=1;
  }printf("終了\n");
  check[s] = '\n';
  for(j=0;j < s;j++){
  	pwin[j] = check[j];
  	/*plose[j] = check[j];
  	pdraw[j] = check[j];
  	plast[j] = check[j];
  	ptotal[j] = check[j];*/
  }
    win[j] =  '\n';
  	lose[j] =  '\n';
  	draw[j] =  '\n';
  	last[j] =  '\n';
   
  	for(j=1;j < i/5+1;j++){
  		win[j-1] = sum[5*j-4];
  		lose[j-1] = sum[5*j-3];
  		draw[j-1] = sum[5*j-2];
  		last[j-1] = sum[5*j-1];
  		total[j-1] =win[j-1]/(win[j-1]+lose[j-1]); 
  		printf("%.3f %.3f %.3f\n",win[j-1],last[j-1],total[j-1]);
  	}
  	selection_sort(total,pwin,win,last,s-1);
  	for(i = 0;i < s;i++){
  		printf("%c ",pwin[i]);
  	}printf("\n");
    fclose(fp);
    return 0;
}