#ifndef ROVER_H
#define ROVER_H

typedef enum {
    UP,
    LEFT,
    RIGHT,
    DOWN
} Richtung;

typedef struct {
    unsigned short xposition;
    unsigned short yposition;
    Richtung richtung;
} Rover;

Rover *createRover(unsigned short xposition, unsigned short yposition);
void deleteRover(Rover *rover);
int isRoverPosition(Rover *rover, unsigned short xposition, unsigned short yposition);
void printRover(Rover *rover);

#endif
