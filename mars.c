#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mars.h"

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

void putRover(Mars* mars) {
  *(*(mars->oberflaeche + 10) + 40) = '^';
  *(mars)->roverXPosition = 40;
  *(mars)->roverYPosition = 10;
}

Mars initalizeMars() {
  Mars mars;
  unsigned short i, j;
  mars.oberflaeche = (char**) malloc(20 * 80 * sizeof(char));
  for (i = 0; i < 20; i++) {
    *(mars.oberflaeche + i) = (char*) malloc(80 * sizeof(char));
    for (j = 0; j < 80; j++) {
      *(*(mars.oberflaeche + i) + j) = ' ';
    }
  }
  mars.roverXPosition = (int *) malloc(sizeof(int));
  mars.roverYPosition = (int *) malloc(sizeof(int));
  putRandomObstracles(mars.oberflaeche);
  putRover(&mars);
  return mars;
}

void deleteMars(Mars* mars) {
  unsigned short i;
  for (i = 0; i < 20; i++) {
    free(*(mars->oberflaeche + i));
  }
  free(mars->oberflaeche);
  free(mars->roverXPosition);
  free(mars->roverYPosition);
}
