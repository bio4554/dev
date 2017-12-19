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
	player.dead = 0;
    	player.hp = 200;
    	player.maxhp = 200;
	player.x = MAX_X/2;
	player.y = MAX_Y/2;
	player.wep = &weapons[0];
	player.arm = &armors[0];
	player.color = 1;
	init_curses();
	init_curse_colors();
	generate(1);
//	initnodes();
	//dirtoc(0,0,0,0);
	get_rand_loc(&player);
	draw_creature(&player);
	draw_level_cre();
	draw_map();
	draw_ui(&player);
	refresh();
	while((c=getch())!='q' && player.dead != 1) {
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
		if(c=='r') {
			init_curses();
			generate(1);
			get_rand_loc(&player);
			player.hp = player.maxhp;
		}
		process_ai(&player);
		draw_creature(&player);
		draw_level_cre();
		draw_map();
        	draw_ui(&player);
		refresh();
	}
	
	endwin();
	if(player.dead != 0)
		printf("\nYou died!\n\n");
	return 0;
}
