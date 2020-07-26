typedef struct Hindernis {
    unsigned int* xpos;
    unsigned int* ypos;
    struct Hindernis* next;
} Hindernis;

Hindernis* createHindernis(int, int);
void delete(Hindernis*);
