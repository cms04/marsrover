#ifndef OBSTRACLE_H
#define OBSTRACLE_H

#include <stdio.h>

typedef struct obstracle_s {
    unsigned short xposition;
    unsigned short yposition;
    struct obstracle_s *next;
} obstracle_t;

typedef struct {
    obstracle_t **list;
    unsigned short maxheight;
    unsigned short maxwidth;
    unsigned short index;
} parameter_t;

obstracle_t **create_obstracles_random(unsigned short maxwidth, unsigned short maxheight);
obstracle_t **create_obstracles_from_file(FILE *in, unsigned short maxheight);
void delete_obstracles(obstracle_t **list, unsigned short maxheight);
int list_contains(obstracle_t *list, unsigned short xposition, unsigned short yposition);
void *create_obstracle_list(void *parameter);
obstracle_t *create_new_obstracle(unsigned short xposition, unsigned short yposition);
obstracle_t *add_obstracle_to_list(obstracle_t *list, obstracle_t *new);

#endif
