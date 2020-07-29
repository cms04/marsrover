#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "objects/mars.h"

void getOptionaleParams(int argc, char *const *argv, int* width, int* height, char* befehle) {

}

void fuehreBefehleAus(Mars* mars, char* befehle) {
    int i;
    printField(mars);
    for (i = 0; i < strlen(befehle); i++) {
        moveRover(mars, *(befehle + i));
        printField(mars);
    }
}

int main(int argc, char *const *argv) {
    int width = 80, height = 20;
    char* befehle = "MMLBBBBRMM";
    extern char* optarg;
    int result = -1;
    while ((result = getopt(argc, argv, "b:w:h:")) != -1) {
        switch (result) {
            case '?':
                break;
            case 'b':
                befehle = optarg;
                break;
            case 'w':
                width = atoi(optarg);
                break;
            case 'h':
                height = atoi(optarg);
                break;
            default:
                break;
        }
    }
    Mars* mars = initalizeMars(height, width);
    fuehreBefehleAus(mars, befehle);
    deleteMars(mars);
    return 0;
}
