#include "rover.h"

typedef struct {
    char** oberflaeche;
    unsigned short* height;
    unsigned short* width;
    Rover* rover;
} Mars;

void printField(Mars*);
void deleteMars(Mars*);
void moveRover(Mars*, char);
void saveMars(FILE *output, Mars* mars);
Mars* initMars(unsigned short height, unsigned short width, char *input);
