/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** broadcast
*/

#ifndef BROADCAST_H_
    #define BROADCAST_H_

    #include "server.h"

typedef struct positions_s {
    uint x;
    uint y;
    char k;
    client_t *client;
    struct positions_s *next;
} positions_t;

typedef struct degree_angle_table_s {
    const float min_degree;
    const float max_degree;
    const char *position;
} degree_angle_table_t;

static const float NORTH_DEGREE = 180.0;
static const float WEST_DEGREE  = 90.0;
static const float EST_DEGREE   = -90.0;
static const float SOUTH_DEGREE = 0.0;
static const float SCALE_PROTRACTOR_MAX_SIZE = 180.0;

    #define NORTH       "NORTH"
    #define EST         "EST"
    #define WEST        "WEST"
    #define SOUTH       "SOUTH"
    #define NORTH_EST   "NORTH_EST"
    #define NORTH_WEST  "NORTH_WEST"
    #define SOUTH_EST   "SOUTH_EST"
    #define SOUTH_WEST  "SOUTH_WEST"

static const degree_angle_table_t DEGREE_ANGLE_TABLE[] = {
    {NORTH_DEGREE,  NORTH_DEGREE,   NORTH},
    {EST_DEGREE,    EST_DEGREE,     EST},
    {WEST_DEGREE,   WEST_DEGREE,    WEST},
    {SOUTH_DEGREE,  SOUTH_DEGREE,   SOUTH},
    {SOUTH_DEGREE,  WEST_DEGREE,    SOUTH_EST},
    {WEST_DEGREE,   NORTH_DEGREE,   NORTH_EST},
    {EST_DEGREE,    SOUTH_DEGREE,   SOUTH_WEST},
    {-NORTH_DEGREE, EST_DEGREE,     NORTH_WEST},
};

    #define sizeof_array(array) (sizeof(array) / sizeof(array[0]))

typedef struct position_table_tail_s {
    int oriented;
    const char *position;
    char tail;
} position_table_tail_t;

    #define PLAYER_LOOK_NORTH 270
    #define PLAYER_LOOK_WEST 180
    #define PLAYER_LOOK_EST 0
    #define PLAYER_LOOK_SOUTH 90
    #define TAIL_1 '1'
    #define TAIL_2 '2'
    #define TAIL_3 '3'
    #define TAIL_4 '4'
    #define TAIL_5 '5'
    #define TAIL_6 '6'
    #define TAIL_7 '7'
    #define TAIL_8 '8'

static const position_table_tail_t POSITION_TABLE_TAIL[] = {
    {PLAYER_LOOK_EST, NORTH,        TAIL_7},
    {PLAYER_LOOK_EST, WEST,         TAIL_1},
    {PLAYER_LOOK_EST, EST,          TAIL_5},
    {PLAYER_LOOK_EST, SOUTH,        TAIL_3},
    {PLAYER_LOOK_EST, NORTH_WEST,   TAIL_4},
    {PLAYER_LOOK_EST, NORTH_EST,    TAIL_2},
    {PLAYER_LOOK_EST, SOUTH_WEST,   TAIL_6},
    {PLAYER_LOOK_EST, SOUTH_EST,    TAIL_8},

    {PLAYER_LOOK_SOUTH, NORTH,      TAIL_1},
    {PLAYER_LOOK_SOUTH, WEST,       TAIL_3},
    {PLAYER_LOOK_SOUTH, EST,        TAIL_7},
    {PLAYER_LOOK_SOUTH, SOUTH,      TAIL_5},
    {PLAYER_LOOK_SOUTH, NORTH_WEST, TAIL_6},
    {PLAYER_LOOK_SOUTH, NORTH_EST,  TAIL_4},
    {PLAYER_LOOK_SOUTH, SOUTH_WEST, TAIL_8},
    {PLAYER_LOOK_SOUTH, SOUTH_EST,  TAIL_2},

    {PLAYER_LOOK_WEST, NORTH,       TAIL_3},
    {PLAYER_LOOK_WEST, WEST,        TAIL_5},
    {PLAYER_LOOK_WEST, EST,         TAIL_1},
    {PLAYER_LOOK_WEST, SOUTH,       TAIL_7},
    {PLAYER_LOOK_WEST, NORTH_WEST,  TAIL_8},
    {PLAYER_LOOK_WEST, NORTH_EST,   TAIL_6},
    {PLAYER_LOOK_WEST, SOUTH_WEST,  TAIL_2},
    {PLAYER_LOOK_WEST, SOUTH_EST,   TAIL_4},

    {PLAYER_LOOK_NORTH, NORTH,      TAIL_5},
    {PLAYER_LOOK_NORTH, WEST,       TAIL_7},
    {PLAYER_LOOK_NORTH, EST,        TAIL_3},
    {PLAYER_LOOK_NORTH, SOUTH,      TAIL_1},
    {PLAYER_LOOK_NORTH, NORTH_WEST, TAIL_2},
    {PLAYER_LOOK_NORTH, NORTH_EST,  TAIL_8},
    {PLAYER_LOOK_NORTH, SOUTH_WEST, TAIL_4},
    {PLAYER_LOOK_NORTH, SOUTH_EST,  TAIL_6},
};

bool add_player_position(positions_t **positions,
client_t *client, char k);
void free_player_position(positions_t **positions);

char get_player_tile_sound(player_t *player, uint x, uint y, int oriented);
char *get_full_message(const char *text, char c);

#endif /* !BROADCAST_H_ */
