#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "objects/mars.h"

int main(int argc, char *const *argv) {
    extern char* optarg;
    int result = -1, width = 80, height = 20, i;
    const char* befehle = "MMLBBBBRMM";
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
    printField(mars);
    for (i = 0; i < strlen(befehle); i++) {
        moveRover(mars, *(befehle + i));
        printField(mars);
    }
    deleteMars(mars);
    return 0;
}
