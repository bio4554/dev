#include <ncurses.h>
#include <stdio.h>
#include <string.h>
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

void clearln(int x, int y) {
	int i = 0;
	for(i = x; i < MAX_X; i++)
		mvprintw(y, x, " ");
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
	mvprintw(MAX_Y+2, 2, "%s", str); 
}

void draw_ui(creature *cre) {
    mvprintw(MAX_Y/2, MAX_X+5, "HP: %d out of %d", cre->hp, cre->maxhp);
    mvprintw(MAX_Y/2+1, MAX_X+5, "Weapon: %s", cre->wep->name);
    mvprintw(MAX_Y/2+2, MAX_X+5, "Damage Roll: %dd%d", cre->wep->dice, cre->wep->sides);
    mvprintw(MAX_Y/2+3, MAX_X+5, "Armor: %s", cre->arm->name);
}

int is_near(int x1, int y1, int x2, int y2) {
	if(x1+1 == x2 && y1 == y2)
		return 4;
	if(x1-1 == x2 && y1 == y2)
		return 3;
	if(x1 == x2 && y1+1 == y2)
		return 2;
	if(x1 == x2 && y1-1 == y2)
		return 1;
	return 0;
}
