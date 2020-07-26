#include <stdio.h>
#include <stdlib.h>
#include "obstraclelist.h"

ObstracleList* create() {
    ObstracleList* list = (ObstracleList*) malloc(sizeof(ObstracleList));
    return list;
}

void insertToList(ObstracleList* list, Hindernis* obs) {
    if (list->head == NULL) {
        list->head = obs;
        return;
    }
    obs->next = list->head;
    list->head = obs;
}

void deleteAll(ObstracleList* list) {
    Hindernis* cur = list->head;
    Hindernis* next = NULL;
    for (; cur != NULL; cur = next) {
        next = cur->next;
        delete(cur);
    }
    free(list);
}
