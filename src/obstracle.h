#ifndef OBSTRACLE_H
#define OBSTRACLE_H

typedef struct Obstracle {
    unsigned short xposition;
    unsigned short yposition;
    struct Obstracle *next;
} Obstracle;

#endif
