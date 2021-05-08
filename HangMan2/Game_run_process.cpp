#include "Game_run_process.h"

using namespace std;

// ham nhan viec chon letter doan bang ban phim
char gameRunProcess::readAGuess(vector<Button*> *button, Inputs *input, Animation *Temp) {

    for (int i = 0; i < button->size(); i++) {

        //if (input->isKeyDown(int((*button)[i]->buttonName[0]) - 61)){
        if (Temp->inside_button(&((*button)[i]->buttonShape),input)) {

            if(input->clicked && (!(*button)[i]->choosen)){                        
                (*button)[i]->choosen = true;
                return (*button)[i]->buttonName[0];
            }
        }
    }

    return '-';
}

// kiem tra xem chu cai vua doan co xuat hien trong tu can doan khong
bool gameRunProcess::contains(string word, char guess) { // check whether the letter guessed was appeared in this word

    int length = word.length();
    for (int i = 0; i < length; i++) {
        if (guess == word[i]) {
            return true;
        }
    }
    return false;
}

// them chu cai doan dung vao guessedWord
string gameRunProcess::update(string guessedWord, string word, char guess) { // update the letter was guessed correctly
    for (int i = 0; i < word.length(); i++) {
        if (guess == word[i]) {
            guessedWord[i] = word[i];
        }
    }
    return guessedWord;
}

// dung ttf viet guessedWord
void gameRunProcess::typing_guessed_word(SDL_Renderer *renderer, Resources *resources) {

    const char *tgw = guessedWord.c_str();

    SDL_Surface *tgw_surface = TTF_RenderText_Solid(resources->font3,tgw,WHITE);

    SDL_Texture *tgw_texture = SDL_CreateTextureFromSurface(renderer,tgw_surface);

    int tgw_W,tgw_H;

    SDL_QueryTexture(tgw_texture,NULL,NULL,&tgw_W,&tgw_H);

    SDL_Rect tgw_rect = {200,275,tgw_W,tgw_H};

    SDL_RenderCopy(renderer,tgw_texture,nullptr,&tgw_rect);

    SDL_FreeSurface(tgw_surface);

    SDL_DestroyTexture(tgw_texture);

}

// dung ttf viet thong bao doan dung chu cai
void gameRunProcess::typing_correct_guess_announcement(SDL_Renderer *renderer, Resources *resources) {

    int rest_tries = GUESS_NUM - badGuessCount;

    string rest_tries_string = to_string(rest_tries);

    string p1 = "You have found a letter. You have ", p2;

    if (rest_tries >= 2) {
        p2 = " tries left.";
    }

    else {
        p2 = " try left.";
    }

    string full = p1 + rest_tries_string + p2;

    char const *restTries = full.c_str();

    SDL_Surface *tcga_surface = TTF_RenderText_Solid(resources->font2,restTries,WHITE);

    SDL_Texture *tcga_texture = SDL_CreateTextureFromSurface(renderer,tcga_surface);

    int tcga_W,tcga_H;

    SDL_QueryTexture(tcga_texture,NULL,NULL,&tcga_W,&tcga_H);

    SDL_Rect tcga_rect = {80,125,tcga_W,tcga_H};

    SDL_RenderCopy(renderer,tcga_texture,nullptr,&tcga_rect);

    SDL_Delay(100);

    SDL_FreeSurface(tcga_surface);

    SDL_DestroyTexture(tcga_texture);

}

