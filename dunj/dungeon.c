#include <string.h>
#include "config.h"
#include "types.h"
#include "externs.h"

int mp;

void init_cre() {
	creature blank = {"BLANK"};
	for(int i = 0; i < MAX_LEVELCRE; i++)
		level_cre[i] = blank;
}

void draw_level_cre() {
	for(int i = 0; i < MAX_LEVELCRE; i++)
	{
		if(strncmp(level_cre[i].name, "BLANK", 5) != 0)
		{
			if(level_cre[i].dead == 0) {
				draw_creature(&level_cre[i]);
			} else {
				place_tile(level_cre[i].x,level_cre[i].y,FLOOR);
				level_cre[i].name = "BLANK";
			}
		}
	}
}

void add_cre(creature newcre) {
	if(mp < MAX_LEVELCRE)
	{
		level_cre[mp] = newcre;
	}
}

void collect_prize(item *prize) {
	prize->found = 1;
}

void populate_level(int numof, int type, int reset) {
//	static int p = 0; //Location in stack
	int i;
	if(reset == 1)
		mp = 0;
//	printf("%d\n",mp);
	if(type < MAX_MONSTERS)
	{
		for(i = 0; i < numof; i++)
		{
			add_cre(monsters[type]);
			get_rand_loc(&level_cre[mp]);
			mp++;
		}
	}
}

void process_ai(creature *player) {
	int i;
	for(i = 0; i < MAX_LEVELCRE; i++)
	{
		if(strncmp(level_cre[i].name, "BLANK", 5) != 0)
			ai_step(&level_cre[i], player);	
	}
}
