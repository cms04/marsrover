#include <stdlib.h>
#include <time.h>
#include "obstracle.h"

static Obstracle *createNewObstracle(unsigned short xposition, unsigned short yposition);
static Obstracle *addHindernisToList(Obstracle *list, Obstracle *new);

Obstracle *createRandomObstracles(unsigned short maxwidth, unsigned short maxheight) {
    Obstracle *head = NULL, *new = NULL;
    time_t t;
    srand((unsigned) time(&t));
    for (unsigned short i = 0; i < maxheight; i++) {
        for (unsigned short j = 0; j < maxwidth; j++) {
            if (rand() % 5 == 0 && (j != maxwidth / 2 || i != maxheight / 2)) {
                new = createNewObstracle(j, i);
                head = addHindernisToList(head, new);
            }
        }
    }
    return head;
}

Obstracle *readObstraclesFromFile(FILE *in) {
    Obstracle *head = NULL, *new = NULL;
    unsigned short coordinates[2] = {0, 0};
    while (fread(&coordinates, sizeof(unsigned short), 2, in) == 2) {
        new = createNewObstracle(coordinates[0], coordinates[1]);
        head = addHindernisToList(head, new);
    }
    return head;
}

void deleteObstracles(Obstracle *list) {
    Obstracle *tmp;
    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
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
