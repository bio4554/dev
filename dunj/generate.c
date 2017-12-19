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

void generate(int type) {
/*	init_cre();
	int tx, ty;
	int i;
	if(type == 1) {//Cave
		init_cre();
		fill(0, 0, RES_X, RES_Y, WALL); 
		fill(RES_X/2-10, RES_Y/2-5, RES_X/2+10, RES_Y/2+5, FLOOR);
		for(i = 0; i < MAX_DUNG; i++) {	
			do {
				tx = rnd(0, RES_X);
				ty = rnd(0, RES_Y);
			} while(next_to(tx, ty, &WALL) != 1);
		}
		populate_level(5, 0, 0);
		populate_level(2, 1, 0);
	}
*/
	init_cre();
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
	for(int i = 0; i < 2; i++) {
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
	fill(0, 0, 5, RES_Y, WALL);
	fill(0, 0, RES_X, 3, WALL);
	fill(0, RES_Y, RES_X, RES_Y-3, WALL);
	fill(RES_X-5, RES_Y, RES_X, 0, WALL);
	
	populate_level(5, 0, 0);
	populate_level(2, 1, 0);
/*
 * 	815
 * 	4 2
 * 	736
 */
}
