#include <stdlib.h>
#include <time.h>
#include "obstracle.h"

static Obstracle *createNewObstracle(unsigned short xposition, unsigned short yposition);
static Obstracle *addHindernisToList(Obstracle *list, Obstracle *new);

Obstracle **createRandomObstracles(unsigned short maxwidth, unsigned short maxheight) {
    Obstracle **list = (Obstracle **) malloc(maxheight * sizeof(Obstracle *));
    for (unsigned short i = 0; i < maxheight; i++) {
        *(list + i) = NULL;
    }
    Obstracle *new = NULL;
    time_t t;
    srand((unsigned) time(&t));
    for (unsigned short i = 0; i < maxheight; i++) {
        for (unsigned short j = 0; j < maxwidth; j++) {
            if (rand() % 5 == 0 && (j != maxwidth / 2 || i != maxheight / 2)) {
                new = createNewObstracle(j, i);
                *(list + i) = addHindernisToList(*(list + i), new);
            }
        }
    }
    return list;
}

Obstracle **readObstraclesFromFile(FILE *in, unsigned short maxheight) {
    Obstracle **list = (Obstracle **) malloc(maxheight * sizeof(Obstracle *));
    for (unsigned short i = 0; i < maxheight; i++) {
        *(list + i) = NULL;
    }
    Obstracle *new = NULL;
    unsigned short coordinates[2] = {0, 0};
    while (fread(&coordinates, sizeof(unsigned short), 2, in) == 2) {
        new = createNewObstracle(coordinates[0], coordinates[1]);
        *(list + coordinates[1]) = addHindernisToList(*(list + coordinates[1]), new);
    }
    return list;
}

void deleteObstracles(Obstracle **lists, unsigned short maxheight) {
    for (unsigned short i = 0; i < maxheight; i++) {
        Obstracle *tmp, *list = *(lists + i);
        while (list != NULL) {
            tmp = list;
            list = list->next;
            free(tmp);
        }
    }
    free(lists);
}

static Obstracle *createNewObstracle(unsigned short xposition, unsigned short yposition) {
    Obstracle *new = (Obstracle *) malloc(sizeof(Obstracle));
    new->xposition = xposition;
    new->yposition = yposition;
    new->next = NULL;
    return new;
}

static Obstracle *addHindernisToList(Obstracle *list, Obstracle *new) {
    if (list == NULL) {
        return new;
    }
    Obstracle *current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;
    return list;
}

int contains(Obstracle *list, unsigned short xposition, unsigned short yposition) {
    Obstracle *current = list;
    while (current != NULL) {
        if (current->xposition == xposition && current->yposition == yposition) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
