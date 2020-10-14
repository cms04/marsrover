#include <stdlib.h>
#include <stdio.h>
#include "mars.h"

void fuehreBefehlAus(Mars *mars, char befehl) {
    switch (befehl) {
        case 'M':
            //bewegeRoverNachVorne(mars);
            break;
        case 'B':
            //bewegeRoverZurueck(mars);
            break;
        case 'L':
            dreheNachLinks(mars->rover);
            break;
        case 'R':
            dreheNachRechts(mars->rover);
            break;
    }
}

Mars *createRandom(unsigned short width, unsigned short height) {
    Mars *mars = (Mars *) malloc(sizeof(Mars));
    mars->width = width;
    mars->height = height;
    mars->rover = createRover(width / 2, height / 2);
    mars->obstracles = createRandomObstracles(width, height);
    return mars;
}

void deleteMars(Mars *mars) {
    deleteRover(mars->rover);
    deleteObstracles(mars->obstracles);
    free(mars);
}

void print(Mars *mars) {
    for (unsigned short i = 0; i < mars->width; i++) {
        printf("=");
    }
    printf("\n");
    for (unsigned short i = 0; i < mars->height; i++) {
        for (unsigned short j = 0; j < mars->width; j++) {
            if (isRoverPosition(mars->rover, j, i)) {
                printRover(mars->rover);
            } else if (contains(mars->obstracles, j, i)) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (unsigned short i = 0; i < mars->width; i++) {
        printf("=");
    }
    printf("\n");
}
