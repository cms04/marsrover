#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mars.h"

void execute_command(mars_t *mars, char befehl) {
    switch (befehl) {
        case 'M':
            move_rover_forward(mars);
            break;
        case 'B':
            move_rover_back(mars);
            break;
        case 'L':
            turn_rover_left(mars->rover);
            break;
        case 'R':
            turn_rover_right(mars->rover);
            break;
    }
}

void execute_live_commands(mars_t *mars) {
    char befehl = 'x';
    do {
        printf("\nEnter command [LRMBx]: ");
        befehl = fgetc(stdin);
        printf("\n");
        execute_command(mars, befehl);
        print_mars(mars);
    } while(befehl != 'x');
}

void execute_command_string(mars_t *mars, char *befehle) {
    for (size_t i = 0; i < strlen(befehle); i++) {
        execute_command(mars, *(befehle + i));
        print_mars(mars);
    }
}

mars_t *create_random(unsigned short width, unsigned short height) {
    mars_t *mars = (mars_t *) malloc(sizeof(mars_t));
    if (mars == NULL) {
        return NULL;
    }
    mars->width = width;
    mars->height = height;
    mars->rover = create_rover(width / 2, height / 2);
    if (mars->rover == NULL) {
        free(mars);
        return NULL;
    }
    mars->obstracles = create_obstracles_random(width, height);
    if (mars->obstracles == NULL) {
        delete_rover(mars->rover);
        free(mars);
        return NULL;
    }
    return mars;
}

void delete_mars(mars_t *mars) {
    if (mars != NULL) {
        delete_rover(mars->rover);
        delete_obstracles(mars->obstracles, mars->height);
        free(mars);
    }
}

void print_mars(mars_t *mars) {
    for (unsigned short i = 0; i < mars->width; i++) {
        printf("=");
    }
    printf("\n");
    for (unsigned short i = 0; i < mars->height; i++) {
        for (unsigned short j = 0; j < mars->width; j++) {
            if (is_rover_position(mars->rover, j, i)) {
                print_rover(mars->rover);
            } else if (list_contains(mars->obstracles[i], j, i)) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (unsigned short i = 0; i < mars->width; i++) {
        printf("=");
    }
    printf("\n");
}

void move_rover_forward(mars_t *mars) {
    unsigned short newx = mars->rover->xposition, newy = mars->rover->yposition;
    switch (mars->rover->richtung) {
        case UP:
            newy = (newy == 0) ? mars->height - 1 : newy - 1;
            break;
        case DOWN:
            newy = (newy == mars->height - 1) ? 0 : newy + 1;
            break;
        case RIGHT:
            newx = (newx == mars->width - 1) ? 0 : newx + 1;
            break;
        case LEFT:
            newx = (newx == 0) ? mars->width - 1 : newx - 1;
            break;
    }
    if (!list_contains(mars->obstracles[newy], newx, newy)) {
        mars->rover->xposition = newx;
        mars->rover->yposition = newy;
    }
}

void move_rover_back(mars_t *mars) {
    unsigned short newx = mars->rover->xposition, newy = mars->rover->yposition;
    switch (mars->rover->richtung) {
        case UP:
            newy = (newy == mars->height - 1) ? 0 : newy + 1;
            break;
        case DOWN:
            newy = (newy == 0) ? mars->height - 1 : newy - 1;
            break;
        case RIGHT:
            newx = (newx == 0) ? mars->width - 1 : newx - 1;
            break;
        case LEFT:
            newx = (newx == mars->width - 1) ? 0 : newx + 1;
            break;
    }
    if (!list_contains(mars->obstracles[newy], newx, newy)) {
        mars->rover->xposition = newx;
        mars->rover->yposition = newy;
    }
}

void save_to_file(mars_t *mars, char *filename) {
    FILE *out = fopen(filename, "wb");
    if (out == NULL) {
        fprintf(stderr, "ERROR: Could not write to file %s\n", filename);
        return;
    }
    fwrite(&(mars->height), sizeof(unsigned short), 1, out);
    fwrite(&(mars->width), sizeof(unsigned short), 1, out);
    for (unsigned short i = 0; i < mars->height; i++) {
        obstracle_t *current = mars->obstracles[i];
        while (current != NULL) {
            fwrite(&(current->xposition), sizeof(unsigned short), 1, out);
            fwrite(&(current->yposition), sizeof(unsigned short), 1, out);
            current = current->next;
        }
    }
    fclose(out);
}

mars_t *create_from_file(char *filename) {
    FILE *in = fopen(filename, "rb");
    if (in == NULL) {
        fprintf(stderr, "ERROR: Could not open file %s\n", filename);
        exit(3);
    }
    unsigned short height = 0, width = 0;
    fread(&height, sizeof(unsigned short), 1, in);
    fread(&width, sizeof(unsigned short), 1, in);
    mars_t *mars = (mars_t *) malloc(sizeof(mars_t));
    if (mars == NULL) {
        fclose(in);
        return NULL;
    }
    mars->width = width;
    mars->height = height;
    mars->rover = create_rover(width / 2, height / 2);
    if (mars->rover == NULL) {
        free(mars);
        fclose(in);
        return NULL;
    }
    mars->obstracles = create_obstracles_from_file(in, mars->height);
    if (mars->obstracles == NULL) {
        delete_rover(mars->rover);
        free(mars);
        fclose(in);
        return NULL;
    }
    fclose(in);
    return mars;
}
