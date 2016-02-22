#ifndef TYPES_H
#define TYPES_H

typedef const char* string;


typedef struct {
	string name;
	char icon;
	int x;
	int y;
} creature;

typedef struct {
	char icon;
	int walk; // TRUE or FALSE
	int type; // 0 for material, 1 for creature
	creature *cre;
} tile;


#endif
