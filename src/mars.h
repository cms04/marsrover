#ifndef MARS_H
#define MARS_H

typedef struct {
    unsigned short width;
    unsigned short height;
    Rover *rover;
    Obstracle *obstracles;
} Mars;

#endif
