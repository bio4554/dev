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
		if(level_cre[i].name != "BLANK")
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
