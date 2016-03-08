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

void initnodes() {
	int i = 0;
	for(int x = 0; x < MAX_X; x++) {
		for(int y = 0; y < MAX_Y; y++) {
			setnode(&unvisited[i], x, y, cave[x][y].icon);
			i++;
		}
	}
}

int dirtoc(int x1, int y1, int x2, int y2) {
	for(int i = 0; i < MAX_X*MAX_Y; i++) {
	printf("\n%d, %d, %c", unvisited[i].x, unvisited[i].y, unvisited[i].icon);
	}	
	return 0;
}
