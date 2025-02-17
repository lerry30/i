#include <stdio.h>
#include "graphics.h"
#include "action.h"
#include "math_utils.h"

#include "s_input_state.h"
#include "s_player.h"

void draw_player(SDL_Renderer *renderer) {
    Player *player = get_player();
    SDL_SetRenderDrawColor(renderer, 0, 128, 128, 255);
    draw_rect(
        player->x,
        player->y,
        player->width,
        player->height
    );  // Draw a rectangle
}

void render(SDL_Renderer* renderer) {
    // Example usage of math functions
    //double angle = 45.0;
    //printf("sin(%f) = %f\n", angle, sine_deg(angle));

    //SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    //draw_line(100, 100, 400, 300);  // Draw a line using SDL

    draw_player(renderer);

    // it help to render thing when key is pressed
    //execute_actions(renderer);
}

int main() {
    // setting singleton for key input and the event
    //InputState *input = get_input_state();
    //input->actions[0].action = function_to_draw;

    // singleton for player config
    Player* player = get_player();
    player->x = 300;
    player->y = 200;
    player->width = 30;
    player->height = 30;

    init_sdl(render, handle_key_event); // Initialize SDL from graphics.h
    cleanup_sdl();  // Cleanup SDL

    return 0;
}
