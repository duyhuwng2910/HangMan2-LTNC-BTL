#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL.h>
#include <cstring>
#include "Resources.h"
#include "Input.h"
#include "Render_game.h"
#include "Sound.h"

class Animation {

public:

    // Check if mouse is inside the button
    bool inside_button(const SDL_Rect* Shape, Inputs* input);

    // Kiem tra trang thai cua game
    void Status_check(Inputs *input, Resources *resources, SDL_Renderer *renderer, Game_status &status, Render *R, long &score, Mix_Chunk *chunk);

    // tao hieu ung chuyen canh truoc
    void fade_before(SDL_Renderer *renderer, Resources *resources, string Name);

    // tao hieu ung chuyen canh sau
    void fade_after(SDL_Renderer *renderer, Resources *resources, string Name);

    // do bong menu
    void Play_animation(Inputs *input, Resources *resources, SDL_Renderer *renderer, Game_status &status, Level &level, Mix_Chunk *chunk);

    // do bong how to play
    void How_to_play_animation(Inputs *input, Resources *resources, SDL_Renderer *renderer, Game_status &status, Mix_Chunk *chunk);

    // do bong exit game
    void Exit_animation(Inputs *input, Resources *resources, SDL_Renderer *renderer, Game_status &status);

    // Chuyen canh level
    void Level_animation(Inputs *input, Resources *resources, SDL_Renderer *renderer, Game_status &status, Level &level, Mix_Chunk *chunk);

};

#endif // ANIMATION_H
