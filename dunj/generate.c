#include <stdio.h>
#include "config.h"
#include "types.h"
#include "externs.h"

void fill(int x1, int y1, int x2, int y2, tile temp) {
	if(x2 < x1) 
	{
		int tmp = x2;
		x2 = x1;
		x1 = tmp;
	}
	if(y2 < y1) 
	{
		int tmp = y2;
		y2 = y1;
		y1 = tmp;	
	}
	for(int x = x1; x < x2; x++)
		for(int y = y1; y < y2; y++)
			cave[x][y] = temp;
}

void get_rand_loc(creature *cre) {
	int x, y;
	creature *temp = cre;
	do
	{
		x = rnd(0, RES_X);
		y = rnd(0, RES_Y);
	}while(cave[x][y].walk < 1);
	if(cave[x][y].walk > 0)
	{
		cre->x = x;
		cre->y = y;
	}
}

void move_item(int dir, item *thing) {
	if(dir == 1) {
		if(cave[thing->x][thing->y-1].walk == 1)
		thing->y = thing->y - 1;
	} else if(dir == 2) {
		if(cave[thing->x-1][thing->y].walk == 1)
		thing->x = thing->x - 1;
	} else if(dir == 3) {
		if(cave[thing->x+1][thing->y].walk == 1)
		thing->x = thing->x + 1;
	} else {
		if(cave[thing->x][thing->y+1].walk == 1)
		thing->y = thing->y + 1;
	}
}

//  1
// 2 3
//  4




void place_prize(creature *player, item *prize) {
	int x;
	int y;
	int fail = 0;
	do {
		int dir = rnd(1, 4);
		if(dir == 1) {
			x = player->x;
			y = player->y - 1;
		} else if(dir == 2) {
			x = player->x - 1;
			y = player->y;
		} else if(dir == 3) {
			x = player->x + 1;
			y = player->y;
		} else {
			x = player->x;
			y = player->y + 1;
		}
		fail++;
	} while(cave[x][y].walk != 1 && fail < 1000);	



	
	prize->x = x;
	prize->y = y;
	for(int i = 0; i < 2000; i++) {
		int dir = rnd(1, 4);
		move_item(dir, prize);
	}

	tile temp = {prize->icon, 0, 3, 1}; 

	cave[prize->x][prize->y] = temp;
}

void generate(int type) {
	init_cre();
	populate_level(0, 0, 1);
	int tx, ty;
	tx = 0;
	ty = 0;

	//if(type == 1) {
	
	for(int ix = 0; ix < RES_X; ix++) {
		for(int iy = 0; iy < RES_Y; iy++) {
			int tc = rnd(0, 2);
			if(tc == 0) {
				cave[ix][iy] = WALL;
			} else {
				cave[ix][iy] = FLOOR;
			}
		}
	}
	for(int i = 0; i < 3; i++) {
		cellular_automata();
	}	
	fill(0, 0, 3, RES_Y, WALL);
	fill(0, 0, RES_X, 2, WALL);
	fill(0, RES_Y, RES_X, RES_Y-2, WALL);
	fill(RES_X-3, RES_Y, RES_X, 0, WALL);
	
	populate_level(5, 0, 0);
	populate_level(2, 1, 0);
	populate_level(1, 2, 0);
	populate_level(1, 3, 0);
/*
 * 	815
 * 	4 2
 * 	736
 */
}



void cellular_automata() {
	for(int iy = 0; iy < RES_Y; iy++) {
		for(int ix = 0; ix < RES_X; ix++) {
			int count = 0;
			for(int dc = 1; dc < 9; dc++) {
				count = count + ccheck(ix, iy, dc, WALL);
			}
			if(cave[ix][iy].icon == WALL.icon) {
				if(count < 4) {
					cave[ix][iy] = FLOOR;
				}
			} else {
				if(count >= 5) {
					cave[ix][iy] = WALL;
				}
			}
		}
	}

}
