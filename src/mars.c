#include <stdlib.h>
#include <stdio.h>
#include "mars.h"

void fuehreBefehlAus(Mars *mars, char befehl) {
    switch (befehl) {
        case 'M':
            bewegeRoverNachVorne(mars);
            break;
        case 'B':
            bewegeRoverZurueck(mars);
            break;
        case 'L':
            dreheNachLinks(mars->rover);
            break;
        case 'R':
            dreheNachRechts(mars->rover);
            break;
    }
}

void fuehreLiveBefehleAus(Mars *mars) {
    char befehl = 'x';
    do {
        printf("\nEnter command [LRMBx]: ");
        befehl = fgetc(stdin);
        printf("\n");
        fuehreBefehlAus(mars, befehl);
        print(mars);
    } while(befehl != 'x');
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

void bewegeRoverNachVorne(Mars *mars) {
    unsigned short newx = mars->rover->xposition, newy = mars->rover->yposition;
    switch (mars->rover->richtung) {
        case UP:
            newy = (newy == 0) ? mars->height - 1 : newy - 1;
            break;
        case DOWN:
            newy = (newy == mars->height - 1) ? 0 : newy + 1;
            break;
        case RIGHT:
            newx = (newx == mars->width - 1) ? 0 : newx + 1;
            break;
        case LEFT:
            newx = (newx == 0) ? mars->width - 1 : newx - 1;
            break;
    }
    if (!contains(mars->obstracles, newx, newy)) {
        mars->rover->xposition = newx;
        mars->rover->yposition = newy;
    }
}

void bewegeRoverZurueck(Mars *mars) {
    unsigned short newx = mars->rover->xposition, newy = mars->rover->yposition;
    switch (mars->rover->richtung) {
        case UP:
            newy = (newy == mars->height - 1) ? 0 : newy + 1;
            break;
        case DOWN:
            newy = (newy == 0) ? mars->height - 1 : newy - 1;
            break;
        case RIGHT:
            newx = (newx == 0) ? mars->width - 1 : newx - 1;
            break;
        case LEFT:
            newx = (newx == mars->width - 1) ? 0 : newx + 1;
            break;
    }
    if (!contains(mars->obstracles, newx, newy)) {
        mars->rover->xposition = newx;
        mars->rover->yposition = newy;
    }
}

void saveToFile(Mars *mars, char *filename) {
    FILE *out = fopen(filename, "wb");
    if (out == NULL) {
        fprintf(stderr, "ERROR: Could not write to file %s\n", filename);
        return;
    }
    fwrite(&(mars->height), sizeof(unsigned short), 1, out);
    fwrite(&(mars->width), sizeof(unsigned short), 1, out);
    Obstracle *current = mars->obstracles;
    while (current != NULL) {
        fwrite(&(current->xposition), sizeof(unsigned short), 1, out);
        fwrite(&(current->yposition), sizeof(unsigned short), 1, out);
        current = current->next;
    }
    fclose(out);
}

Mars *createFromFile(char *filename) {
    FILE *in = fopen(filename, "rb");
    if (in == NULL) {
        fprintf(stderr, "ERROR: Could not open file %s\n", filename);
        exit(1);
    }
    unsigned short height = 0, width = 0;
    fread(&height, sizeof(unsigned short), 1, in);
    fread(&width, sizeof(unsigned short), 1, in);
    Mars *mars = (Mars *) malloc(sizeof(Mars));
    mars->width = width;
    mars->height = height;
    mars->rover = createRover(width / 2, height / 2);
    mars->obstracles = readObstraclesFromFile(in);
    fclose(in);
    return mars;
}
