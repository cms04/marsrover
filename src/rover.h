#ifndef ROVER_H
#define ROVER_H

typedef enum {
    UP,
    LEFT,
    RIGHT,
    DOWN
} richtung_t;

typedef struct {
    unsigned short xposition;
    unsigned short yposition;
    richtung_t richtung;
} rover_t;

rover_t *create_rover(unsigned short xposition, unsigned short yposition);
void delete_rover(rover_t *rover);
int is_rover_position(rover_t *rover, unsigned short xposition, unsigned short yposition);
void print_rover(rover_t *rover);
void turn_rover_left(rover_t *rover);
void turn_rover_right(rover_t *rover);

#endif
