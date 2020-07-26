#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mars.h"

void printField(Mars* mars) {
    unsigned short i, j;
    printf("\n");
    for (i = 0; i < *(mars->width); i++) {
        printf("=");
    }
    printf("\n");
    for (i = 0; i < *(mars->height); i++) {
        for (j = 0; j < *(mars->width); j++) {
            printf("%c", *(*(mars->oberflaeche + i) + j));
        }
        printf("\n");
    }
    for (i = 0; i < *(mars->width); i++) {
        printf("=");
    }
    printf("\n");
}

void putRandomObstracles(Mars* mars) {
    ObstracleList* obstracles = create();
    unsigned short i, j;
    time_t t;
    srand((unsigned) time(&t));
    for (i = 0; i < *(mars->height); i++) {
        for (j = 0; j < *(mars->width); j++) {
            if (rand() % 5 == 0) {
                *(*(mars->oberflaeche + i) + j) = '#';
                Hindernis* obs = createHindernis(j, i);
                insertToList(obstracles, obs);
            }
        }
    }
    mars->obstracles = obstracles;
}

void putRover(Mars* mars) {
    unsigned short xpos = *(mars->width) / 2, ypos = *(mars->height) / 2;
    *(*(mars->oberflaeche + ypos) + xpos) = '^';
    *(mars)->roverXPosition = xpos;
    *(mars)->roverYPosition = ypos;
}

Mars* initalizeMars(unsigned short height, unsigned short width) {
    Mars* mars = (Mars *) malloc(sizeof(Mars));
    unsigned short i, j;
    mars->oberflaeche = (char**) malloc(height * width * sizeof(char));
    for (i = 0; i < height; i++) {
        *(mars->oberflaeche + i) = (char*) malloc(width * sizeof(char));
        for (j = 0; j < width; j++) {
            *(*(mars->oberflaeche + i) + j) = ' ';
        }
    }
    mars->roverXPosition = (unsigned short *) malloc(sizeof(unsigned short));
    mars->roverYPosition = (unsigned short *) malloc(sizeof(unsigned short));
    mars->height = (unsigned short *) malloc(sizeof(unsigned short));
    mars->width = (unsigned short *) malloc(sizeof(unsigned short));
    *(mars->height) = height;
    *(mars->width) = width;
    putRandomObstracles(mars);
    putRover(mars);
    return mars;
}

void deleteMars(Mars* mars) {
    unsigned short i;
    for (i = 0; i < *(mars->height); i++) {
        free(*(mars->oberflaeche + i));
    }
    free(mars->oberflaeche);
    free(mars->roverXPosition);
    free(mars->roverYPosition);
    free(mars->height);
    free(mars->width);
    deleteAll(mars->obstracles);
    free(mars);
}
