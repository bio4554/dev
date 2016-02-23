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

int dice(int dice, int sides) {
	int num = 0;
	int i;
	for(i = 0; i < dice; i++) {
		num = num + rnd(1, sides);
	}
	return num;
}
