#include <stdio.h>
#include <stdlib.h>
#include "rover.h"

Rover* createRover(unsigned short xpos, unsigned short ypos) {
    Rover* rover = (Rover *) malloc(sizeof(Rover));
    rover->xpos = (unsigned short *) malloc(sizeof(unsigned int));
    rover->ypos = (unsigned short *) malloc(sizeof(unsigned int));
    rover->direction = (enum Richtung *) malloc(sizeof(enum Richtung));
    *(rover->xpos) = xpos;
    *(rover->ypos) = ypos;
    *(rover->direction) = NORD;
    return rover;
}

void deleteRover(Rover* rover) {
    free(rover->xpos);
    free(rover->ypos);
    free(rover->direction);
    deleteAll(rover->obstracles);
    free(rover);
}

void moveUpIfPossible(Rover* rover, ObstracleList* list, unsigned short dimy) {
    unsigned short newx = *(rover->xpos), newy;
    if (*(rover->ypos) == 0) {
        newy = dimy - 1;
    } else {
        newy = *(rover->ypos) - 1;
    }
    if (contains(rover->obstracles, newx, newy) == 0) {
        *(rover->ypos) = newy;
    }
}

void moveDownIfPossible(Rover* rover, ObstracleList* list, unsigned short dimy) {
    unsigned short newx = *(rover->xpos), newy = *(rover->ypos) + 1;
    if (newy >= dimy) {
        newy = 0;
    }
    if (contains(rover->obstracles, newx, newy) == 0) {
        *(rover->ypos) = newy;
    }
}

void moveLeftIfPossible(Rover* rover, ObstracleList* list, unsigned short dimx) {
    unsigned short newx, newy = *(rover->ypos);
    if (*(rover->xpos) == 0) {
        newx = dimx - 1;
    } else {
        newx = *(rover->xpos) - 1;
    }
    if (contains(rover->obstracles, newx, newy) == 0) {
        *(rover->xpos) = newx;
    }
}

void moveRightIfPossible(Rover* rover, ObstracleList* list, unsigned short dimx) {
    unsigned short newx = *(rover->xpos) + 1, newy = *(rover->ypos);
    if (newx >= dimx) {
        newx = 0;
    }
    if (contains(rover->obstracles, newx, newy) == 0) {
        *(rover->xpos) = newx;
    }
}

int isRoverPosition(Rover* rover, unsigned short xpos, unsigned short ypos) {
    return (*(rover->xpos) == xpos) && (*(rover->ypos) == ypos);
}

void turnLeft(Rover* rover) {
    if (*(rover->direction) == NORD) {
        *(rover->direction) = WEST;
    } else if (*(rover->direction) == WEST) {
        *(rover->direction) = SUED;
    } else if (*(rover->direction) == SUED) {
        *(rover->direction) = OST;
    } else if (*(rover->direction) == OST) {
        *(rover->direction) = NORD;
    }
}

void turnRight(Rover* rover) {
    if (*(rover->direction) == NORD) {
        *(rover->direction) = OST;
    } else if (*(rover->direction) == OST) {
        *(rover->direction) = SUED;
    } else if (*(rover->direction) == SUED) {
        *(rover->direction) = WEST;
    } else if (*(rover->direction) == WEST) {
        *(rover->direction) = NORD;
    }
}

void moveForwardIfPossible(Rover* rover, ObstracleList* list, unsigned short x, unsigned short y) {
    if (*(rover->direction) == NORD) {
        moveUpIfPossible(rover, list, y);
    } else if (*(rover->direction) == OST) {
        moveRightIfPossible(rover, list, x);
    } else if (*(rover->direction) == SUED) {
        moveDownIfPossible(rover, list, y);
    } else if (*(rover->direction) == WEST) {
        moveLeftIfPossible(rover, list, x);
    }
}

void moveBackIfPossible(Rover* rover, ObstracleList* list, unsigned short x, unsigned short y) {
    if (*(rover->direction) == NORD) {
        moveDownIfPossible(rover, list, y);
    } else if (*(rover->direction) == OST) {
        moveLeftIfPossible(rover, list, x);
    } else if (*(rover->direction) == SUED) {
        moveUpIfPossible(rover, list, y);
    } else if (*(rover->direction) == WEST) {
        moveRightIfPossible(rover, list, x);
    }
}

void doCommand(Rover* rover, char command, unsigned short x, unsigned short y) {
    if (command == 'L') {
        turnLeft(rover);
    } else if (command == 'R') {
        turnRight(rover);
    } else if (command == 'M') {
        moveForwardIfPossible(rover, rover->obstracles, x, y);
    } else if (command == 'B') {
        moveBackIfPossible(rover, rover->obstracles, x, y);
    }
}

char printRover(Rover* rover) {
    switch (*(rover->direction)) {
        case NORD:
            return '^';
        case OST:
            return '>';
        case SUED:
            return 'v';
        case WEST:
            return '<';
        default:
            return ' ';
    }
}
