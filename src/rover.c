#include <stdlib.h>
#include <stdio.h>
#include "rover.h"

rover_t *create_rover(unsigned short xposition, unsigned short yposition) {
    rover_t *rover = (rover_t *) malloc(sizeof(rover_t));
    if (rover == NULL) {
        return NULL;
    }
    rover->xposition = xposition;
    rover->yposition = yposition;
    rover->richtung = UP;
    return rover;
}

void delete_rover(rover_t *rover) {
    if (rover != NULL) {
        free(rover);
    }
}

void print_rover(rover_t *rover) {
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

int is_rover_position(rover_t *rover, unsigned short xposition, unsigned short yposition) {
    return rover->xposition == xposition && rover->yposition == yposition;
}

void turn_rover_left(rover_t *rover) {
    switch (rover->richtung) {
        case UP:
            rover->richtung = LEFT;
            break;
        case LEFT:
            rover->richtung = DOWN;
            break;
        case DOWN:
            rover->richtung = RIGHT;
            break;
        case RIGHT:
            rover->richtung = UP;
            break;
    }
}

void turn_rover_right(rover_t *rover) {
    switch (rover->richtung) {
        case UP:
            rover->richtung = RIGHT;
            break;
        case LEFT:
            rover->richtung = UP;
            break;
        case DOWN:
            rover->richtung = LEFT;
            break;
        case RIGHT:
            rover->richtung = DOWN;
            break;
    }
}
