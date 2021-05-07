#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <cstring>
#include <iostream>
#include <vector>
#include "Button.h"
#include "Choose_Word.h"
#include "Game_run_process.h"
#include "Score/Update_Score.h"
#include "Score/Update_Best_Score.h"
#include "Animation.h"
#include "Render_game.h"
#include "Sound.h"

using namespace std;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//bool init(vector <Button*> *button) {
bool init() {

    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {

        cout << "SDL could not initialize! SDL Error: %s\n" << SDL_GetError() << endl;

        success = false;

    }

    else {

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

        if( gWindow == NULL ) {

            cout << "Window could not be created! SDL Error: %s\n" << SDL_GetError() << endl;

            success = false;

        }

        else {
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;

            if( !( IMG_Init( imgFlags ) & imgFlags ) ) {

                cout << "SDL_image could not initialize! SDL_image Error: %s\n" << IMG_GetError() << endl;

                success = false;

            }

        }

    }

    if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) == -1) {

        cout << Mix_GetError() << endl;

    }

    return success;

}

void close() {
	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] ) {

    init();

    SDL_Renderer *renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    Mix_Chunk* chunk = NULL;

    Mix_Music* music = NULL;

    Sound game_sound(music,chunk);

    bool game_running = true;

    // Cac bien su dung cho qua trinh choi game

    int badGuessCount = 0;

    long score = 0;

    Level level;

    string word, guessedWord;

    vector<Button*> button;
    //Init the button
    int _x = 200, _y = 450;
    string temp;

    for (char element = 'A'; element <= 'I'; element++) {
        temp = element;
        button.push_back(new Button(_x, _y, 50, 50, temp));
        _x += 60;
    }
    _x = 200;
    _y = 510;

    for (char element = 'J'; element <= 'R'; element++) {
        temp = element;
        button.push_back(new Button(_x, _y, 50, 50, temp));
        _x += 60;
    }
    _x = 230;
    _y = 570;

    for (char element = 'S'; element <= 'Z'; element++) {
        temp = element;
        button.push_back(new Button(_x, _y, 50, 50, temp));
        _x += 60;
    }
    vector<char> check_letter;

    Inputs *input = new Inputs;

    Animation Game;

    Resources resources(renderer);

    gameState gameState = PLAY;

    Game_status status = LOADING;

    gameRunProcess game_run(&status,badGuessCount,score,&level,word,guessedWord,check_letter,input);

    Render render(score);

    //While application is running
    while( game_running ) {

        input->Update();
        game_running = !input->quit;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //Game.fade_after(renderer, &resources, "Main menu");
        
        switch (status) {
            
            case LOADING:
                
                Game.fade_after(renderer,&resources, "Main menu");
                
                chunk = Mix_LoadWAV("Sound/Start Game.wav");

                Mix_PlayChannel(-1, chunk, 0);

                status = START_GAME;

            case START_GAME:
            case NO_MORE_PLAY:

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

                SDL_RenderClear(renderer);

                SDL_SetTextureAlphaMod(resources.getTexture("Main menu", 0), 255);

                SDL_RenderCopy(renderer,resources.getTexture("Main menu",0),nullptr,&shape);
                
                score = 0;

                render.renderBestScore(renderer,&resources);

                Game.Status_check(input,&resources,renderer,status,&render,score,chunk);

                break;

            case PLAY_GAME_SUCCESS:

                Game.Play_animation(input,&resources,renderer,status,level,chunk);

                break;

            case CHOOSE_LEVEL_SUCCESS:

                game_run.gameRun(renderer,&resources,&Game,&render,&button,&gameState,chunk);

                break;

            case HOW_TO_PLAY:

                Game.How_to_play_animation(input,&resources,renderer,status,chunk);

                break;

            case EXIT_GAME:

                Game.Exit_animation(input,&resources,renderer,status);

                break;

            case EXIT_GAME_SUCCESS:

                Game.Exit_animation(input,&resources,renderer,status);

                break;

        }

        SDL_RenderPresent(renderer);

    }

    close();

	return 0;

}




