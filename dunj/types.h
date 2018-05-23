#ifndef TYPES_H
#define TYPES_H


typedef struct {
	const char* name;
	const char* desc;
	int dice;
	int sides;
} weapon;

typedef struct {
	const char* name;
	const char* desc;
	int dice;
	int sides;
} armor;

typedef struct {
	const char* name;
	char icon;
	int type; //0 armor, 1 weapon
	int index;
	int x;
	int y;
	int found;
} item;

typedef struct {
	const char* name;
	char icon;
	int x;
	int y;
	weapon *wep;
	armor *arm;
	int hp;
	int maxhp;
	int color;
	int dead;
} creature;

typedef struct {
	char icon;
	int walk; // TRUE or FALSE
	int type; // 0 for material, 1 for creature
	int color;
	creature *cre;
	int seen;
} tile;

typedef struct {
	int x;
	int y;
	char icon;
} node;


#endif
