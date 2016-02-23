#include <stdio.h>
#include <ncurses.h>
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
	mvprintw(MAX_Y+2, 2, "%s attacked %s with %s", atk->name, def->name), atk->wep.name;
	int damage = dice(atk->wep.dice, atk->wep.sides);
	mvprintw(MAX_Y+3, 2, "Rolled %dd%d: %d", atk->wep.dice, atk->wep.sides, damage);
	if(damage >= (dice(def->arm.dice, def->arm.sides))) {
		def->hp = def->hp - damage;
		mvprintw(MAX_Y+4, 2, "%s hit for %d damage. Remaining HP: %d", atk->name, damage, def->hp);
	}
}
