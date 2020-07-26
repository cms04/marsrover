#include <stdio.h>
#include <stdlib.h>
#include "obstracle.h"

Hindernis* createHindernis(unsigned short x, unsigned short y) {
    Hindernis* hindernis = malloc(sizeof(Hindernis));
    hindernis->next = NULL;
    hindernis->xpos = (unsigned short *) malloc(sizeof(unsigned short));
    hindernis->ypos = (unsigned short *) malloc(sizeof(unsigned short));
    *(hindernis->xpos) = x;
    *(hindernis->ypos) = y;
    return hindernis;
}

void delete(Hindernis* hindernis) {
    free(hindernis->xpos);
    free(hindernis->ypos);
    free(hindernis);
}

int equals(Hindernis* obs, unsigned short x, unsigned short y) {
    return (*(obs->xpos) == x) && (*(obs->ypos) == y);
}
