#include <stdio.h>
#include <stdlib.h>

void move(int k, char x, char y, char z){  /* k���̉~�Ղ�x����y�ɓ������iz�͎g��Ȃ����j */
  int i;
  if(k == 1){   /* �I�[���� */
    printf("move #%02d from %c to %c.\n", k, x, y);  /* 1�������Ȃ�΁A��ɏ���Ă��Ȃ��̂Ŏ��R�ɓ������� */
  }else{
    move(k-1, x, z, y);   /* �����̏�ɏ���Ă���~�Ղ��A�g��Ȃ�z���Ɉړ����� */
    for(i = 1; i < k; i++){   /* ��ʂɕ\������ʒu�𒲐� */
      putchar(' ');
    }
    printf("move #%02d from %c to %c.\n", k, x, y);  /* �������g��ړI��(y)�Ɉړ����� */
    move(k-1, z, y, x);
  }
}

void hanoi(int n){
  move(n, 'l', 'c', 'r');
}

int main(int ac, char **av){
  if(ac < 2){  /* �����Ƃ��ĉ~�Ղ̖������w�� */
    fprintf(stderr, "Usage: %s <num>\n", av[0]);
    exit(1);
  }

  hanoi(atoi(av[1]));  /* atoi �� ASCII to Integer�A�܂蕶���𐔒l�ɕϊ� */

  return 0;
}
