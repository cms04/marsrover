#include "mars.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *const *argv) {
    unsigned short width = 80, height = 20, live = 0;
    char *befehle = "MMLBBBBRMM", *outputfilename = NULL, *inputfilename = NULL;
    extern char *optarg;
    char param = -1;
    while ((param = getopt(argc, argv, "h:w:b:o:i:l")) != EOF) {
        switch (param) {
            case 'h':
                height = atoi(optarg);
                break;
            case 'w':
                width = atoi(optarg);
                break;
            case 'b':
                befehle = optarg;
                break;
            case 'o':
                outputfilename = optarg;
                break;
            case 'i':
                inputfilename = optarg;
                break;
            case 'l':
                live = 1;
                break;
        }
    }
    Mars *mars = (inputfilename == NULL) ? createRandom(width, height) : createFromFile(inputfilename);
    if (mars == NULL) {
        fprintf(stderr, "ERROR: Not enough space available.\n");
        return 1;
    }
    print(mars);
    if (live) {
        fuehreLiveBefehleAus(mars);
    } else {
        arbeiteBefehleAb(mars, befehle);
    }
    if (outputfilename != NULL) {
        saveToFile(mars, outputfilename);
    }
    deleteMars(mars);
    return 0;
}
