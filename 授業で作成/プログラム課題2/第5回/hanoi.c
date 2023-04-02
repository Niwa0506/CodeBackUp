#include <stdio.h>
#include <stdlib.h>

void move(int k, char x, char y, char z){  /* k枚の円盤をxからyに動かす（zは使わない軸） */
  int i;
  if(k == 1){   /* 終端条件 */
    printf("move #%02d from %c to %c.\n", k, x, y);  /* 1枚だけならば、上に乗っていないので自由に動かせる */
  }else{
    move(k-1, x, z, y);   /* 自分の上に乗っている円盤を、使わないz軸に移動する */
    for(i = 1; i < k; i++){   /* 画面に表示する位置を調整 */
      putchar(' ');
    }
    printf("move #%02d from %c to %c.\n", k, x, y);  /* 自分自身を目的軸(y)に移動する */
    move(k-1, z, y, x);
  }
}

void hanoi(int n){
  move(n, 'l', 'c', 'r');
}

int main(int ac, char **av){
  if(ac < 2){  /* 引数として円盤の枚数を指定 */
    fprintf(stderr, "Usage: %s <num>\n", av[0]);
    exit(1);
  }

  hanoi(atoi(av[1]));  /* atoi は ASCII to Integer、つまり文字を数値に変換 */

  return 0;
}
