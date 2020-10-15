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
    char *befehle = "MMLBBBBRMM", *outputfilename = NULL, *inputfilename = NULL;
    extern char *optarg;
    char param = -1;
    while ((param = getopt(argc, argv, "h:w:b:o:i:")) != EOF) {
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
        }
    }
    Mars *mars = (inputfilename == NULL) ? createRandom(width, height) : createFromFile(inputfilename);
    print(mars);
    arbeiteBefehleAb(mars, befehle);
    if (outputfilename != NULL) {
        saveToFile(mars, outputfilename);
    }
    deleteMars(mars);
    return 0;
}
