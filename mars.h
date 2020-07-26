#include "obstraclelist.h"

typedef struct {
    char** oberflaeche;
    int* roverXPosition;
    int* roverYPosition;
    int* height;
    int* width;
    ObstracleList* obstracles;
} Mars;

void printField(Mars*);
Mars* initalizeMars(int, int);
void deleteMars(Mars*);
