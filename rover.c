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

void moveUpIfPossible(Rover* rover, ObstracleList* list) {
    if (contains(list, *(rover->xpos), *(rover->ypos) - 1) == 0) {
        *(rover->ypos) = *(rover->ypos) - 1;
    }
}

void moveDownIfPossible(Rover* rover, ObstracleList* list) {
    if (contains(list, *(rover->xpos), *(rover->ypos) + 1) == 0) {
        *(rover->ypos) = *(rover->ypos) - 1;
    }
}

void moveLeftIfPossible(Rover* rover, ObstracleList* list) {
    if (contains(list, *(rover->xpos) - 1, *(rover->ypos)) == 0) {
        *(rover->xpos) = *(rover->xpos) - 1;
    }
}

void moveRightIfPossible(Rover* rover, ObstracleList* list) {
    if (contains(list, *(rover->xpos) + 1, *(rover->ypos)) == 0) {
        *(rover->xpos) = *(rover->xpos) + 1;
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

void moveForwardIfPossible(Rover* rover, ObstracleList* list) {
    if (*(rover->direction) == '^') {
        moveUpIfPossible(rover, list);
    } else if (*(rover->direction) == '>') {
        moveRightIfPossible(rover, list);
    } else if (*(rover->direction) == 'v') {
        moveDownIfPossible(rover, list);
    } else if (*(rover->direction) == '<') {
        moveLeftIfPossible(rover, list);
    }
}

void moveBackIfPossible(Rover* rover, ObstracleList* list) {
    if (*(rover->direction) == '^') {
        moveDownIfPossible(rover, list);
    } else if (*(rover->direction) == '>') {
        moveLeftIfPossible(rover, list);
    } else if (*(rover->direction) == 'v') {
        moveUpIfPossible(rover, list);
    } else if (*(rover->direction) == '<') {
        moveRightIfPossible(rover, list);
    }
}

void doCommand(Rover* rover, ObstracleList* list, char command) {
    if (command == 'L') {
        turnLeft(rover);
    } else if (command == 'R') {
        turnRight(rover);
    } else if (command == 'M') {
        moveForwardIfPossible(rover, list);
    } else if (command == 'B') {
        moveBackIfPossible(rover, list);
    }
}
