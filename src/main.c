#include "mars.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arbeiteBefehleAb(Mars *mars, char *befehle) {
    for (size_t i = 0; i < strlen(befehle); i++) {
        fuehreBefehlAus(mars, *(befehle + i));
        print(mars);
    }
}

int main(int argc, char *const *argv) {
    unsigned short width = 80, height = 20;
    char *befehle = "MMLBBBBRMM";
    extern char *optarg;
    char param = -1;
    while ((param = getopt(argc, argv, "h:w:")) != EOF) {
        switch (param) {
            case 'h':
                height = atoi(optarg);
                break;
            case 'w':
                width = atoi(optarg);
                break;
        }
    }
    Mars *mars = createRandom(width, height);
    print(mars);
    arbeiteBefehleAb(mars, befehle);
    deleteMars(mars);
    return 0;
}
