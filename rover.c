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

void moveUpIfPossible(Rover* rover, ObstracleList* list, unsigned short dimy) {
    unsigned short newx = *(rover->xpos), newy = *(rover->ypos) - 1;
    if (newy < 0) {
        newy = dimy - 1;
    }
    if (contains(list, newx, newy) == 0) {
        *(rover->ypos) = newy;
    }
}

void moveDownIfPossible(Rover* rover, ObstracleList* list, unsigned short dimy) {
    unsigned short newx = *(rover->xpos), newy = *(rover->ypos) + 1;
    if (newy >= dimy) {
        newy = 0;
    }
    if (contains(list, newx, newy) == 0) {
        *(rover->ypos) = newy;
    }
}

void moveLeftIfPossible(Rover* rover, ObstracleList* list, unsigned short dimx) {
    unsigned short newx = *(rover->xpos) - 1, newy = *(rover->ypos);
    if (newx < 0) {
        newx = dimx - 1;
    }
    if (contains(list, newx, newy) == 0) {
        *(rover->xpos) = newx;
    }
}

void moveRightIfPossible(Rover* rover, ObstracleList* list, unsigned short dimx) {
    unsigned short newx = *(rover->xpos) + 1, newy = *(rover->ypos);
    if (newy >= dimx) {
        newy = 0;
    }
    if (contains(list, newx, newy) == 0) {
        *(rover->xpos) = newx;
    }
}

int isRoverPosition(Rover* rover, unsigned short xpos, unsigned short ypos) {
    return (*(rover->xpos) == xpos) && (*(rover->ypos) == ypos);
}

void turnLeft(Rover* rover) {
    if (*(rover->direction) == '^') {
        *(rover->direction) = '<';
    } else if (*(rover->direction) == '<') {
        *(rover->direction) = 'v';
    } else if (*(rover->direction) == 'v') {
        *(rover->direction) = '>';
    } else if (*(rover->direction) == '>') {
        *(rover->direction) = '^';
    }
}

void turnRight(Rover* rover) {
    if (*(rover->direction) == '^') {
        *(rover->direction) = '>';
    } else if (*(rover->direction) == '>') {
        *(rover->direction) = 'v';
    } else if (*(rover->direction) == 'v') {
        *(rover->direction) = '<';
    } else if (*(rover->direction) == '<') {
        *(rover->direction) = '^';
    }
}

void moveForwardIfPossible(Rover* rover, ObstracleList* list, unsigned short x, unsigned short y) {
    if (*(rover->direction) == '^') {
        moveUpIfPossible(rover, list, y);
    } else if (*(rover->direction) == '>') {
        moveRightIfPossible(rover, list, x);
    } else if (*(rover->direction) == 'v') {
        moveDownIfPossible(rover, list, y);
    } else if (*(rover->direction) == '<') {
        moveLeftIfPossible(rover, list, x);
    }
}

void moveBackIfPossible(Rover* rover, ObstracleList* list, unsigned short x, unsigned short y) {
    if (*(rover->direction) == '^') {
        moveDownIfPossible(rover, list, y);
    } else if (*(rover->direction) == '>') {
        moveLeftIfPossible(rover, list, x);
    } else if (*(rover->direction) == 'v') {
        moveUpIfPossible(rover, list, y);
    } else if (*(rover->direction) == '<') {
        moveRightIfPossible(rover, list, x);
    }
}

void doCommand(Rover* rover, ObstracleList* lst, char command, unsigned short x, unsigned short y) {
    if (command == 'L') {
        turnLeft(rover);
    } else if (command == 'R') {
        turnRight(rover);
    } else if (command == 'M') {
        moveForwardIfPossible(rover, lst, x, y);
    } else if (command == 'B') {
        moveBackIfPossible(rover, lst, x, y);
    }
}
