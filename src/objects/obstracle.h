typedef struct Hindernis {
    unsigned short* xpos;
    unsigned short* ypos;
    struct Hindernis* next;
} Hindernis;

Hindernis* createHindernis(unsigned short x, unsigned short y);
void delete(Hindernis*);
int equals(Hindernis*, unsigned short x, unsigned short y);
