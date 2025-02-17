#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Player;

// declare singleton to use anywhere
Player* get_player();

#endif
