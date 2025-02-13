#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>

int init_sdl(void (*render)());
void cleanup_sdl();
void draw_line(int x1, int y1, int x2, int y2);
void draw_rect(int x, int y, int width, int height);

#endif
