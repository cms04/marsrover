#include "obstracle.h"

typedef struct {
    Hindernis* head;
} ObstracleList;

ObstracleList* create();
void insertToList(ObstracleList*, Hindernis*);
void deleteAll(ObstracleList*);
int contains(ObstracleList*, unsigned short, unsigned short);
