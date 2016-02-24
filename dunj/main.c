#include <ncurses.h>
#include "config.h"
#include "types.h"
#include "externs.h"

int main()
{
	char c;
	rnd_seed(0);
	creature player;
	player.name = "Player";
	player.icon = '@';
    player.hp = 100;
    player.maxhp = 100;
	player.x = MAX_X/2;
	player.y = MAX_Y/2;
	player.wep = &weapons[0];
	player.arm = &armors[0];
	init_curses();
	generate(1);
	draw_creature(&player);
	draw_level_cre();
	draw_map();
	refresh();
	while((c=getch())!='q') {
		clear(); //NASTY HACK NEEDS TO BE FIXED
		place_tile(player.x, player.y, FLOOR);
		if(c=='w')
			cmove(&player, 1);
		if(c=='s')
			cmove(&player, 2);
		if(c=='a')
			cmove(&player, 3);
		if(c=='d')
			cmove(&player, 4);
		process_ai(&player);
		draw_creature(&player);
		draw_level_cre();
		draw_map();
        draw_ui(&player);
		refresh();
	}
	endwin();
	return 0;
}
