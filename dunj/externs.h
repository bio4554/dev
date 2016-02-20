#ifndef EXTERNS_H
#define EXTERNS_H
#include "types.h"

extern tile cave[MAX_X][MAX_Y];

/* graphics.c */
void init_curses();
void draw_map();

/* generate.c */
void generate(int);
void fill(int,int,int,int,tile);

/* creature.c */
void draw_creature(creature*);
#endif
