#include "mars.h"

int main() {
  Mars mars = initalizeMars();
  printField((&mars)->oberflaeche);
  deleteMars(&mars);
  return 0;
}
