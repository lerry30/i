#include "s_input_state.h"

static InputState input_state_instance = {0};

InputState* get_input_state() {
    return &input_state_instance;
}
