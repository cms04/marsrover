typedef struct Hindernis {
    unsigned short* xpos;
    unsigned short* ypos;
    struct Hindernis* next;
} Hindernis;

Hindernis* createHindernis(unsigned short, unsigned short);
void delete(Hindernis*);
