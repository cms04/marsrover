#ifndef OBSTRACLE_H
#define OBSTRACLE_H

#include <stdio.h>

typedef struct Obstracle {
    unsigned short xposition;
    unsigned short yposition;
    struct Obstracle *next;
} Obstracle;

typedef struct {
    Obstracle **list;
    unsigned short maxheight;
    unsigned short maxwidth;
    unsigned short index;
} Parameter;

Obstracle **createRandomObstracles(unsigned short maxwidth, unsigned short maxheight);
Obstracle **readObstraclesFromFile(FILE *in, unsigned short maxheight);
void deleteObstracles(Obstracle **list, unsigned short maxheight);
int contains(Obstracle *list, unsigned short xposition, unsigned short yposition);
void *createObstracleList(void *parameter);

#endif
