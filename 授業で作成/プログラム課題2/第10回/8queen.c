/*
  8王妃問題を解く
 */

#include <stdio.h>

int  flag_a[8];   /* 各行に王妃が配置済みか */
int  flag_b[15];   /* ／対角線に王妃が配置済みか */
int  flag_c[15];   /* ＼対角線に王妃が配置済みか */
int  pos[8];      /* 各列の王妃の位置 */

int count = 0;   /* 出力した配置数をカウント */

/*--- 盤面（各列の王妃の位置）を出力 ---*/
void print(void)
{
  int i;

  printf("[%2d]", ++count);
  for(i = 0; i < 8; i++)
    printf("%2d", pos[i]);
  putchar('\n');
}

/*--- i列目の適当な位置に王妃を配置 ---*/
void set(int i)
{
  int  j;

  for(j = 0; j < 8; j++) {
    if (!flag_a[j] && !flag_b[i+j] &&!flag_c[i-j+7]) {
      pos[i] = j;
      if (i == 7)   
	     print();
      else {
	flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
	set( i+1 );
	flag_a[j] = flag_b[i+j] = flag_c[i-j+7] = 0;
      }
    }
  }
}

int main(void)
{
  int i;

  for(i = 0; i < 8; i++)  /* flag_aを初期化 */
    flag_a[i] = 0;
  for(i = 0; i < 15; i++) /* flag_bとflag_cを初期化 */
    flag_b[i] = flag_c[i] = 0;

  set(0);

  return (0);
}
