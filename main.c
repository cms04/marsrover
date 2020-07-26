#include "mars.h"

int main() {
    Mars* mars = initalizeMars(20, 80);
    printField(mars);
    moveRover(mars, 'L');
    printField(mars);
    moveRover(mars, 'M');
    moveRover(mars, 'M');
    printField(mars);
    deleteMars(mars);
    return 0;
}
