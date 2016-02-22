#include <ncurses.h>
#include <stdio.h>
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

void place_tile(int x1, int y1, tile temp) {
	cave[x1][y1] = temp;
}

int ccheck(int x, int y, int dir, tile check) {
	printf("\n\n %c check %c\n", cave[x][y].icon, check.icon);
	if(dir == 1)
		if(cave[x][y-1].icon == check.icon)
			return 1;
	else if(dir == 2)
		if(cave[x][y+1].icon == check.icon)
			return 1;
	else if(dir == 3)
		if(cave[x-1][y].icon == check.icon)
			return 1;
	else if(dir == 4)
		if(cave[x+1][y].icon == check.icon)
			return 1;
	else
			return 0;


}

void printm(char* str) {
	mvprintw(MAX_Y+2, 2, 
}