// dung ttf viet thong bao doan sai chu cai
void gameRunProcess::typing_wrong_guess_announcement(SDL_Renderer *renderer, Resources *resources) {

    int rest_tries = GUESS_NUM - badGuessCount;
    
    SDL_Delay(100);

    string rest_tries_string = to_string(rest_tries);

    string p1 = "You have guessed wrong. You have ",p2;

    if (rest_tries >= 2) {
        p2 = " tries left.";
    }

    else {
        p2 = " try left.";
    }

    string full = p1 + rest_tries_string + p2;

    char const *restTries = full.c_str();

    SDL_Surface *twga_surface = TTF_RenderText_Solid(resources->font2,restTries,WHITE);

    SDL_Texture *twga_texture = SDL_CreateTextureFromSurface(renderer,twga_surface);

    int twga_W,twga_H;

    SDL_QueryTexture(twga_texture,NULL,NULL,&twga_W,&twga_H);

    SDL_Rect twga_rect = {80,125,twga_W,twga_H};

    SDL_RenderCopy(renderer,twga_texture,nullptr,&twga_rect);

    SDL_FreeSurface(twga_surface);

    SDL_DestroyTexture(twga_texture);

}

// dung ttf viet cac chu cai da doan de nguoi choi khong chon lai
void gameRunProcess::guessed_letters(SDL_Renderer *renderer, Resources *resources) {

    SDL_Surface *gl_surface = TTF_RenderText_Solid(resources->font2,"Letters were guessed: ",WHITE);

    SDL_Texture *gl_texture = SDL_CreateTextureFromSurface(renderer,gl_surface);

    int gl_W,gl_H;

    SDL_QueryTexture(gl_texture,NULL,NULL,&gl_W,&gl_H);

    SDL_Rect gl_rect = {80,175,gl_W,gl_H};

    SDL_RenderCopy(renderer,gl_texture,nullptr,&gl_rect);

    string guessedLetters;

    for (int i = 0; i < check_letter.size(); i++) {
        guessedLetters = guessedLetters + check_letter[i] + " ";
    }

    char const *logt = guessedLetters.c_str();

    SDL_Surface *logt_surface = TTF_RenderText_Solid(resources->font2,logt,WHITE);

    SDL_Texture *logt_texture = SDL_CreateTextureFromSurface(renderer,logt_surface);

    int logt_W,logt_H;

    SDL_QueryTexture(logt_texture,NULL,NULL,&logt_W,&logt_H);

    SDL_Rect logt_rect = {80,225,logt_W,logt_H};

    SDL_RenderCopy(renderer,logt_texture,nullptr,&logt_rect);

    SDL_FreeSurface(logt_surface);

    SDL_DestroyTexture(logt_texture);

}

// dung ttf dua ra thong bao khi nguoi choi con lai 2 luot doan tu
void gameRunProcess::warning_announcement(SDL_Renderer *renderer, Resources *resources, Mix_Chunk* chunk) {

    SDL_Surface *wa_surface = TTF_RenderText_Solid(resources->font2,"Be careful, You seem to be hung",WHITE);

    SDL_Texture *wa_texture = SDL_CreateTextureFromSurface(renderer,wa_surface);

    int wa_W,wa_H;

    SDL_QueryTexture(wa_texture,NULL,NULL,&wa_W,&wa_H);

    SDL_Rect wa_rect = {175,70,wa_W,wa_H};

    if (GUESS_NUM - badGuessCount <= 5) {

        SDL_RenderCopy(renderer,wa_texture,nullptr,&wa_rect);

        chunk = Mix_LoadWAV("Sound/Warning Announcement.wav");

        Mix_PlayChannel(-1, chunk, 0);

    }

    Mix_PlayChannel(-1, chunk, 0);

    SDL_FreeSurface(wa_surface);

    SDL_DestroyTexture(wa_texture);

}

// render hinh anh an mung khi doan dung
void gameRunProcess::celebration(bool win, SDL_Renderer *renderer, Resources *resources, Mix_Chunk *chunk) {

    if (win) {

        chunk = Mix_LoadWAV("Sound/Celebration.wav");

        Mix_PlayChannel(-1,chunk,0);

        for (int i = 0; i < 18; i++) {

            SDL_RenderCopy(renderer,resources->getTexture("Congrate",i),nullptr,&shape);

            SDL_Delay(200);

            SDL_RenderPresent(renderer);

        }

        int a = 255;

        while (a > 0) {

            SDL_SetRenderDrawColor(renderer,0,0,0,255);

            SDL_RenderClear(renderer);

            SDL_SetTextureAlphaMod(resources->getTexture("Congrate",17),a);

            SDL_RenderCopy(renderer,resources->getTexture("Congrate",17),nullptr,&shape);

            SDL_Delay(5);

            a -= 5;

            SDL_RenderPresent(renderer);

        }

    }

    else {

        chunk = Mix_LoadWAV("Sound/Game over.wav");

        Mix_PlayChannel(-1,chunk,0);

    }

}

