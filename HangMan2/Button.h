#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <cstring>
#include "Resources.h"
#include "Input.h"
#include "Animation.h"

using namespace std;

class Button {

public:

    SDL_Rect buttonShape;
    string buttonName;
    string screenName;
    bool choosen = false;

    Button(int x, int y, int w, int h, string _buttonName);

    // render button
    void render_Button(SDL_Renderer *renderer, Resources *resources);

};

#endif // BUTTON_H

