#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "objects/mars.h"

void getOptionaleParams(int argc, char *const *argv, int* width, int* height, char* befehle) {
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
                *width = atoi(optarg);
                break;
            case 'h':
                *height = atoi(optarg);
                break;
            default:
                break;
        }
    }
}

int main(int argc, char *const *argv) {
    extern char* optarg;
    int width = 80, height = 20, i;
    char* befehle = "MMLBBBBRMM";
    getOptionaleParams(argc, argv, &width, &height, befehle);
    Mars* mars = initalizeMars(height, width);
    printField(mars);
    for (i = 0; i < strlen(befehle); i++) {
        moveRover(mars, *(befehle + i));
        printField(mars);
    }
    deleteMars(mars);
    return 0;
}
