typedef struct {
  char** oberflaeche;
  int* roverXPosition;
  int* roverYPosition;
} Mars;

void printField(char**);
Mars initalizeMars();
void deleteMars(Mars*);
