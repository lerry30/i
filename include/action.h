#ifndef ACTION_H
#define ACTION_H

#include <SDL2/SDL.h>
#include "singleton.h"

void handle_key_event(SDL_Event *);
void execute_actions(SDL_Renderer *);

#endif
