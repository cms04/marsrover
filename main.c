#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printField(char** marskarte) {
  unsigned short i, j;
  printf("\n");
  for (i = 0; i < 80; i++) {
    printf("=");
  }
  printf("\n");
  for (i = 0; i < 20; i++) {
    for (j = 0; j < 80; j++) {
      printf("%c", *(*(marskarte + i) + j));
    }
    printf("\n");
  }
  for (i = 0; i < 80; i++) {
    printf("=");
  }
  printf("\n");
}

void putRandomObstracles(char** marskarte) {
  unsigned short i, j;
  time_t t;
  srand((unsigned) time(&t));
  for (i = 0; i < 20; i++) {
    for (j = 0; j < 80; j++) {
      if (rand() % 5 == 0) {
        *(*(marskarte + i) + j) = '#';
      }
    }
  }
}

void putRover(char** marskarte) {
  *(*(marskarte + 10) + 40) = '^';
}

char** initalizeMarsKarte() {
  unsigned short i, j;
  char** marskarte = (char**) malloc(20 * 80 * sizeof(char));
  for (i = 0; i < 20; i++) {
    *(marskarte + i) = (char*) malloc(80 * sizeof(char));
    for (j = 0; j < 80; j++) {
      *(*(marskarte + i) + j) = ' ';
    }
  }
  putRandomObstracles(marskarte);
  putRover(marskarte);
  return marskarte;
}

void deleteMarsKarte(char** marskarte) {
  unsigned short i;
  for (i = 0; i < 20; i++) {
    free(*(marskarte + i));
  }
  free(marskarte);
}

int main() {
  char** marskarte = initalizeMarsKarte();
  printField(marskarte);
  deleteMarsKarte(marskarte);
  return 0;
}
