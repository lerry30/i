#ifndef S_INPUT_STATE_H
#define S_INPUT_STATE_H

typedef struct {
    void (*action)();
    int active;
} Action;

typedef struct {
    Action actions[10];
} InputState;

// declare singleton to use it anywhere
InputState* get_input_state();

#endif
