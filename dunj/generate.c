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
	do
	{
		x = rnd(0, MAX_X);
		y = rnd(0, MAX_Y);
	}while(cave[x][y].walk < 1);
	if(cave[x][y].walk > 0)
	{
		cre->x = x;
		cre->y = y;
	}
}

void generate(int type) {
	init_cre();
	if(type == 1) {//Cave
		init_cre();
		fill(0, 0, MAX_X, MAX_Y, WALL); 
		fill(MAX_X/2-10, MAX_Y/2-5, MAX_X/2+10, MAX_Y/2+5, FLOOR);
		populate_level(5, 0, 0);
		populate_level(2, 1, 0);
	}
}
