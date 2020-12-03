#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "obstracle.h"

obstracle_t **create_obstracles_random(unsigned short maxwidth, unsigned short maxheight) {
    obstracle_t **list = (obstracle_t **) malloc(maxheight * sizeof(obstracle_t *));
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
    parameter_t *parameters = (parameter_t *) malloc(maxheight * sizeof(parameter_t));
    if (parameters == NULL) {
        free(list);
        free(threads);
        return NULL;
    }
    for (unsigned short i = 0; i < maxheight; i++) {
        (parameters + i)->maxheight = maxheight;
        (parameters + i)->maxwidth = maxwidth;
        (parameters + i)->index = i;
        pthread_create(threads + i, NULL, &create_obstracle_list, parameters + i);
    }
    for (unsigned short i = 0; i < maxheight; i++) {
        pthread_join(threads[i], (void *) (list + i));
    }
    free(threads);
    free(parameters);
    return list;
}

void *create_obstracle_list(void *parameter) {
    parameter_t *p = (parameter_t *) parameter;
    obstracle_t *list = NULL;
    obstracle_t *new = NULL;
    for (unsigned short j = 0; j < p->maxwidth; j++) {
        if (rand() % 5 == 0 && (j != p->maxwidth / 2 || p->index != p->maxheight / 2)) {
            new = create_new_obstracle(j, p->index);
            list = add_obstracle_to_list(list, new);
        }
    }
    pthread_exit((void *) list);
}


obstracle_t **create_obstracles_from_file(FILE *in, unsigned short maxheight) {
    obstracle_t **list = (obstracle_t **) malloc(maxheight * sizeof(obstracle_t *));
    if (list == NULL) {
        return NULL;
    }
    for (unsigned short i = 0; i < maxheight; i++) {
        *(list + i) = NULL;
    }
    obstracle_t *new = NULL;
    unsigned short coordinates[2] = {0, 0};
    while (fread(&coordinates, sizeof(unsigned short), 2, in) == 2) {
        new = create_new_obstracle(coordinates[0], coordinates[1]);
        *(list + coordinates[1]) = add_obstracle_to_list(*(list + coordinates[1]), new);
    }
    return list;
}

void delete_obstracles(obstracle_t **lists, unsigned short maxheight) {
    if (lists != NULL) {
        for (unsigned short i = 0; i < maxheight; i++) {
            obstracle_t *tmp, *list = *(lists + i);
            while (list != NULL) {
                tmp = list;
                list = list->next;
                free(tmp);
            }
        }
        free(lists);
    }
}

obstracle_t *create_new_obstracle(unsigned short xposition, unsigned short yposition) {
    obstracle_t *new = (obstracle_t *) malloc(sizeof(obstracle_t));
    if (new == NULL) {
        return NULL;
    }
    new->xposition = xposition;
    new->yposition = yposition;
    new->next = NULL;
    return new;
}

obstracle_t *add_obstracle_to_list(obstracle_t *list, obstracle_t *new) {
    if (list == NULL) {
        return new;
    }
    list->next = add_obstracle_to_list(list->next, new);
    return list;
}

int list_contains(obstracle_t *list, unsigned short xposition, unsigned short yposition) {
    if (list == NULL) {
        return 0;
    }
    if (list->xposition == xposition && list->yposition == yposition) {
        return 1;
    }
    return list_contains(list->next, xposition, yposition);
}
