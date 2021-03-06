#include "config.h"
#include "types.h"
#include "externs.h"

tile cave[MAX_X][MAX_Y];


tile FLOOR = {'.', 1, 0, 3};
tile WALL = {'|', 0, 0, 5};
tile SPACE = {' ', 0, 0, 6};

creature level_cre[MAX_LEVELCRE];

weapon weapons[MAX_WEAPONS] = {
	{"Sword", "A steel sword", 2, 6},
	{"Fire spew", "A breath of fire", 2, 10},
	{"Golden Sword", "A golden sword", 2, 8},
};

armor armors[MAX_ARMORS] = {
	{"Leather", "Leather armor", 1, 10},
	{"Steel", "Steel armor", 2, 10},
	{"Scales", "Scale plates", 1, 20},
};

node unvisited[MAX_X*MAX_Y];

void setnode(node *n, int x, int y, char c) {
	n->x = x;
	n->y = y;
	n->icon = c;
}
