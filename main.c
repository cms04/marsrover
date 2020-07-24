#include "mars.h"

int main() {
  Mars mars = initalizeMars(20, 80);
  printField(&mars);
  deleteMars(&mars);
  return 0;
}