// render ket qua doan tu, bao gom doan dung, doan sai, thong bao so diem hien tai, co pha record khong
void gameRunProcess::displayFinalResult(bool win, SDL_Renderer *renderer, Resources *resources, Animation *Temp, Render *render, gameState *gameState) {

    int temp;
    string best;

	ifstream Myfile("Score/Best_score.txt");

    if (Myfile.is_open()) {
        while (getline(Myfile,best)) {
            Myfile >> best;
        }
        Myfile.close();
    }

    else {
        cout << "Unable to open file." << endl;
    }

    stringstream ss(best);

    ss >> temp;

    cout << "last best score: " << temp << endl;

    if (score > temp) {

        temp = score;

        ofstream Update("Score/Best_score.txt");

        if (Update.is_open()) {
            Update << score;
            Update.close();
        }
    }

    cout << "current best score: " << score << endl;

    string rS_String = to_string(score);

    cout << rS_String << endl;

    const char *rS_result = rS_String.c_str();

    SDL_Surface *rS_surface = TTF_RenderText_Solid(resources->font3,rS_result,WHITE);

    SDL_Texture *rS_texture = SDL_CreateTextureFromSurface(renderer,rS_surface);

    int rS_W,rS_H;

    SDL_QueryTexture(rS_texture,NULL,NULL,&rS_W,&rS_H);

    if (win) {

        if (score == temp) {

            Temp->fade_after(renderer,resources,"WIN_REACH_RECORD");

            SDL_Rect rS_rect = {920,285,rS_W,rS_H};

            SDL_RenderCopy(renderer,rS_texture,nullptr,&rS_rect);

            SDL_RenderPresent(renderer);

            SDL_RenderCopy(renderer,resources->getTexture("WIN_REACH_RECORD",0),nullptr,&shape);
            
            input->Update();

            if (Temp->inside_button(&reach_record,input)) {

                SDL_RenderCopy(renderer,resources->getTexture("WIN_REACH_RECORD_do_bong",0),nullptr,&shape);

            }

            SDL_Delay(3500);

            Temp->fade_before(renderer,resources,"WIN_REACH_RECORD");

        }

        else if (score > temp) {

            Temp->fade_after(renderer,resources,"WIN_BREAKING_RECORD");

            SDL_Rect rS_rect = {920,285,rS_W,rS_H};

            SDL_RenderCopy(renderer,rS_texture,nullptr,&rS_rect);

            SDL_RenderPresent(renderer);

            SDL_RenderCopy(renderer,resources->getTexture("WIN_BREAKING_RECORD",0),nullptr,&shape);
            
            input->Update();

            if (Temp->inside_button(&breaking_record,input)) {

                SDL_RenderCopy(renderer,resources->getTexture("WIN_BREAKING_RECORD_do_bong",0),nullptr,&shape);

            }

            SDL_Delay(3500);

            Temp->fade_before(renderer,resources,"WIN_BREAKING_RECORD");

        }

        else {

            Temp->fade_after(renderer,resources,"WIN");

            SDL_Rect rS_rect = {920,285,rS_W,rS_H};

            SDL_RenderCopy(renderer,rS_texture,nullptr,&rS_rect);

            SDL_RenderPresent(renderer);

            SDL_RenderCopy(renderer,resources->getTexture("WIN",0),nullptr,&shape);

            SDL_Delay(3500);

            Temp->fade_before(renderer,resources,"WIN");

        }

    }

    else {

        Temp->fade_after(renderer,resources,"LOSE");

        SDL_Rect rS_rect = {580,520,rS_W,rS_H};

        SDL_RenderCopy(renderer,rS_texture,nullptr,&rS_rect);

        SDL_RenderPresent(renderer);

        const char *w = word.c_str();

        SDL_Surface *w_surface = TTF_RenderText_Solid(resources->font3,w,WHITE);

        SDL_Texture *w_texture = SDL_CreateTextureFromSurface(renderer,w_surface);

        int w_W, w_H;

        SDL_QueryTexture(w_texture,NULL,NULL,&w_W,&w_H);

        SDL_Rect w_rect = {180,375,w_W,w_H};

        SDL_RenderCopy(renderer,w_texture,nullptr,&w_rect);

        SDL_RenderPresent(renderer);

        SDL_RenderCopy(renderer,resources->getTexture("LOSE",0),nullptr,&shape);
        
        input->Update();

        if (Temp->inside_button(&lose,input)) {

            SDL_RenderCopy(renderer,resources->getTexture("LOSE_do_bong",0),nullptr,&shape);

        }

        SDL_Delay(3500);

        Temp->fade_before(renderer,resources,"LOSE");

    }

        SDL_FreeSurface(rS_surface);

        SDL_DestroyTexture(rS_texture);


}

