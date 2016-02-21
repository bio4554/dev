#include <stdio.h>
#include "config.h"
#include "types.h"
#include "externs.h"

void draw_creature(creature *cre) {
	tile cretemp = {cre->icon, 0};
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
}
