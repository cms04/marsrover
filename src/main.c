#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "objects/mars.h"

char* getOptionaleParams(int argc, char *const *argv, int* width, int* height, int* live) {
    extern char* optarg;
    char* befehle = NULL;
    int result = -1;
    while ((result = getopt(argc, argv, "b:w:h:l")) != -1) {
        switch (result) {
            case '?':
                break;
            case 'b':
                befehle = optarg;
                break;
            case 'w':
                *width = atoi(optarg);
                break;
            case 'h':
                *height = atoi(optarg);
                break;
            case 'l':
                *live = 1;
                break;
            default:
                break;
        }
    }
    if (befehle == NULL) {
        return "MMLBBBBRMM";
    } else {
        return befehle;
    }
}

void fuehreBefehleAus(Mars* mars, char* befehle) {
    int i;
    printField(mars);
    for (i = 0; i < strlen(befehle); i++) {
        moveRover(mars, *(befehle + i));
        printField(mars);
    }
}

void nehmeLiveBefehleEntgegen(Mars* mars) {
    char command = 'N', tmp = '\n';
    printField(mars);
    printf("Live-Eingabe ausgewählt.\n");
    do {
        printf("Bitte einen Befehl eingeben [LRMBx]: ");
        fscanf(stdin, "%c%c", &command, &tmp);
        moveRover(mars, command);
        printField(mars);
    } while(command != 'x');
    printf("Programm wird beendet...\n");
}

int main(int argc, char *const *argv) {
    int width = 80, height = 20, live = 0;
    char* befehle = getOptionaleParams(argc, argv, &width, &height, &live);
    Mars* mars = initalizeMars(height, width);
    if (live) {
        nehmeLiveBefehleEntgegen(mars);
    } else {
        fuehreBefehleAus(mars, befehle);
    }
    deleteMars(mars);
    return 0;
}
