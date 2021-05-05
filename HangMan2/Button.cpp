#include "Button.h"

Button::Button(int x, int y, int w, int h, string _buttonName) {

    buttonShape.x = x;
    buttonShape.y = y;
    buttonShape.w = w;
    buttonShape.h = h;
    this->buttonName = _buttonName;

}

void Button::render_Button(SDL_Renderer* renderer, Resources* resources) {

    if(!choosen) {

        SDL_RenderCopy(renderer,resources->getTexture(buttonName,0),nullptr,&buttonShape);

    }

}
//
//bool Button::choosen_Button(Inputs *input, Animation *Temp) {
//
//
//
//    if ((Temp->inside_button(&buttonShape,input) && (input->clicked)) || input->isKeyDown((int)buttonName[0] - 61)) {
//        return true;
//    }
//    return false;
//}


