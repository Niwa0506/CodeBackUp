#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define keytype int

#define LIMIT 200

/* ソート対象データ */
int data200[] = {
94, 82, 2, 53, 45, 11, 77, 7, 162, 184,
10, 38, 167, 65, 69, 186, 72, 48, 143, 180,
20, 41, 139, 195, 153, 81, 175, 55, 29, 24,
78, 51, 56, 125, 171, 16, 18, 159, 117, 71,
43, 192, 105, 49, 42, 140, 103, 168, 17, 166,
50, 31, 129, 8, 47, 88, 156, 57, 110, 137,
84, 60, 61, 63, 131, 147, 89, 124, 138, 165,
21, 76, 75, 25, 169, 126, 91, 101, 119, 19,
28, 30, 1, 83, 158, 142, 163, 27, 151, 144,
176, 157, 96, 146, 134, 34, 14, 74, 132, 99,
100, 68, 102, 80, 22, 123, 127, 148, 4, 149,
58, 97, 112, 128, 32, 85, 6, 174, 12, 66,
39, 106, 107, 92, 111, 164, 173, 46, 9, 188,
130, 145, 155, 0, 108, 135, 118, 198, 115, 37,
36, 54, 23, 104, 33, 79, 141, 154, 90, 44,
86, 87, 152, 59, 194, 114, 185, 161, 13, 150,
160, 178, 193, 67, 199, 98, 73, 03, 183, 35,
177, 70, 172, 133, 113, 15, 121, 5, 136, 191,
95, 181, 62, 40, 26, 109, 116, 187, 93, 189,
190, 170, 52, 120, 64, 182, 196, 122, 197, 179
};


typedef struct {
  keytype key;
} recordtype;

recordtype a[LIMIT+1];


/* 全レコードを表示 (nはレコード数） */
void print_record(recordtype a[], int n){
  int i;

  for(i=0; i<=n; i++){   /* a[0]も表示する */
    printf("%d, ", a[i].key);
  }

  printf("\n");
}


void init_data(recordtype *x){
  int i;

  x[0].key = INT_MIN;  /* x[0]は未使用，番兵として使うために最小値で初期化 */
  for(i=0; i<LIMIT; i++){
    x[i+1].key = data200[i];  /* 配列dataをrecordtype配列のメンバkeyにコピー */
  }

  printf("[Initialized Data]\n");
  print_record(x, 200);
}


void swap(recordtype *x, recordtype *y){
 recordtype i;
  i.key = x->key;x->key = y->key;y->key = i.key;
}

/* 小テスト12-3用 */
void quicksort2 ( recordtype a[], int n ){
 int i,last;
 if(n<=1)return ;
 swap(&a[0],&a[rand()%n]);
 last = 0;
 for(i = 1;i<n;i++){
  if(a[i].key < a[0].key){swap(&a[++last],&a[i]);}
 }
 swap(&a[0],&a[last]);
 quicksort2(a,last);quicksort2(a+last+1,n-last-1);
} 


int main(void){

  init_data(a);
  printf("[quick sort2]\n");
  quicksort2(a+1, LIMIT);
  print_record(a, LIMIT);
  
}
