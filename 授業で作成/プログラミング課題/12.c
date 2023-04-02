#include <stdio.h>
#include "eps.h"

int main(void){
	int k;
eps_open("test.ps", 480, 480); 
eps_cmd("240 240 translate"); 
	for(int j = 0;j <= 3;++j) {
		k = j*20;
	for(int i = 1; i <= 4; ++i) {
		eps_num(i*0.1);
		eps_cmd("setgray");
		eps_drawrect(i*20, k, 15, 15);
	}
}
	/*for(int i = 1; i <= 3; ++i) {
		eps_num(i*0.1);
		eps_cmd("setgray");
		eps_drawrect(i+20, i*20, 15, 15);
	}*/
	eps_close();
return 0;
}