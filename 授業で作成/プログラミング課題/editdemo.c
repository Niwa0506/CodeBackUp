#include <ncurses.h>
#include <stdlib.h>

int main(void) {
	initscr(); noecho(); cbreak(); 
	system("stty raw"); clear(); move(10, 10); addstr("press any key");move(11,10);refresh();
	int ch = getch(); addstr("1:Hello.");move(12,10);refresh();
		ch = getch(); addstr("2:Hello.");move(13,10);refresh(); 
		ch = getch(); move(12,13);delch();move(13,10);addstr("1:you mistake.");move(14,10);refresh(); 
		ch = getch(); addstr("2:Don't take my 'e'.");move(12,13);insch('e');refresh();
		ch = getch();move(13,10);clrtoeol();move(15,10);addstr("1:shut up");
		ch = getch(); endwin(); 
		return 0;
}