// dua ra lua chon choi tiep hay khong
void gameRunProcess::option(SDL_Renderer *renderer, Resources *resources, Animation *Temp, gameState *gameState, Mix_Chunk *chunk) {

    //Temp->fade_after(renderer,resources,"Option");

    //SDL_RenderPresent(renderer);

    SDL_SetRenderDrawColor(renderer,0,0,0,255);

    SDL_RenderClear(renderer);

    SDL_SetTextureAlphaMod(resources->getTexture("Option",0),255);

    SDL_RenderCopy(renderer,resources->getTexture("Option",0),nullptr,&shape);

    input->Update();

    if (Temp->inside_button(&YES,input)) {

        SDL_RenderCopy(renderer,resources->getTexture("YES",0),nullptr,&shape);

        if (input->clicked) {

            chunk = Mix_LoadWAV("Sound/Option click.wav");

            Mix_PlayChannel(-1,chunk,0);

            *gameState = CONTINUE;

            Temp->fade_before(renderer,resources,"Option");

            Temp->fade_after(renderer,resources,"Level");

        }

        else {

            *gameState = OPTION;

        }

        SDL_RenderPresent(renderer);

    }

    else if (Temp->inside_button(&NO,input)) {

        SDL_RenderCopy(renderer,resources->getTexture("NO",0),nullptr,&shape);

        if (input->clicked) {

            chunk = Mix_LoadWAV("Sound/Option click.wav");

            Mix_PlayChannel(-1,chunk,0);

            *gameState = STOP;

            Temp->fade_before(renderer,resources,"Option");

            Temp->fade_after(renderer,resources,"Main menu");

        }

        else {

            *gameState = OPTION;

        }

    }

    SDL_RenderPresent(renderer);

}

