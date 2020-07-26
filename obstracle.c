#include <stdio.h>
#include <stdlib.h>
#include "obstracle.h"

Hindernis* createHindernis(int x, int y) {
    Hindernis* hindernis = malloc(sizeof(Hindernis));
    hindernis->next = NULL;
    hindernis->xpos = (unsigned int *) malloc(sizeof(unsigned int));
    hindernis->ypos = (unsigned int *) malloc(sizeof(unsigned int));
    *(hindernis->xpos) = x;
    *(hindernis->ypos) = y;
    return hindernis;
}

void delete(Hindernis* hindernis) {
    free(hindernis->xpos);
    free(hindernis->ypos);
    free(hindernis);
}
