#ifndef ROVER_H
#define ROVER_H

#include "obstraclelist.h"

typedef enum { NORD, OST, SUED, WEST } Richtung;

typedef struct {
    unsigned short* xpos;
    unsigned short* ypos;
    Richtung* direction;
    ObstracleList* obstracles;
} Rover;

Rover* createRover(unsigned short xpos, unsigned short ypos);
void deleteRover(Rover*);
int isRoverPosition(Rover*, unsigned short xpos, unsigned short ypos);
void doCommand(Rover*, char command, unsigned short xpos, unsigned short ypos);
char printRover(Rover*);

#endif
