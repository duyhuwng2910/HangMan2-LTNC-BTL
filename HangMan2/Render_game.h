#ifndef RENDER_GAME_H
#define RENDER_GAME_H

#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <SDL_ttf.h>
#include "Resources.h"

class  Render {
public:
    long score;

    Render(long _score);

    // render hinh anh tuong ung voi so luot doan con lai cua nguoi choi, duoc update sau moi lan doan tu
    void renderGame(int &badGuessCount, SDL_Renderer *renderer, Resources *resources);

    // dung ttf viet so diem cao nhat tai Main menu
    void renderBestScore(SDL_Renderer *renderer, Resources *resources);

};
#endif // RENDER_GAME_H
