#ifndef RESOURCES_H
#define RESOURCES_H

#include <map>
#include <cstring>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;

const SDL_Rect shape = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};



// PIXEL OF MENU
const SDL_Rect PLAY_BUTTON = {70,278,76,35};

const SDL_Rect BEST_SCORE_BUTTON = {70,375,192,35};

const SDL_Rect HOW_TO_PLAY_BUTTON = {70,475,203,35};

const SDL_Rect EXIT_GAME_BUTTON = {70,575,164,35};

// PIXEL OF LEVEL
const SDL_Rect VERY_EASY_LEVEL_BUTTON = {70,250,158,30};

const SDL_Rect EASY_LEVEL_BUTTON = {70,345,75,30};

const SDL_Rect MEDIUM_LEVEL_BUTTON = {70,440,115,30};

const SDL_Rect HARD_LEVEL_BUTTON = {70,535,80,30};

const SDL_Rect EXTREMELY_HARD_BUTTON = {70,630,258,30};

const SDL_Rect YES = {230,390,240,40};

const SDL_Rect NO = {866,390,295,40};

const SDL_Color WHITE = {255,255,255};

const SDL_Rect reach_record = {475,495,860,45};

const SDL_Rect breaking_record = {470,495,870,45};

const SDL_Rect lose = {80,555,430,45};

enum Game_status {

    START_GAME,
    PLAY_GAME_SUCCESS,
    HOW_TO_PLAY,
    EXIT_GAME,
    EXIT_GAME_SUCCESS,
    CHOOSE_LEVEL_SUCCESS,
    NO_MORE_PLAY

};

enum Level {

    VERY_EASY,
    EASY,
    MEDIUM,
    HARD,
    EXTREMELY_HARD

};

class Resources {

public:

    TTF_Font *font1, *font2, *font3;
    SDL_Renderer* renderer;
    map<string, map<int,SDL_Texture*>> textures;

    Resources(SDL_Renderer* _renderer);
    ~Resources();
    void loadTexture(SDL_Texture **texture, string file_path);

    void loadResources();

    SDL_Texture* getTexture(string name, int frame);

};

#endif // RESOURCES_H
