#include "obstraclelist.h"
#include "rover.h"

typedef struct {
    char** oberflaeche;
    unsigned short* roverXPosition;
    unsigned short* roverYPosition;
    unsigned short* height;
    unsigned short* width;
    ObstracleList* obstracles;
    Rover* rover;
} Mars;

void printField(Mars*);
Mars* initalizeMars(unsigned short, unsigned short);
void deleteMars(Mars*);
