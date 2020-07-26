#include <stdio.h>
#include <stdlib.h>
#include "rover.h"

Rover* createRover(unsigned short xpos, unsigned short ypos) {
    Rover* rover = (Rover *) malloc(sizeof(Rover));
    rover->xpos = (unsigned short *) malloc(sizeof(unsigned int));
    rover->ypos = (unsigned short *) malloc(sizeof(unsigned int));
    rover->direction = (char *) malloc(sizeof(char));
    *(rover->xpos) = xpos;
    *(rover->ypos) = ypos;
    *(rover->direction) = '^';
    return rover;
}

void deleteRover(Rover* rover) {
    free(rover->xpos);
    free(rover->ypos);
    free(rover->direction);
    free(rover);
}

int isRoverPosition(Rover* rover, unsigned short xpos, unsigned short ypos) {
    return (*(rover->xpos) == xpos) && (*(rover->ypos) == ypos);
}
