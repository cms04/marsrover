#include "obstraclelist.h"

enum Richtung { NORD, OST, SUED, WEST };

typedef struct {
    unsigned short* xpos;
    unsigned short* ypos;
    enum Richtung* direction;
    ObstracleList* obstracles;
} Rover;

Rover* createRover(unsigned short, unsigned short);
void deleteRover(Rover*);
int isRoverPosition(Rover*, unsigned short, unsigned short);
void doCommand(Rover*, char, unsigned short, unsigned short);
char printRover(Rover*);
