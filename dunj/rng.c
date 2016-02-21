#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "types.h"
#include "externs.h"

void rnd_seed(int seed) {
	srand(time(NULL));
}

int rnd(int lower, int upper) {
	int num = ((rand() % upper) + lower);
	return num;
}
