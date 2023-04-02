#include <stdio.h>

#define keytype int

#define LIMIT 100


typedef struct {
  keytype key;
} recordtype;

recordtype a[LIMIT];

void swap(recordtype *x, recordtype *y){
  recordtype i;
   i.key = x->key;x->key = y->key;y->key = i.key;

}

void shellsort( recordtype a[], int n ){
     int  i, j, h; recordtype v;
     for( h=1; h*3+1 <= n/9; h = h*3+1 );
     for(    ; h > 0; h /= 3){
          for( i = h+1; i <= n; i++ ){
               v = a[i]; j = i;
               while( j>h && a[j-h].key > v.key){
                    a[j] = a[j - h]; j -=h;
                }
               a[j] = v;
	  }
     }
}

/* 各レコードにデータを格納 */
void init(void){
  a[0].key = 99;   /* a[0]はソート対象外になるので注意 */

  a[1].key = 35;
  a[2].key = 19;
  a[3].key = 5;
  a[4].key = 23;
  a[5].key = 16;
  a[6].key = 1;
  a[7].key = 28;
  a[8].key = 15;
  a[9].key = 32;
  a[10].key =8;

  a[11].key = 21;
  a[12].key = 6;
  a[13].key = 34;
  a[14].key = 31;
  a[15].key = 12;
  a[16].key = 18;
  a[17].key = 26;
  a[18].key = 2;
  a[19].key = 22;
  a[20].key = 17;

  a[21].key = 36;
  a[22].key = 11;
  a[23].key = 24;
  a[24].key = 3;
  a[25].key = 29;
  a[26].key = 7;
  a[27].key = 33;
  a[28].key = 30;
  a[29].key = 27;
  a[30].key = 20;

  a[31].key = 10;
  a[32].key = 14;
  a[33].key = 13;
  a[34].key = 4;
  a[35].key = 25;
  a[36].key = 9;
  
}

/* 全レコードを表示 (nはレコード数） */
void print_record(recordtype a[], int n){
  int i;

  for(i=0; i<=n; i++){   /* a[0]も表示する */
    printf("%d, ", a[i].key);
  }

  printf("\n");
  
}

int main(void){

  init();
  printf("[Before]:\n");
  print_record(a, 36);  /* 初期状態の表示 */

  shellsort(a, 36);

  printf("[After]:\n");
  print_record(a, 36);  /* ソート後の状態を表示 */
  
}
