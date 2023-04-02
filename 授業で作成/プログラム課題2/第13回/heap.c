#include <stdio.h>
#include <limits.h>

#define keytype int

#define LIMIT 300

/* ソート対象データ */
int data300[] = {
83, 161, 292, 227, 254, 240, 169, 53, 236, 203,
208, 159, 158, 78, 228, 165, 265, 92, 269, 272,
46, 98, 0, 288, 18, 226, 72, 230, 249, 62,
122, 79, 157, 175, 126, 224, 68, 21, 181, 99,
27, 140, 24, 293, 270, 31, 225, 167, 114, 56,
51, 267, 102, 213, 287, 206, 259, 22, 146, 280,
268, 232, 284, 251, 191, 299, 196, 5, 133, 217,
69, 242, 20, 60, 108, 209, 58, 190, 26, 183,
186, 57, 296, 40, 149, 237, 248, 119, 52, 275,
101, 127, 1, 171, 88, 194, 115, 124, 128, 160,
11, 252, 41, 166, 49, 176, 163, 188, 264, 109,
286, 3, 121, 84, 29, 120, 54, 16, 152, 95,
295, 197, 234, 70, 255, 184, 241, 170, 261, 297,
71, 253, 10, 107, 150, 212, 200, 231, 218, 97,
7, 211, 74, 61, 112, 17, 151, 262, 75, 66,
30, 177, 35, 266, 91, 123, 32, 274, 55, 153,
260, 136, 105, 125, 82, 258, 73, 34, 12, 80,
118, 276, 145, 223, 281, 246, 77, 76, 233, 142,
198, 219, 277, 193, 235, 96, 65, 25, 129, 205,
130, 81, 247, 271, 294, 106, 279, 86, 89, 50,
173, 201, 221, 137, 210, 289, 23, 45, 4, 111,
144, 104, 131, 256, 273, 139, 43, 37, 28, 155,
93, 285, 147, 8, 154, 36, 282, 290, 215, 172,
85, 189, 174, 33, 180, 263, 245, 204, 48, 14,
64, 182, 156, 162, 87, 110, 2, 47, 202, 179,
143, 187, 67, 13, 195, 148, 63, 278, 164, 9,
100, 178, 6, 94, 42, 216, 214, 117, 222, 132,
207, 298, 44, 257, 38, 39, 135, 238, 220, 19,
113, 59, 185, 90, 103, 291, 141, 229, 15, 250,
192, 138, 244, 243, 168, 134, 199, 283, 116, 239
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
    x[i+1].key = data300[i];  /* 配列dataをrecordtype配列のメンバkeyにコピー */
  }

  printf("[Initialized Data]\n");
  print_record(x, LIMIT);
}


void swap(recordtype *x, recordtype *y){

  recordtype tmp;
  tmp = *x; *x = *y; *y = tmp;
}

void pushdown( recordtype a[], int first, int last ){
    int r= first;int k=2*r;
    while(k<=last){
      if(k<last&&a[k].key<a[k+1].key){k++;}
      if(a[r].key >=a[k].key){break;}
    swap(&a[k],&a[r]);
    r= k;k=2*r;
    }
}
void pushdown2(recordtype a[],int first,int last){
  int r= first;int k=2*r;
    while(k<=last){
      if(k<last&&a[k].key>a[k+1].key){k++;}
      if(a[r].key <=a[k].key){break;}
    swap(&a[k],&a[r]);
    r= k;k=2*r;
}
}

void heapsort( recordtype a[], int n ){
  int i;
  for(i= n/2;i>=1;i--){
    pushdown2(a,i,n);
  }
  for(i=n;i>=2;i--){
    swap(&a[1],&a[i]);
    pushdown2(a,1,i-1);
  }
}


int main(void){

  init_data(a);

  heapsort(a, LIMIT);

  printf("\n[Heap Sort]\n");
  print_record(a, LIMIT);
  
}
