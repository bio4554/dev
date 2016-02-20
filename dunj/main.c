#include <ncurses.h>
#include "config.h"
#include "types.h"
#include "externs.h"

int main()
{
	creature player;
	player.name = "Player";
	player.icon = '@';
	player.x = MAX_X/2;
	player.y = MAX_Y/2;
	init_curses();
	generate(1);
	draw_creature(&player);
	draw_map();
	refresh();
	getch();
	endwin();
	return 0;
}
