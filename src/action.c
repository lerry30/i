#include "action.h"

void handle_key_event(SDL_Event *event) {
    InputState *input = get_input_state();
    
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
            case SDLK_SPACE:
                input->actions[0].active = 1;
                break;
        }
    }
}

void execute_actions(SDL_Renderer *renderer) {
    InputState *input = get_input_state();

    for (int i = 0; i < 10; i++) {
        if (input->actions[i].active) {
            input->actions[i].action(renderer);
        }
    }
}
