#include "config.h"
#include "types.h"
#include "externs.h"

creature monsters[MAX_MONSTERS] = {
	{"Skeleton", 's', 0, 0, &weapons[0], &armors[0], 20, 20, 2, 0},
	{"Orc", 'o', 0, 0, &weapons[0], &armors[0], 20, 20, 2, 0},
	{"Dragon", 'D', 0, 0, &weapons[1], &armors[1], 100, 100, 1, 0},
};
