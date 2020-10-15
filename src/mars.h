#ifndef MARS_H
#define MARS_H

#include "rover.h"
#include "obstracle.h"

typedef struct {
    unsigned short width;
    unsigned short height;
    Rover *rover;
    Obstracle *obstracles;
} Mars;

Mars *createRandom(unsigned short xpos, unsigned short ypos);
Mars *createFromFile(char *filename);
void deleteMars(Mars *mars);
void print(Mars *mars);
void fuehreBefehlAus(Mars *mars, char befehl);
void bewegeRoverNachVorne(Mars *mars);
void bewegeRoverZurueck(Mars *mars);
void saveToFile(Mars *mars, char *filename);

#endif
