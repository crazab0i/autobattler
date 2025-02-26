#include "system.h"

char getKeyPress() {
	struct termios oldt, newt;
	char ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	newt.c_cc[VMIN] = 1;
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	printf("\033[?25l");
	ch = getchar();
	if (ch == '\033') {
		getchar();
		ch = getchar();
		switch (ch) {
			case 'A': ch = 'w'; break;
			case 'B': ch = 's'; break;
			case 'C': ch = 'd'; break;
			case 'D': ch = 'a'; break;
		}
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}