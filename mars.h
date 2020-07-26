#include "obstraclelist.h"

typedef struct {
    char** oberflaeche;
    unsigned short* roverXPosition;
    unsigned short* roverYPosition;
    unsigned short* height;
    unsigned short* width;
    ObstracleList* obstracles;
} Mars;

void printField(Mars*);
Mars* initalizeMars(unsigned short, unsigned short);
void deleteMars(Mars*);
