#include <ncurses.h>
#include "config.h"
#include "types.h"
#include "externs.h"
#include <unistd.h>


int main(int argc, char *argv[])
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
	player.wep = &weapons[2];
	player.arm = &armors[0];
	player.color = 1;
	int dif = 0;
	printf("\nHow to play: Use WASD to move around the cave and search for the treasure. Press P to quit. \n\nChoose the difficulty: \n 1. Easy: Step tracking, flashlight (Press L to use flashlight)\n 2. Medium: Step tracking, no flashlight\n 3. Hard: No step tracking, no flashlight\n\n>");
//	fgets(dif, 1, stdin);
//	printf("%d", argv[0]);
        //dif = getchar();
	scanf("%d", &dif);
	int score = 0;
	item prize;
	prize.name = "Treasure";
	prize.icon = 'T';
	prize.type = 3;
	prize.found = 0;
	int usedLight = 0;
	init_curses();
	int prizegot = 0;
        init_curse_colors();
	generate(1);
	get_rand_loc(&player);
	place_prize(&player, &prize);
	draw_creature(&player);
	draw_fov(&player, 5);
	mvprintw(MAX_Y+2, 20, "Score: %d", score);
	mvprintw(MAX_Y+2, MAX_X+2, " ");
	refresh();
	while((c=getch())!='p' && player.dead != 1) {
		//clear(); //NASTY HACK NEEDS TO BE FIXED
		if(usedLight == 1 || dif == 3) {
			clear();
			usedLight = 0;
		}
		place_tile(player.x, player.y, FLOOR);
		clear_level_cre();
		//draw_level_cre();
		if(c=='w' && prize.found != 1)
			cmove(&player, 1);
		if(c=='s' && prize.found != 1)
			cmove(&player, 2);
		if(c=='a' && prize.found != 1)
			cmove(&player, 3);
		if(c=='d' && prize.found != 1)
			cmove(&player, 4);
		if(c=='r') {
//			init_curses();
			clear();
			generate(1);
			get_rand_loc(&player);
			prize.found = 0;
			prizegot = 0;
			place_prize(&player, &prize);
			player.hp = player.maxhp;
		}


		if(c == 't') {
			cellular_automata();
		}

		if(c == 'l' && prize.found != 1 && dif == 1) {
			draw_map(1);
			usedLight = 1;
		}

		if(prize.found == 1) {
			draw_map(1);
			mvprintw(MAX_Y+2, ((MAX_X/2)-25), "You found the treasure. Press R to continue or P to quit.");
			if(prizegot == 0) {
			score++;
			prizegot = 1;
			}
		}
			process_ai(&player);
		draw_creature(&player);
		draw_level_cre();
		if(dif != 3)
		draw_map(0);
		draw_fov(&player, 5);
		//draw_map();
       	draw_ui(&player);
        	mvprintw(MAX_Y+2, 20, "Score: %d", score);
		mvprintw(MAX_Y+2, MAX_X+2, " ");
		refresh();
	}

	
	
	endwin();
	if(player.dead != 0)
		printf("\nYou died!\n\n");
	return 0;
}
