#include "Render_game.h"
#include <fstream>

using namespace std;

Render::Render(long _score) {

    score = _score;

}

// render hinh anh tuong ung voi so luot doan con lai cua nguoi choi, duoc update sau moi lan doan tu
void Render::renderGame(int &badGuessCount, SDL_Renderer *renderer, Resources *resources) {
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderClear(renderer);

    SDL_SetTextureAlphaMod(resources->getTexture("Hangman2", badGuessCount + 1), 255);
    
    SDL_RenderCopy(renderer,resources->getTexture("Hangman2",badGuessCount + 1),nullptr,&shape);

}

// dung ttf viet so diem cao nhat tai Main menu
void Render::renderBestScore(SDL_Renderer *renderer, Resources *resources) {

    string best; // to print best score

    ifstream Myfile("Score/Best_score.txt");

    if (Myfile.is_open()) {
        while (getline(Myfile,best)) {
            Myfile >> best;
        }
        Myfile.close();
    }
    else {
        cout << "Unable to open file.";
    }

    stringstream ss(best);

    int temp;

    ss >> temp;

    if (score > temp) {

        fstream Update("Score/Best_score.txt");

        while(getline(Update,best)){
            Update >> best;
        }

        if (Update.is_open()) {
            Update << score;
            Update.close();
        }
        else {
            cout << "Unable to open file." << endl;
        }

        best = to_string(score);

        char const *BEST = best.c_str();

        SDL_Surface *best_score = TTF_RenderText_Solid(resources->font1,BEST,WHITE);

        SDL_Texture *IMAGE = SDL_CreateTextureFromSurface(renderer,best_score);

        int iW,iH;

        SDL_QueryTexture(IMAGE,NULL,NULL, &iW, &iH);

        SDL_Rect tempShape = {270,373, iW, iH};

        SDL_RenderCopy(renderer,IMAGE,nullptr,&tempShape);
    }

    else {

        char const *BEST = best.c_str();

        SDL_Surface *best_score = TTF_RenderText_Solid(resources->font1 ,BEST,WHITE);

        SDL_Texture *IMAGE = SDL_CreateTextureFromSurface(renderer,best_score);

        int iW, iH;

        SDL_QueryTexture(IMAGE,NULL,NULL, &iW, &iH);

        SDL_Rect tempShape = {270, 373, iW, iH};

        SDL_RenderCopy(renderer,IMAGE,nullptr,&tempShape);
    }

}
