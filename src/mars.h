#ifndef MARS_H
#define MARS_H

#include "rover.h"
#include "obstracle.h"

typedef struct {
    unsigned short width;
    unsigned short height;
    rover_t *rover;
    obstracle_t **obstracles;
} mars_t;

mars_t *create_random(unsigned short xpos, unsigned short ypos);
mars_t *create_from_file(char *filename);
void delete_mars(mars_t *mars);
void print_mars(mars_t *mars);
void execute_command(mars_t *mars, char befehl);
void move_rover_forward(mars_t *mars);
void move_rover_back(mars_t *mars);
void save_to_file(mars_t *mars, char *filename);
void execute_live_commands(mars_t *mars);
void execute_command_string(mars_t *mars, char *befehle);

#endif
