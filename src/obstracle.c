#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "obstracle.h"

static Obstracle *createNewObstracle(unsigned short xposition, unsigned short yposition);
static Obstracle *addHindernisToList(Obstracle *list, Obstracle *new);

Obstracle **createRandomObstracles(unsigned short maxwidth, unsigned short maxheight) {
    Obstracle **list = (Obstracle **) malloc(maxheight * sizeof(Obstracle *));
    if (list == NULL) {
        return NULL;
    }
    for (unsigned short i = 0; i < maxheight; i++) {
        *(list + i) = NULL;
    }
    srand(time(NULL));
    pthread_t *threads = (pthread_t *) malloc(maxheight * sizeof(pthread_t));
    if (threads == NULL) {
        free(list);
        return NULL;
    }
    Parameter *parameters = (Parameter *) malloc(maxheight * sizeof(Parameter));
    if (parameters == NULL) {
        free(list);
        free(threads);
        return NULL;
    }
    for (unsigned short i = 0; i < maxheight; i++) {
        (parameters + i)->list = list + i;
        (parameters + i)->maxheight = maxheight;
        (parameters + i)->maxwidth = maxwidth;
        (parameters + i)->index = i;
        pthread_create(threads + i, NULL, &createObstracleList, parameters + i);
    }
    for (unsigned short i = 0; i < maxheight; i++) {
        pthread_join(threads[i], (void *) *(list + i));
    }
    free(threads);
    free(parameters);
    return list;
}

void *createObstracleList(void *parameter) {
    Parameter *p = (Parameter *) parameter;
    Obstracle *new = NULL;
    for (unsigned short j = 0; j < p->maxwidth; j++) {
        if (rand() % 5 == 0 && (j != p->maxwidth / 2 || p->index != p->maxheight / 2)) {
            new = createNewObstracle(j, p->index);
            *(p->list) = addHindernisToList(*(p->list), new);
        }
    }
    pthread_exit((void *) p->list);
}


Obstracle **readObstraclesFromFile(FILE *in, unsigned short maxheight) {
    Obstracle **list = (Obstracle **) malloc(maxheight * sizeof(Obstracle *));
    if (list == NULL) {
        return NULL;
    }
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
    if (lists != NULL) {
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
}

static Obstracle *createNewObstracle(unsigned short xposition, unsigned short yposition) {
    Obstracle *new = (Obstracle *) malloc(sizeof(Obstracle));
    if (new == NULL) {
        return NULL;
    }
    new->xposition = xposition;
    new->yposition = yposition;
    new->next = NULL;
    return new;
}

static Obstracle *addHindernisToList(Obstracle *list, Obstracle *new) {
    if (new != NULL) {
        if (list == NULL) {
            return new;
        }
        Obstracle *current = list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    }
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
