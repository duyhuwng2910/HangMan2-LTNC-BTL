#include "Animation.h"
#include "Resources.h"

// Check if mouse is inside
bool Animation::inside_button(const SDL_Rect* Shape, Inputs* input) {

    if (input->mouse_x >= Shape->x && input->mouse_x <= Shape->x + Shape->w && input->mouse_y <= Shape->y + Shape->h && input->mouse_y >= Shape->y) {

        return true;

    }

    return false;

}

void Animation::fade_before(SDL_Renderer *renderer, Resources *resources, string Name) {

    int i = 255;

    while (i > 0) {

        SDL_SetRenderDrawColor(renderer,0,0,0,255);

        SDL_RenderClear(renderer);

        SDL_SetTextureAlphaMod(resources->getTexture(Name,0),i);

        SDL_RenderCopy(renderer,resources->getTexture(Name,0),nullptr,&shape);

        SDL_Delay(5);

        i -= 5;

        SDL_RenderPresent(renderer);
    }

}

void Animation::fade_after(SDL_Renderer *renderer, Resources *resources, string Name) {

    int j = 0;

    while (j < 255) {

        SDL_SetRenderDrawColor(renderer,0,0,0,255);

        SDL_RenderClear(renderer);

        SDL_SetTextureAlphaMod(resources->getTexture(Name,0),j);

        SDL_RenderCopy(renderer,resources->getTexture(Name,0),nullptr,&shape);

        SDL_Delay(5);

        j += 5;

        SDL_RenderPresent(renderer);
    }

}

void Animation::Status_check(Inputs* input, Resources* resources, SDL_Renderer *renderer, Game_status &status, Render *R, long &score, Mix_Chunk *chunk) {

    if (inside_button(&PLAY_BUTTON,input)) {

        SDL_RenderCopy(renderer,resources->getTexture("PLAY_do_bong",0),nullptr,&shape);

        R->renderBestScore(renderer,resources);

        if (input->clicked) {

            status = PLAY_GAME_SUCCESS;

            chunk = Mix_LoadWAV("Sound/Option click.wav");

            Mix_PlayChannel(-1,chunk,0);

            fade_before(renderer,resources,"PLAY_do_bong");

            fade_after(renderer,resources,"Level");

        }

    }

    else if (inside_button(&HOW_TO_PLAY_BUTTON,input)) {

        SDL_RenderCopy(renderer,resources->getTexture("HOW_TO_PLAY_do_bong",0),nullptr,&shape);

        R->renderBestScore(renderer,resources);

        if (input->clicked) {

            status = HOW_TO_PLAY;

            chunk = Mix_LoadWAV("Sound/Option click.wav");

            Mix_PlayChannel(-1,chunk,0);

            fade_before(renderer,resources,"HOW_TO_PLAY_do_bong");

            fade_after(renderer,resources,"GUIDE");
        }

    }

    else if (inside_button(&EXIT_GAME_BUTTON,input)) {

        SDL_RenderCopy(renderer,resources->getTexture("EXIT_GAME_do_bong",0),nullptr,&shape);

        R->renderBestScore(renderer,resources);

        if (input->clicked) {

            status = EXIT_GAME_SUCCESS;

            chunk = Mix_LoadWAV("Sound/Option click.wav");

            Mix_PlayChannel(-1,chunk,0);

            fade_before(renderer,resources,"EXIT_GAME_do_bong");

            fade_after(renderer,resources,"QUIT");

        }

    }

    else {

        status = START_GAME;

    }

}

void Animation::Play_animation(Inputs* input, Resources* resources, SDL_Renderer *renderer, Game_status &status, Level &level, Mix_Chunk *chunk) {

    SDL_SetRenderDrawColor(renderer,0,0,0,255);

    SDL_RenderClear(renderer);

    SDL_SetTextureAlphaMod(resources->getTexture("Level",0),255);

    SDL_RenderCopy(renderer,resources->getTexture("Level",0),nullptr,&shape);

    Level_animation(input,resources,renderer,status,level,chunk);

}

void Animation::How_to_play_animation(Inputs* input, Resources* resources, SDL_Renderer *renderer, Game_status &status, Mix_Chunk *chunk) {

    SDL_RenderCopy(renderer,resources->getTexture("GUIDE",0),nullptr,&shape);

    if (input->clicked) {

        status = START_GAME;

        chunk = Mix_LoadWAV("Sound/Option click.wav");

        Mix_PlayChannel(-1,chunk,0);

        fade_before(renderer,resources,"GUIDE");

        fade_after(renderer,resources,"Main menu");
    }

}

void Animation::Exit_animation(Inputs* input, Resources* resources, SDL_Renderer *renderer, Game_status &status) {

    SDL_RenderCopy(renderer,resources->getTexture("QUIT",0),nullptr,&shape);

    if (input->pressed || input->clicked) {

        exit(0);

    }

}

void Animation::Level_animation(Inputs* input, Resources* resources, SDL_Renderer *renderer, Game_status &status, Level &level, Mix_Chunk *chunk) {

    if (inside_button(&VERY_EASY_LEVEL_BUTTON,input)) {

        SDL_RenderCopy(renderer,resources->getTexture("VERY EASY",0),nullptr,&shape);

        if (input->clicked) {

            level = VERY_EASY;

            status = CHOOSE_LEVEL_SUCCESS;

            chunk = Mix_LoadWAV("Sound/Level click.wav");

            Mix_PlayChannel(-1,chunk,0);

            fade_before(renderer,resources,"Level");

        }

    }

    else if (inside_button(&EASY_LEVEL_BUTTON,input)){

        SDL_RenderCopy(renderer,resources->getTexture("EASY",0),nullptr,&shape);

        if (input->clicked) {

            level = EASY;

            status = CHOOSE_LEVEL_SUCCESS;

            chunk = Mix_LoadWAV("Sound/Level click.wav");

            Mix_PlayChannel(-1,chunk,0);

            fade_before(renderer,resources,"Level");

        }

    }

    else if (inside_button(&MEDIUM_LEVEL_BUTTON,input)) {

        SDL_RenderCopy(renderer,resources->getTexture("MEDIUM",0),nullptr,&shape);

        if (input->clicked) {

            level = MEDIUM;

            status = CHOOSE_LEVEL_SUCCESS;

            chunk = Mix_LoadWAV("Sound/Level click.wav");

            Mix_PlayChannel(-1,chunk,0);

            fade_before(renderer,resources,"Level");

        }

    }

    else if (inside_button(&HARD_LEVEL_BUTTON,input)) {

        SDL_RenderCopy(renderer,resources->getTexture("HARD",0),nullptr,&shape);

        if (input->clicked) {

            level = HARD;

            status = CHOOSE_LEVEL_SUCCESS;

            chunk = Mix_LoadWAV("Sound/Level click.wav");

            Mix_PlayChannel(-1,chunk,0);

            fade_before(renderer,resources,"Level");

        }

    }

    else if (inside_button(&EXTREMELY_HARD_BUTTON,input)) {

        SDL_RenderCopy(renderer,resources->getTexture("EXTREMELY HARD",0),nullptr,&shape);

        if (input->clicked) {

            level = EXTREMELY_HARD;

            status = CHOOSE_LEVEL_SUCCESS;

            chunk = Mix_LoadWAV("Sound/Level click.wav");

            Mix_PlayChannel(-1,chunk,0);

            fade_before(renderer,resources,"Level");

        }
    }

    else {

        SDL_RenderCopy(renderer,resources->getTexture("Level",0),nullptr,&shape);

    }

}
