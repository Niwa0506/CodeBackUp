#include <stdio.h>

#define keytype int

#define LIMIT 200     /* データ数 */
#define MAX 100+1     /* テストの最高点=100 , +1はindex=1～100を使うため */

/* ソート対象データ */
int data200[] = {
71, 58, 32, 42, 21, 48, 32, 2, 26, 67,
7, 32, 40, 57, 99, 27, 100, 42, 69, 79,
83, 37, 7, 68, 22, 11, 11, 54, 57, 39,
43, 27, 63, 41, 69, 50, 56, 68, 18, 82,
34, 26, 13, 74, 83, 78, 68, 48, 86, 36,
93, 34, 39, 100, 21, 61, 77, 80, 81, 33,
85, 23, 60, 48, 31, 96, 64, 87, 63, 83,
68, 97, 8, 47, 36, 57, 91, 39, 71, 77,
39, 63, 77, 78, 28, 79, 38, 64, 24, 18,
3, 88, 48, 63, 56, 39, 24, 20, 92, 53,
69, 59, 15, 77, 72, 52, 100, 62, 55, 70,
4, 61, 99, 82, 4, 26, 26, 91, 97, 50,
94, 100, 58, 68, 28, 14, 06, 53, 70, 98,
5, 69, 22, 21, 11, 94, 39, 10, 22, 94,
46, 26, 20, 44, 7, 92, 36, 33, 0, 32,
83, 60, 98, 79, 28, 25, 21, 0, 44, 88,
65, 50, 56, 87, 37, 67, 47, 76, 43, 69,
35, 89, 61, 22, 99, 69, 13, 34, 68, 80,
32, 17, 39, 29, 24, 67, 20, 11, 68, 65,
99, 99, 81, 20, 85, 17, 53, 31, 93, 96,
};


typedef struct {
  keytype key;
} recordtype;

recordtype a[LIMIT+1];


/* 全レコードを表示 (nはレコード数） */
void print_record(recordtype a[], int n){
  int i;

  for(i=1; i<=n; i++){  
    printf("%d, ", a[i].key);
  }

  printf("\n");
}


void init_data(recordtype *x){
  int i;

  for(i=0; i<LIMIT; i++){
    x[i+1].key = data200[i];  /* 配列dataをrecordtype配列のメンバkeyにコピー */
  }

  printf("[Initialized Data]\n");
  print_record(x, LIMIT);
}


void swap(recordtype *x, recordtype *y){

  recordtype tmp;
  tmp = *x; *x = *y; *y = tmp;
}



void distribution_counting( recordtype a[], int n ){
  int  i, j, count[MAX];
  recordtype b[n+1];

  /* 得点の最大値+1であるMAXの使い方に注意して実装せよ */
  /* ここから */
  for(j=0;j<MAX;j++){count[j]=0;}
  for(i=1;i<=n;i++){count[a[i].key]++;}
  for(j=1;j<MAX;j++){count[j]+=count[j-1];}
  /* ここまで */
  for( i = n; i >= 1; i-- ){
    b[ count[ a[i].key] ] = a[i];
    count[ a[i].key ]--;
  }

  for( i = 1; i <= n; i++) { a[ i ] = b[ i ]; }
}


int main(void){

  init_data(a);

  distribution_counting( a, LIMIT );

  printf("\n[Distribution_counting]\n");
  print_record( a, LIMIT );
  
}
