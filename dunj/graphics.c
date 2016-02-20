#include <ncurses.h>
#include "config.h"
#include "types.h"
#include "externs.h"

void init_curses() {
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
}

void draw_map() {
	for(int x = 0; x < MAX_X; x++)
		for(int y = 0; y < MAX_Y; y++)
			mvaddch(y, x, cave[x][y].icon);
}

int ccheck(int x, int y, int dir, tile check) {
	if(cave[x][y] == check)
		return true;
	else
		return false;
}
