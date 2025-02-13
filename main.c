#include <stdio.h>
#include "graphics.h"
#include "math_utils.h"

void render() {
    // Example usage of math functions
    double angle = 45.0;
    printf("sin(%f) = %f\n", angle, sine_deg(angle));

    draw_line(100, 100, 400, 300);  // Draw a line using SDL
    
    draw_rect(10, 10, 100, 100);

    SDL_Delay(3000);
}

int main() {
    init_sdl(render);  // Initialize SDL from graphics.h
    cleanup_sdl();  // Cleanup SDL

    return 0;
}