// qua trinh chay game (ham chinh cua qua trinh chay game)
void gameRunProcess::gameRun(SDL_Renderer *renderer, Resources *resources, Animation *Temp, Render *render, vector<Button*> *button, gameState *gameState, Mix_Chunk *chunk){

    // bat dau qua trinh choi game
    while (*status == CHOOSE_LEVEL_SUCCESS) {

        // quan ly su kien bang bien gameState
        switch (*gameState) {

            case PLAY: {

                // khoi tao tu can doan
                srand(time(0));
                word = chooseWord(*level);
                guessedWord = string(word.length(),'-');
                badGuessCount = 0;
                char guess;
                check_letter.clear();

                for (int i = 0; i < button->size(); i++) {

                    (*button)[i]->choosen = false;

                }

                cout << "word: " << word << endl << "declared guessedWord: " << guessedWord << endl;

                // Chuyen canh vao game
                Temp->fade_after(renderer,resources,"VAO GAME");

                SDL_Delay(500);

                Temp->fade_before(renderer,resources,"VAO GAME");

                Temp->fade_after(renderer,resources,"Hangman2");

                // Set up button, anh va tu
                SDL_RenderCopy(renderer,resources->getTexture("Hangman2",0),nullptr,&shape);

                typing_guessed_word(renderer,resources);

                    do {

                        input->Update();

                        for (int i = 0; i < button->size(); i++) {

                            (*button)[i]->render_Button(renderer,resources);

                        }

                        SDL_RenderPresent(renderer);

                        guess = readAGuess(button,input,Temp);

                        if (guess == '-') {

                            continue;

                        }

                        cout << "guess: " << guess << endl;

                        check_letter.push_back(guess);

                        // Neu doan dung chu cai
                        if (contains(word,guess)) {

                            chunk = Mix_LoadWAV("Sound/Correct guess.wav");

                            Mix_PlayChannel(-1,chunk,0);

                            render->renderGame(badGuessCount,renderer,resources);

                            typing_correct_guess_announcement(renderer,resources);

                            guessed_letters(renderer,resources);
                            
                            cout << "[guessedWord] = " << guessedWord << endl;
                            
                            guessedWord = update(guessedWord,word,guess);

                            typing_guessed_word(renderer,resources);

                        }

                        // Neu chu cai ban chon khong co trong word
                        else {

                            badGuessCount++;

                            chunk = Mix_LoadWAV("Sound/Wrong guess (updated).wav");

                            Mix_PlayChannel(-1,chunk,0);

                            render->renderGame(badGuessCount,renderer,resources);

                            warning_announcement(renderer,resources,chunk);

                            typing_wrong_guess_announcement(renderer,resources);

                            guessed_letters(renderer,resources);

                            typing_guessed_word(renderer,resources);

                        }

                        cout << guessedWord << endl;

                    }  while (badGuessCount < GUESS_NUM && word != guessedWord); // dieu kien de vong lap dien ra

                    // chuyen canh sau khi choi xong 1 luot
                    int a = 255;

                    while (a > 0) {

                        SDL_SetRenderDrawColor(renderer,0,0,0,255);

                        SDL_RenderClear(renderer);

                        SDL_SetTextureAlphaMod(resources->getTexture("Hangman2",badGuessCount + 1),a);

                        SDL_RenderCopy(renderer,resources->getTexture("Hangman2",badGuessCount + 1),nullptr,&shape);

                        SDL_Delay(5);

                        a -= 5;

                        SDL_RenderPresent(renderer);

                    }

                    // cong vao diem hien tai neu doan dung
                    if (badGuessCount < 14) {

                        score = update_score(score,*level);

                    }

            // kiem tra so diem co pha duoc record khong
            update_Best_score(score);

            // An mung neu ban doan chinh xac
            celebration(guessedWord == word,renderer,resources,chunk);

            *gameState = RESULT;

            break;
        }

        // in ra ket qua sau moi luot choi
        case RESULT: {

            displayFinalResult(guessedWord == word,renderer,resources,Temp,render,gameState);

            SDL_Delay(500);

            *gameState = OPTION;

            break;
        }

        // Lua chon choi tiep hay khong
        case OPTION: {

            option(renderer,resources,Temp,gameState,chunk);

            break;
        }

        // Choi tiep, nguoi choi quay lai man hinh chon level
        case CONTINUE: {

            *status = PLAY_GAME_SUCCESS;

            *gameState = PLAY;

            break;
        }

        // Khong choi nua, nguoi choi quay lai man hinh menu
        case STOP: {

            *status = NO_MORE_PLAY;

            score = 0;

            *gameState = PLAY;

            break;

        }

        }

    }

    //SDL_RenderPresent(renderer);

}
