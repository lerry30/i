#include <stdio.h>
#include "graphics.h"
#include "action.h"
#include "math_utils.h"
#include "singleton.h"

void draw_rectangle(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 128, 128, 255);
    draw_rect(10, 10, 30, 30);  // Draw a rectangle
}

void render(SDL_Renderer* renderer) {
    // Example usage of math functions
    //double angle = 45.0;
    //printf("sin(%f) = %f\n", angle, sine_deg(angle));

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    draw_line(100, 100, 400, 300);  // Draw a line using SDL

    execute_actions(renderer);
}

int main() {
    InputState *input = get_input_state();
    input->actions[0].action = draw_rectangle;

    init_sdl(render, handle_key_event); // Initialize SDL from graphics.h
    cleanup_sdl();  // Cleanup SDL

    return 0;
}
