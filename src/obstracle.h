#ifndef OBSTRACLE_H
#define OBSTRACLE_H

#include <stdio.h>

typedef struct Obstracle {
    unsigned short xposition;
    unsigned short yposition;
    struct Obstracle *next;
} Obstracle;

Obstracle *createRandomObstracles(unsigned short maxwidth, unsigned short maxheight);
Obstracle *readObstraclesFromFile(FILE *in);
void deleteObstracles(Obstracle *list);
int contains(Obstracle *list, unsigned short xposition, unsigned short yposition);

#endif
