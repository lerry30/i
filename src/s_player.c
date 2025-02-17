#include "s_player.h"

static Player player_instance = {0};

Player* get_player() {
    return &player_instance;
}
