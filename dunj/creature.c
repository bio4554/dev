#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include "config.h"
#include "types.h"
#include "externs.h"

void draw_creature(creature *cre) {
	tile cretemp = {cre->icon, 0, 1, cre};
	cave[cre->x][cre->y] = cretemp;
}

void cmove(creature *cre, int dir) {
	int x = cre->x;
	int y = cre->y;
	if(dir == 1)
		if(cave[x][y-1].walk == 1)
			cre->y--;
	if(dir == 2)
		if(cave[x][y+1].walk == 1)
			cre->y++;
	if(dir == 3)
		if(cave[x-1][y].walk == 1)
			cre->x--;
	if(dir == 4)
		if(cave[x+1][y].walk == 1)
			cre->x++;

	if(dir == 1)
		if(cave[x][y-1].type == 1)
			attack(cre, cave[x][y-1].cre);
	if(dir == 2)
		if(cave[x][y+1].type == 1)
			attack(cre, cave[x][y+1].cre);
	if(dir == 3)
		if(cave[x-1][y].type == 1)
			attack(cre,cave[x-1][y].cre);
	if(dir == 4)
		if(cave[x+1][y].type == 1)
			attack(cre, cave[x+1][y].cre);

}

void attack(creature *atk, creature *def) {
	if(strncmp(atk->name, "Player", 6) != 0)
	{
		mvprintw(MAX_Y+2, 2, "%s attacked %s with %s", atk->name, def->name, atk->wep->name);
		int damage = dice(atk->wep->dice, atk->wep->sides);
		mvprintw(MAX_Y+3, 2, "Rolled %dd%d: %d", atk->wep->dice, atk->wep->sides, damage);
		if(damage >= (dice(def->arm->dice, def->arm->sides))) {
			def->hp = def->hp - damage;
			mvprintw(MAX_Y+4, 2, "%s hit for %d damage. Remaining HP: %d", atk->name, damage, def->hp);
		}
	} else if(strncmp(atk->name, "Player", 6) == 0)
	{
		mvprintw(MAX_Y/2+8, MAX_X+2, "You attack the %s with a %s", def->name, atk->wep->name);
		int damage = dice(atk->wep->dice, atk->wep->sides);
		mvprintw(MAX_Y/2+9, MAX_X+2, "Rolled %dd%d: %d", atk->wep->dice, atk->wep->sides, damage);
		if(damage >= (dice(def->arm->dice, def->arm->sides))) {
			def->hp = def->hp - damage;
			mvprintw(MAX_Y/2+10, MAX_X+2, "%s hit for %d damage. Remaining HP of attacked creature: %d", atk->name, damage, def->hp);
		}
	}
}	

void ai_step(creature *cre, creature *player) {
	int choice; //Choice for creature, move or attack
	if(is_near(cre->x, cre->y, player->x, player->y) > 0) //Player is next to cre
		choice = 1;
	else
		choice = 0;

	if(choice == 1) { //Attack player
		attack(cre, player);
	}
	if(choice == 0) { //Move to player
		
	}
}

int dirtoc(int x1, int y1, int x2, int y2) {
	coord openlist[MAX_Y*MAX_X];
	coord closelist[MAX_Y*MAX_X];
	int i, oi, h;
	oi = 0;
	
	openlist[oi] = {x1, y1, 0};
	for(i = 1; i < 4; i++) {
		if(i == 1) //Dir up
			if(cave[x1][y1-1].walk == 1) {
				oi++;
				openlist[oi] = {x1, y1-1, openlist[oi-1].cost+1};
			}
		else if(i == 2) //Dir down
			if(cave[x1][y1+1].walk == 1) {
				oi++;
				openlist[oi] = {x1, y1+1, openlist[oi-1].cost+1};
			}
		else if(i == 3) //Dir left
			if(cave[x1-1][y1].walk == 1) {
				oi++;
				openlist[oi] = {x1-1, y1, openlist[oi-1].cost+1};
			}
		else if(i == 4) //Dir right
			if(cave[x1+1][y1].walk == 1) {
				oi++;
				openlist[oi] = {x1+1, y1, openlist[oi-1].cost+1};
			}
	}
	
	return 0;
}
