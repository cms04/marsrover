typedef struct {
    char** oberflaeche;
    int* roverXPosition;
    int* roverYPosition;
    int* height;
    int* width;
} Mars;

void printField(Mars*);
Mars initalizeMars(int, int);
void deleteMars(Mars*);
