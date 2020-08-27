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
            if (isRoverPosition(mars->rover, j, i)) {
                printf("%c", printRover(mars->rover));
            } else {
                printf("%c", *(*(mars->oberflaeche + i) + j));
            }
        }
        printf("\n");
    }
    for (i = 0; i < *(mars->width); i++) {
        printf("=");
    }
    printf("\n");
}

void moveRover(Mars* mars, char command) {
    doCommand(mars->rover, command, *(mars->width), *(mars->height));
}

void putRandomObstracles(Mars* mars) {
    ObstracleList* obstracles = create();
    unsigned short i, j;
    time_t t;
    srand((unsigned) time(&t));
    for (i = 0; i < *(mars->height); i++) {
        for (j = 0; j < *(mars->width); j++) {
            if (rand() % 5 == 0 && (j != *(mars->width) / 2 || i != *(mars->height) / 2)) {
                *(*(mars->oberflaeche + i) + j) = '#';
                Hindernis* obs = createHindernis(j, i);
                insertToList(obstracles, obs);
            }
        }
    }
    mars->rover->obstracles = obstracles;
}

void putObstracle(ObstracleList* list, unsigned short height, unsigned short width) {
    Hindernis* obs = createHindernis(height, width);
    insertToList(list, obs);
}

void putRover(Mars* mars) {
    unsigned short xpos = *(mars->width) / 2, ypos = *(mars->height) / 2;
    mars->rover = createRover(xpos, ypos);
}

Mars* initalizeMars(unsigned short height, unsigned short width) {
    Mars* mars = (Mars *) malloc(sizeof(Mars));
    unsigned short i, j;
    mars->oberflaeche = (char**) malloc(height * sizeof(char *));
    for (i = 0; i < height; i++) {
        *(mars->oberflaeche + i) = (char*) malloc(width * sizeof(char));
        for (j = 0; j < width; j++) {
            *(*(mars->oberflaeche + i) + j) = ' ';
        }
    }
    mars->height = (unsigned short *) malloc(sizeof(unsigned short));
    mars->width = (unsigned short *) malloc(sizeof(unsigned short));
    *(mars->height) = height;
    *(mars->width) = width;
    putRover(mars);
    putRandomObstracles(mars);
    return mars;
}

Mars* initializeWithFile(FILE *input) {
    Mars* mars = (Mars *) malloc(sizeof(Mars));
    unsigned short i, j;
    unsigned short height = 0, width = 0;
    fscanf(input, "%hd %hd", &height, &width);
    mars->height = (unsigned short *) malloc(sizeof(unsigned short));
    mars->width = (unsigned short *) malloc(sizeof(unsigned short));
    *(mars->height) = height;
    *(mars->width) = width;
    putRover(mars);
    char *inputline = (char *) malloc((width * sizeof(char)) + 1);
    mars->oberflaeche = (char**) malloc(height * sizeof(char *));
    ObstracleList* obstracles = create();
    mars->rover->obstracles = obstracles;
    for (i = 0; i < height; i++) {
        *(mars->oberflaeche + i) = (char*) malloc(width * sizeof(char));
        fgets(inputline, width, input);
        fgets(inputline, width, input);
        *(inputline + width) = '\0';
        for (j = 0; j < width; j++) {
            *(*(mars->oberflaeche + i) + j) = *(inputline + j);
            if (*(inputline + j) == '#') {
                putObstracle(obstracles, i, j);
            }
        }
    }
    free(inputline);
    return mars;
}

void deleteMars(Mars* mars) {
    unsigned short i;
    for (i = 0; i < *(mars->height); i++) {
        free(*(mars->oberflaeche + i));
    }
    free(mars->oberflaeche);
    free(mars->height);
    free(mars->width);
    deleteRover(mars->rover);
    free(mars);
}
