#include <ncurses.h>
#include "config.h"
#include "types.h"
#include "externs.h"
#include <unistd.h>

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
	int score = 0;
	item prize;
	prize.name = "Treasure";
	prize.icon = 'T';
	prize.type = 3;
	prize.found = 0;
	init_curses();
        init_curse_colors();
	generate(1);
	get_rand_loc(&player);
	place_prize(&player, &prize);
	draw_creature(&player);
	draw_fov(&player, 5);
	mvprintw(MAX_Y+2, 20, "Score: %d", score);
	mvprintw(MAX_Y+2, MAX_X+2, " ");
	refresh();
	while((c=getch())!='q' && player.dead != 1) {
		clear(); //NASTY HACK NEEDS TO BE FIXED
		place_tile(player.x, player.y, FLOOR);
		if(c=='w' && prize.found != 1)
			cmove(&player, 1, &prize);
		if(c=='s' && prize.found != 1)
			cmove(&player, 2, &prize);
		if(c=='a' && prize.found != 1)
			cmove(&player, 3, &prize);
		if(c=='d' && prize.found != 1)
			cmove(&player, 4, &prize);
		if(c=='r') {
			generate(1);
			get_rand_loc(&player);
			prize.found = 0;
			place_prize(&player, &prize);
			player.hp = player.maxhp;
		}
		if(c == 't') {
			cellular_automata();
		}
		if(c == 'l' && prize.found != 1) {
			draw_map();
		}
		if(prize.found == 1) {
			draw_map();
			mvprintw(MAX_Y+2, ((MAX_X/2)-25), "You found the treasure. Press R to continue or Q to quit.");
			score++;
		}
		process_ai(&player);
		draw_creature(&player);
		draw_fov(&player, 5);
        	mvprintw(MAX_Y+2, 20, "Score: %d", score);
		mvprintw(MAX_Y+2, MAX_X+2, " ");
		refresh();
	}
	endwin();
	if(player.dead != 0)
		printf("\nYou died!\n\n");
	return 0;
}
