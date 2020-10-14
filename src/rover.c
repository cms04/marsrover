#include <stdlib.h>
#include <stdio.h>
#include "rover.h"

Rover *createRover(unsigned short xposition, unsigned short yposition) {
    Rover *rover = (Rover *) malloc(sizeof(Rover));
    rover->xposition = xposition;
    rover->yposition = yposition;
    rover->richtung = UP;
    return rover;
}

void deleteRover(Rover *rover) {
    free(rover);
}

void printRover(Rover *rover) {
    switch (rover->richtung) {
        case UP:
            printf("^");
            break;
        case LEFT:
            printf("<");
            break;
        case RIGHT:
            printf(">");
            break;
        case DOWN:
            printf("v");
            break;
    }
}

int isRoverPosition(Rover *rover, unsigned short xposition, unsigned short yposition) {
    return rover->xposition == xposition && rover->yposition == yposition;
}
