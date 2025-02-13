#include "graphics.h"
#include <stdio.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int init_sdl(void (*render)()) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) { // enable video related features(graphics, window creation)
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // create window
    window = SDL_CreateWindow("", // window title
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // x, y make center on screen
                                          800, 600, // window width and height
                                          SDL_WINDOW_SHOWN); // makes window visible
    if (!window) { // check if window is null
        SDL_Log("Could not create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // create renderer(canvas) where things(line, rectangle) are displayed or draw
    renderer = SDL_CreateRenderer(
            window, // which window to render things
            -1, // automatically selects the best graphic driver available
            SDL_RENDERER_ACCELERATED); // use hardware acceleration if available

    if (!renderer) { // check if renderer is null
        SDL_Log("Could not create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event; // stores events like mouse clicks or key presses
                     
    // Fixed Frame Rate (Cap at 60 FPS)
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart = 0;
    int frameTime;

    while(running) {
        frameStart = SDL_GetTicks();

        // there's a queue for events so this while loop process them one by one
        while(SDL_PollEvent(&event)) {  // Process all pending events
            if(event.type == SDL_QUIT) { // check if user tries to press close button to close, if so, the running will be set to false causing window to stop
                printf("close window\n");
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // configure the color(rgba) for renderer(canvas)
        SDL_RenderClear(renderer); // after configuring the color will apply to clear the renderer

        // Render things here...
        render(renderer); // callback function to draw things

        SDL_RenderPresent(renderer); // updates the screen to display what was drawn
                                     
        frameTime = SDL_GetTicks() - frameStart;

        // Delay to maintain 60 FPS
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    return 0;
}

void draw_line(int x1, int y1, int x2, int y2) {
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void draw_rect(int x, int y, int width, int height) {
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderFillRect(renderer, &rect);
}

void cleanup_sdl() {
    // cleanup by freeing memory
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
