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

void putObstracle(ObstracleList* list, unsigned short height, unsigned short width) {
    Hindernis* obs = createHindernis(height, width);
    insertToList(list, obs);
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
                putObstracle(obstracles, j, i);
            }
        }
    }
    mars->rover->obstracles = obstracles;
}

void putRover(Mars* mars) {
    unsigned short xpos = *(mars->width) / 2, ypos = *(mars->height) / 2;
    mars->rover = createRover(xpos, ypos);
}

void saveBasicSettings(Mars* mars, unsigned short height, unsigned short width) {
    mars->oberflaeche = (char**) malloc(height * sizeof(char *));
    mars->height = (unsigned short *) malloc(sizeof(unsigned short));
    mars->width = (unsigned short *) malloc(sizeof(unsigned short));
    *(mars->height) = height;
    *(mars->width) = width;
    putRover(mars);
}

Mars* initalizeMars(unsigned short height, unsigned short width) {
    Mars* mars = (Mars *) malloc(sizeof(Mars));
    saveBasicSettings(mars, height, width);
    unsigned short i, j;
    for (i = 0; i < height; i++) {
        *(mars->oberflaeche + i) = (char*) malloc(width * sizeof(char));
        for (j = 0; j < width; j++) {
            *(*(mars->oberflaeche + i) + j) = ' ';
        }
    }
    putRandomObstracles(mars);
    return mars;
}

Mars* initializeWithFile(FILE *input) {
    Mars* mars = (Mars *) malloc(sizeof(Mars));
    unsigned short i, j;
    unsigned short height = 0, width = 0;
    fread(&height, sizeof(unsigned short), 1, input);
    fread(&width, sizeof(unsigned short), 1, input);
    saveBasicSettings(mars, height, width);
    ObstracleList* obstracles = create();
    for (i = 0; i < height; i++) {
        *(mars->oberflaeche + i) = (char*) malloc(width * sizeof(char));
        for (j = 0; j < width; j++) {
            fread(*(mars->oberflaeche + i) + j, sizeof(unsigned char), 1, input);
            if (*(*(mars->oberflaeche + i) + j) == '#') {
                putObstracle(obstracles, j, i);
            }
        }
    }
    mars->rover->obstracles = obstracles;
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

void saveMars(FILE *output, Mars* mars) {
    fwrite(mars->height, sizeof(unsigned short), 1, output);
    fwrite(mars->width, sizeof(unsigned short), 1, output);
    for (int i = 0; i < *(mars->height); i++) {
        for (int j = 0; j < *(mars->width); j++) {
            fwrite(*(mars->oberflaeche + i) + j, sizeof(char), 1, output);
        }
    }
}
