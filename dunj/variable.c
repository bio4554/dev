#include "config.h"
#include "types.h"
#include "externs.h"

tile cave[MAX_X][MAX_Y];

tile FLOOR = {' ', 1, 0};
tile WALL = {'#', 0, 0};

creature level_cre[MAX_LEVELCRE];

weapon weapons[MAX_WEAPONS] = {
	{"Sword", "A steel sword", 4, 10},
};

armor armors[MAX_ARMORS] = {
	{"Leather", "Leather armor", 1, 10},
};
