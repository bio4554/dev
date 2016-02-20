#ifndef TYPES_H
#define TYPES_H

typedef const char* string;

typedef struct {
	char icon;
	int walk; // TRUE or FALSE
} tile;

typedef struct {
	string name;
	char icon;
	int x;
	int y;
} creature;

#endif
