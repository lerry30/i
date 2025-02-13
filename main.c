#include <stdio.h>
#include "graphics.h"
#include "math_utils.h"

void render(SDL_Renderer* renderer) {
    // Example usage of math functions
    double angle = 45.0;
    printf("sin(%f) = %f\n", angle, sine_deg(angle));

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    draw_line(100, 100, 400, 300);  // Draw a line using SDL

    SDL_SetRenderDrawColor(renderer, 0, 128, 128, 255);
    draw_rect(10, 10, 100, 100);  // Draw a rectangle
}

int main() {
    init_sdl(render);  // Initialize SDL from graphics.h
    cleanup_sdl();  // Cleanup SDL

    return 0;
}
