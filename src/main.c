#include "mars.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *const *argv) {
    unsigned short width = 80, height = 20;
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
    deleteMars(mars);
    return 0;
}
