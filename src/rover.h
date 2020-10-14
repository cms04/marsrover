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
}

#endif
