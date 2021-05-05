#ifndef GAME_RUN_PROCESS_H
#define GAME_RUN_PROCESS_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "time.h"
#include "Button.h"
#include "Resources.h"
#include "Score/Update_Best_Score.h"
#include "Score/Update_Score.h"
#include "Render_game.h"
#include "Choose_Word.h"
#include "Animation.h"
#include "Input.h"
#include "Sound.h"

const int GUESS_NUM = 14;

// gameState nho de quan ly duoi dang switch case
enum gameState {
    PLAY,
    RESULT,
    OPTION,
    CONTINUE,
    STOP
};

class gameRunProcess {

public:
    // Cac bien su dung cho qua trinh choi game
    int badGuessCount = 0;

    long score = 0;

    Level *level;

    string word, guessedWord;

    vector<char> check_letter;

    Inputs *input;

    Game_status *status;

    gameRunProcess(Game_status *_status, int _badGuesscount, long &_score, Level *_level, string _word, string _guessedWord, vector<char> _check_letter, Inputs *_input) {

        status = _status;
        badGuessCount = _badGuesscount;
        score = _score;
        level = _level;
        word = _word;
        guessedWord = _guessedWord;
        check_letter = _check_letter;
        input = _input;

    }

    //Cac ham phuc vu qua trinh game chay

    // ham nhan viec chon letter doan bang ban phim
    char readAGuess(vector<Button*> *button, Inputs *input, Animation *Temp);

    // kiem tra xem chu cai vua doan co xuat hien trong tu can doan khong
    bool contains(string word, char guess);

    // them chu cai doan dung vao guessedWord
    string update(string guessedWord, const string word, char guess);

    // qua trinh chay game (ham chinh cua qua trinh chay game)
    void gameRun(SDL_Renderer *renderer, Resources *resources, Animation *Temp, Render *render, vector <Button*> *button, gameState *gameState, Mix_Chunk *chunk);

    // dung ttf viet guessedWord
    void typing_guessed_word(SDL_Renderer *renderer, Resources *resources);

    // dung ttf viet thong bao doan dung chu cai
    void typing_correct_guess_announcement(SDL_Renderer *renderer, Resources *resources);

    // dung ttf viet thong bao doan sai chu cai
    void typing_wrong_guess_announcement(SDL_Renderer *renderer, Resources *resources);

    // dung ttf viet cac chu cai da doan de nguoi choi khong chon lai
    void guessed_letters(SDL_Renderer *renderer, Resources *resources);

    // dung ttf dua ra thong bao khi nguoi choi con lai 2 luot doan tu
    void warning_announcement(SDL_Renderer *renderer, Resources *resources, Mix_Chunk* chunk);

    // render hinh anh an mung khi doan dung
    void celebration(bool win, SDL_Renderer *renderer, Resources *resources, Mix_Chunk *chunk);

    // render ket qua doan tu, bao gom doan dung, doan sai, thong bao so diem hien tai, co pha record khong
    void displayFinalResult(bool win, SDL_Renderer *renderer, Resources *resources, Animation *Temp, Render *render, gameState *gameState);

    // dua ra lua chon choi tiep hay khong
    void option(SDL_Renderer *renderer, Resources *resources, Animation *Temp, gameState *gameState, Mix_Chunk *chunk);
};

#endif // GAME_RUN_PROCESS_H
