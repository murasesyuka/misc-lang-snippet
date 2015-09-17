#include <ncurses.h>
#include <tuple>

struct Curses
{
	Curses(){initscr();};
	~Curses(){endwin();};

	auto getMaxYX(){
		int h,w;
		getmaxyx(stdscr, h, w);
		return std::make_tuple(h,w);
	}
};

int main()
{
	{	
		Curses c;
		/* start_color(); */
		/* init_pair(1, COLOR_WHITE, COLOR_BLACK); */
		/* bkgd(COLOR_PAIR(1)); */
		
		/* erase(); */
		
		move(20, 50);
		addstr("Hello Curses.");
	
		auto hw = c.getMaxYX();
		move(std::get<0>(hw), std::get<1>(hw));
		addstr("Hello Center.");
		printw("(%d, %d).",std::get<0>(hw), std::get<1>(hw));
		/* refresh(); */
		
		/* timeout(-1); */

		getch();
	}
	
	
	return 0;
}
