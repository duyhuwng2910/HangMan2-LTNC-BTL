#include "Input.h"

#include <iostream>
// PRIAVTE HELPER FUNCTIONS

using namespace std;

bool Inputs::check_for_quit(SDL_Event event) {

    if(event.type == SDL_QUIT) {
        return true;
    }

    if(event.type == SDL_KEYDOWN) {
        switch(event.key.keysym.sym) {
            case SDLK_ESCAPE:
                return true;
                break;
            default:
                break;
        }
    }

    return false;

}

// PUBLIC FUNCTIONS

Inputs::Inputs() {
    quit = false;
}

bool Inputs::isKeyDown(int key) {
    return keyStates[key];
}


void Inputs::Update() {

    clicked = false;

    keyStates = SDL_GetKeyboardState(NULL);

	SDL_Event event;

    while(SDL_PollEvent(&event) != 0) {

        // ESC or X button close the game
        if (check_for_quit(event)) {
            quit = true;
        }

        // Record mouse position when it moves
        if(event.type == SDL_MOUSEMOTION) {
            mouse_x = event.motion.x;
            mouse_y = event.motion.y;
            clicked = false;
        }


        if (event.type == SDL_MOUSEBUTTONUP) {
            clicked = true;
            cout << "clicked" << endl;
            break;
        }

        if (event.type == SDL_KEYDOWN) {
            pressed = true;
            cout << "Key is down" << endl;
        }

        if (event.type == SDL_KEYUP) {
            pressed = false;
            cout << "Key is up" << endl;
        }

    }

}


