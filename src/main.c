#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "objects/mars.h"

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

void showHelp() {
    printf("MARS-ROVER\n\n");
    printf("Optionale Parameter:\n");
    printf("\t-b\tEine Zeichenkette von Befehlen, bestehend aus den Zeichen L (nach links\n");
    printf("\t\tdrehen), R (nach rechts drehen), M (nach vorne bewegen), B (Rückwärtsgang)\n");
    printf("\t-w\tEine positive Zahl, die die Breite des Feldes angibt\n");
    printf("\t-h\tEine positive Zahl, die die Höhe des Feldes angibt\n");
    printf("\t-l\tLive-Eingabe aktivieren: Wird dieser Parameter gesetzt, kann der Rover\n");
    printf("\t\tper Live-Eingabe direkt vom Nutzer gesteuert werden.\n");
    printf("\nDie Parameter -l und -b dürfen nicht gemeinsam benutzt werden!\n");
    printf("\nWerden keine Parameter angegeben, startet das Programm standardmäßig mit\n");
    printf("einer Breite von 80 Zeichen, einer Länge von 20 Zeichen und der Befehlsfolge\n");
    printf("MMLBBBBRMM.\n");
}

Mars* initMars(int height, int width, char *input) {
    Mars* mars;
    if (input == NULL) {
        mars = initalizeMars(height, width);
    } else {
        FILE *datei = fopen(input, "r");
        mars = initializeWithFile(datei);
        fclose(datei);
    }
    return mars;
}

int main(int argc, char *const *argv) {
    unsigned short width = 80, height = 20, live = 0, inputs = 0;
    char *input = NULL, *output = NULL;
    char* befehle = "MMLBBBBRMM";
    extern char* optarg;
    int result = -1;
    while ((result = getopt(argc, argv, "b:w:h:lmf:o:")) != -1) {
        switch (result) {
            case 'b':
                befehle = optarg;
                inputs += 1;
                break;
            case 'w':
                width = atoi(optarg);
                break;
            case 'h':
                height = atoi(optarg);
                break;
            case 'l':
                live = 1;
                inputs += 1;
                break;
            case 'm':
                showHelp();
                return 0;
            case 'f':
                input = optarg;
                break;
            case 'o':
                output = optarg;
                break;
        }
    }
    if (inputs > 1) {
        fprintf(stderr, "FEHLER: Bitte nur eine Eingabequelle angeben!\n");
        return 1;
    }
    if (input != NULL && output != NULL && strcmp(input, output) == 0) {
        fprintf(stderr, "FEHLER: Eingabe- und Ausgabedatei können nicht identisch sein!\n");
        return 2;
    }
    Mars* mars = initMars(height, width, input);
    if (live) {
        nehmeLiveBefehleEntgegen(mars);
    } else {
        fuehreBefehleAus(mars, befehle);
    }
    if (output != NULL) {
        FILE *datei = fopen(output, "w");
        saveMars(datei, mars);
        fclose(datei);
    }
    deleteMars(mars);
    return 0;
}
