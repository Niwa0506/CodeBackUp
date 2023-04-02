#include <stdio.h>
#include "eps.h"

int main(void){
	int k;
eps_open("check.ps", 480, 480); 
eps_cmd("240 240 translate"); 
	for(int j = 0;j <= 4;++j) {
		k = j*15;
	for(int i = 1; i <= 5; ++i) {
		eps_num(i*0.1);
		eps_cmd("setgray");
		//eps_drawrect(i*15, k, 15, 15);
		//eps_fillrect(i*15,k,15,15)
		if((i %2==1 & j%2 ==0 )||(i%2 == 0 && j%2 ==1)){
		eps_fillrect(i*15,k,15,15);}
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