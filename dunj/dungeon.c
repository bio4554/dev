#include <string.h>
#include "config.h"
#include "types.h"
#include "externs.h"

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
			draw_creature(&level_cre[i]);
		}
	}
}

void add_cre(creature newcre) {
	static int i = 0;
	if(i < MAX_LEVELCRE)
	{
		level_cre[i] = newcre;
		i++;
	}
}

void populate_level(int numof, int type, int reset) {
	static int p = 0; //Location in stack
	int i;
	if(reset == 1)
		p = 0;
	if(type < MAX_MONSTERS)
	{
		for(i = 0; i < numof; i++)
		{
			add_cre(monsters[type]);
			get_rand_loc(&level_cre[p]);
			p++;
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
