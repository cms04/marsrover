#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mars.h"

void printField(Mars* mars) {
  unsigned short i, j;
  printf("\n");
  for (i = 0; i < *(mars->width); i++) {
    printf("=");
  }
  printf("\n");
  for (i = 0; i < *(mars->height); i++) {
    for (j = 0; j < *(mars->width); j++) {
      printf("%c", *(*(mars->oberflaeche + i) + j));
    }
    printf("\n");
  }
  for (i = 0; i < *(mars->width); i++) {
    printf("=");
  }
  printf("\n");
}

void putRandomObstracles(Mars* mars) {
  unsigned short i, j;
  time_t t;
  srand((unsigned) time(&t));
  for (i = 0; i < *(mars->height); i++) {
    for (j = 0; j < *(mars->width); j++) {
      if (rand() % 5 == 0) {
        *(*(mars->oberflaeche + i) + j) = '#';
      }
    }
  }
}

void putRover(Mars* mars) {
  int xpos = *(mars->width) / 2, ypos = *(mars->height) / 2;
  *(*(mars->oberflaeche + ypos) + xpos) = '^';
  *(mars)->roverXPosition = xpos;
  *(mars)->roverYPosition = ypos;
}

Mars initalizeMars(int height, int width) {
  Mars mars;
  unsigned short i, j;
  mars.oberflaeche = (char**) malloc(height * width * sizeof(char));
  for (i = 0; i < height; i++) {
    *(mars.oberflaeche + i) = (char*) malloc(width * sizeof(char));
    for (j = 0; j < width; j++) {
      *(*(mars.oberflaeche + i) + j) = ' ';
    }
  }
  mars.roverXPosition = (int *) malloc(sizeof(int));
  mars.roverYPosition = (int *) malloc(sizeof(int));
  mars.height = (int *) malloc(sizeof(int));
  mars.width = (int *) malloc(sizeof(int));
  *(mars.height) = height;
  *(mars.width) = width;
  putRandomObstracles(&mars);
  putRover(&mars);
  return mars;
}

void deleteMars(Mars* mars) {
  unsigned short i;
  for (i = 0; i < *(mars->height); i++) {
    free(*(mars->oberflaeche + i));
  }
  free(mars->oberflaeche);
  free(mars->roverXPosition);
  free(mars->roverYPosition);
  free(mars->height);
  free(mars->width);
}
