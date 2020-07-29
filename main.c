#include <string.h>
#include "mars.h"

int main(int argc, const char** argv) {
    const char* befehle;
    int i;
    Mars* mars = initalizeMars(20, 80);
    if (argc == 2) {
        befehle = *(argv + 1);
    } else {
        befehle = "MMMLMMMMMMRBBBBBLMM";
    }
    printField(mars);
    for (i = 0; i < strlen(befehle); i++) {
        moveRover(mars, *(befehle + i));
        printField(mars);
    }
    deleteMars(mars);
    return 0;
}
