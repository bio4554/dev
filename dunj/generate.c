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

void generate(int type) {
	tile wall = {'#', 0};
	tile floor = {' ', 1};
	if(type == 1) {//Cave
		fill(0, 0, MAX_X, MAX_Y, wall); 
		fill(MAX_X/2-10, MAX_Y/2-5, MAX_X/2+10, MAX_Y/2+5, floor);
	}
}
