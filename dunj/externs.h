#ifndef EXTERNS_H
#define EXTERNS_H
#include "types.h"

extern tile cave[MAX_X][MAX_Y];


extern tile FLOOR;
extern tile WALL;
extern weapon weapons[MAX_WEAPONS];
extern armor armors[MAX_ARMORS];

extern creature monsters[MAX_MONSTERS];
extern creature level_cre[MAX_LEVELCRE];
extern node unvisited[MAX_X*MAX_Y];
/* graphics.c */
void init_curses(); //Initialize curses for use
void draw_map(); //Draw the map onto the curses window
int ccheck(int,int,int,tile); //Usesless function, to be removed
void place_tile(int,int,tile); //Place a tile at given coordinates
void draw_ui(creature*);
int is_near(int,int,int,int);
void clearln(int,int);
int next_to(int,int,tile*);

/* generate.c */
void generate(int); //Generate a new dungeon of given type
void fill(int,int,int,int,tile); //Fill an area with given tile
void get_rand_loc(creature*); //Set given creatures location to an empty location

/* creature.c */
void draw_creature(creature*); //Draw given creature onto screen
void cmove(creature*,int); //Move a given creature in a given direction
void attack(creature*, creature*);
void ai_step(creature*,creature*);
void initnodes();
int dirtoc(int,int,int,int);


/* dungeon.c */
void init_cre(); //Initialize level creature stack for use MUST RUN ONCE BEFORE EACH NEW LEVEL
void draw_level_cre(); //Draw all the creatures in the level creature stack onto screen
void add_cre(creature); //Add a creature to the top of the stack
void populate_level(int,int,int); //Numof, type, reset
void process_ai(creature*);

/* rng.c */
void rnd_seed(int);
int rnd(int,int);
int dice(int,int);

/* monsters.c */
void init_monsters();

/* variable.c  */
void setnode(node*, int, int, char);
#endif
