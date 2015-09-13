#include <ncurses.h>

struct Curses
{
	Curses(){initscr();};
	~Curses(){endwin();};
};

int main()
{
	{	
		Curses init;
		/* start_color(); */
		/* init_pair(1, COLOR_WHITE, COLOR_BLACK); */
		/* bkgd(COLOR_PAIR(1)); */
		
		/* erase(); */
		
		move(20, 50);
		addstr("Hello Curses.");
		
		/* refresh(); */
		
		/* timeout(-1); */

		getch();
	}
	
	
	return 0;
}
