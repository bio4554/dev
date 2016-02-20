#include "config.h"
#include "types.h"
#include "externs.h"

void draw_creature(creature *cre) {
	tile cretemp = {cre->icon, 0};
	cave[cre->x][cre->y] = cretemp;
}
