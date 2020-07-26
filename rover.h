typedef struct {
    unsigned short* xpos;
    unsigned short* ypos;
    char* direction;
} Rover;

Rover* createRover(unsigned short, unsigned short);
void deleteRover(Rover*);
int isRoverPosition(Rover*, unsigned short, unsigned short);
