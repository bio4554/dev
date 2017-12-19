#include "config.h"
#include "types.h"
#include "externs.h"

creature monsters[MAX_MONSTERS] = {
	{"Skeleton", 's', 0, 0, &weapons[0], &armors[0], 100, 100, 2},
	{"Orc", 'o', 0, 0, &weapons[0], &armors[0], 100, 100, 2},
};
