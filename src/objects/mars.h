#ifndef MARS_H
#define MARS_H

#include "rover.h"

typedef struct {
    char** oberflaeche;
    unsigned short* height;
    unsigned short* width;
    Rover* rover;
} Mars;

void printField(Mars*);
void deleteMars(Mars*);
void moveRover(Mars*, char command);
void saveMars(FILE* outputfile, Mars*);
Mars* initMars(unsigned short height, unsigned short width, char* inputfilename);

#endif
