#include <stdio.h>
#include <limits.h>

#define LIMIT 100
typedef int keytype;   /* keytypeはintに設定 */

/* レコード用構造体 */
typedef  struct {
     keytype  key;
} recordtype; 

recordtype a[LIMIT+1];  /* ソート対象のレコード配列 */

int  data[] = {         /* LIMITはソート対象+1 */
  56, 91, 97, 95,  4, 72, 86, 96, 70, 37,
  10, 80, 39, 57, 44, 87, 16, 31, 84, 51,
  20, 74, 58, 81, 69,  5, 92, 41, 34, 30,
  82, 83, 73, 33, 67,  0, 90, 60, 38, 94,
  21, 43, 68, 42, 49, 18,  3, 47, 48, 46,
  13, 63,  2, 71, 99, 19,  8, 40, 23, 25,
  32, 61, 77, 26, 76,  9, 66, 52, 98, 93,
  78, 28, 36, 35, 55,  7, 11, 15, 64, 62,
  14, 75, 45, 06, 88, 85, 89,  1, 79, 65,
  59, 50, 17, 29, 12, 22, 27, 53, 24, 54
};

/* 全レコードを表示 */
void printrecord(recordtype *x){
  int i;

  for(i=0; i<=LIMIT; i++){
    printf("%02d: %02d, ", i, x[i].key);
    if(i%10 == 0) printf("\n");  /* 10個毎に改行 */
  }
}

/* データの初期化 */
void init_data(recordtype *x){
  int i;

  x[0].key = INT_MIN;  /* x[0]は未使用，番兵として使うために最小値で初期化 */
  for(i=0; i<LIMIT; i++){
    x[i+1].key = data[i];    /* 配列dataをrecordtype配列のメンバkeyにコピー */
  }
}

/* レコードの入れ替え */
void swap(recordtype *x, recordtype *y){
     recordtype  tmp;
     tmp = *x; *x = *y; *y = tmp;
}

/* 選択ソート */
void selection_sort( recordtype a[], int n ){
    int i,j,minindex;
    for(i = 1;i<n;i++){
      minindex = i;
      for(j = i+1;j <=n;j++){
        if(a[j].key <a[minindex].key){minindex = j;}
      }
        swap(&a[minindex],&a[i]);
    }
     printf("[Selection Sort]\n");

}

/* 挿入ソート */
void insertion_sort( recordtype a[], int n ){
    int i,j;recordtype v;
    for(i = 2;i <=n;++i){
      v = a[i];j = i;
      while(a[j-1].key > v.key){
        a[j] = a[j-1];j--;
      }
      a[j] =v;
    }
     printf("[Insertion Sort]\n");

}

/* バブルソート */
void bubble_sort( recordtype a[], int n ){
      int i,j;
      for(i = 1;i<n;i++){
        for(j =1;j<=n-i;j++){
          if(a[j].key  > a[j+1].key){
            swap(&a[j],&a[j+1]);
          }
        }
      }
     printf("[Bubble Sort]\n");

}


int main(void){

  init_data(a);  /* データの初期化 */
  printf("[Initialized Data]\n");
  printrecord(a);
  
/*  selection_sort(a, LIMIT);
  printrecord(a);

  init_data(a);
  insertion_sort(a, LIMIT);  
  printrecord(a);*/
  
  init_data(a);
  bubble_sort(a, LIMIT);  
  printrecord(a);

  return 0;
}
