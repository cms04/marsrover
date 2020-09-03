#ifndef OBSTRACLE_H
#define OBSTRACLE_H

typedef struct Hindernis {
    unsigned short* xpos;
    unsigned short* ypos;
    struct Hindernis* next;
} Hindernis;

Hindernis* createHindernis(unsigned short x, unsigned short y);
void delete(Hindernis*);
int equals(Hindernis*, unsigned short x, unsigned short y);

#endif
