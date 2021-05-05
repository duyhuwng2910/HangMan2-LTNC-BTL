#include "Resources.h"

Resources::Resources(SDL_Renderer* _renderer) {

    this->renderer = _renderer;
    TTF_Init();
    loadResources();

}

void Resources::loadTexture(SDL_Texture **texture, string file_path) {

    *texture = NULL;

    SDL_Surface* loaded_surface = NULL;

    loaded_surface = IMG_Load(file_path.c_str());

    if (loaded_surface == NULL) {
        cout << "Error loading image: %s\n" << SDL_GetError() << endl;
    }

    *texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);

    if (texture == NULL) {
        cout << "Unable to create texture from surface: %s\n" << SDL_GetError() << endl;
    }

    SDL_SetTextureBlendMode(*texture, SDL_BLENDMODE_BLEND);
    SDL_FreeSurface(loaded_surface);

}

void Resources::loadResources() {

    font1 = TTF_OpenFont("Font/BebasNeue.ttf",40);
    font2 = TTF_OpenFont("Font/Lato-Regular.ttf",30);
    font3 = TTF_OpenFont("Font/Lato-Regular.ttf",80);
    if (font1 == NULL){
        cout << "error" << endl;
    }

    // Luu y, o mot so anh do bong, chi so 0 la anh thuong, con chi so 1 la anh co do bong

    // load anh main screen
    loadTexture(&textures["Main menu"][0],"Images/Screen/1.Main_menu.png");
    loadTexture(&textures["Main menu music on"][0],"Images/Screen/Music_on.png");
    loadTexture(&textures["Main menu music off"][0],"Images/Screen/Music_off.png");
    loadTexture(&textures["Level"][0],"Images/Screen/2.Level.png");
    loadTexture(&textures["GUIDE"][0],"Images/Screen/3.How_to_play.png");

    // load anh chu cai
    loadTexture(&textures["A"][0],"Images/Letter_images/A.png");
    loadTexture(&textures["B"][0],"Images/Letter_images/B.png");
    loadTexture(&textures["C"][0],"Images/Letter_images/C.png");
    loadTexture(&textures["D"][0],"Images/Letter_images/D.png");
    loadTexture(&textures["E"][0],"Images/Letter_images/E.png");
    loadTexture(&textures["F"][0],"Images/Letter_images/F.png");
    loadTexture(&textures["G"][0],"Images/Letter_images/G.png");
    loadTexture(&textures["H"][0],"Images/Letter_images/H.png");
    loadTexture(&textures["I"][0],"Images/Letter_images/I.png");
    loadTexture(&textures["J"][0],"Images/Letter_images/J.png");
    loadTexture(&textures["K"][0],"Images/Letter_images/K.png");
    loadTexture(&textures["L"][0],"Images/Letter_images/L.png");
    loadTexture(&textures["M"][0],"Images/Letter_images/M.png");
    loadTexture(&textures["N"][0],"Images/Letter_images/N.png");
    loadTexture(&textures["O"][0],"Images/Letter_images/O.png");
    loadTexture(&textures["P"][0],"Images/Letter_images/P.png");
    loadTexture(&textures["Q"][0],"Images/Letter_images/Q.png");
    loadTexture(&textures["R"][0],"Images/Letter_images/R.png");
    loadTexture(&textures["S"][0],"Images/Letter_images/S.png");
    loadTexture(&textures["T"][0],"Images/Letter_images/T.png");
    loadTexture(&textures["U"][0],"Images/Letter_images/U.png");
    loadTexture(&textures["V"][0],"Images/Letter_images/V.png");
    loadTexture(&textures["W"][0],"Images/Letter_images/W.png");
    loadTexture(&textures["X"][0],"Images/Letter_images/X.png");
    loadTexture(&textures["Y"][0],"Images/Letter_images/Y.png");
    loadTexture(&textures["Z"][0],"Images/Letter_images/Z.png");

    // load anh do bong menu
    loadTexture(&textures["PLAY_do_bong"][0],"Images/Do_bong_menu/1.png");
    loadTexture(&textures["HOW_TO_PLAY_do_bong"][0],"Images/Do_bong_menu/2.png");
    loadTexture(&textures["EXIT_GAME_do_bong"][0],"Images/Do_bong_menu/3.png");

    loadTexture(&textures["PLAY_do_bong_music_on"][0],"Images/Do_bong_menu/Music_on_1.png");
    loadTexture(&textures["HOW_TO_PLAY_do_bong_music_on"][0],"Images/Do_bong_menu/Music_on_2.png");
    loadTexture(&textures["EXIT_GAME_do_bong_music_on"][0],"Images/Do_bong_menu/Music_on_3.png");
    loadTexture(&textures["PLAY_do_bong_music_off"][0],"Images/Do_bong_menu/Music_off_1.png");
    loadTexture(&textures["HOW_TO_PLAY_do_bong_music_off"][0],"Images/Do_bong_menu/Music_off_2.png");
    loadTexture(&textures["EXIT_GAME_do_bong_music_off"][0],"Images/Do_bong_menu/Music_off_3.png");

    // load anh do bong level
    loadTexture(&textures["VERY EASY"][0],"Images/Do_bong_level/1.png");
    loadTexture(&textures["EASY"][0],"Images/Do_bong_level/2.png");
    loadTexture(&textures["MEDIUM"][0],"Images/Do_bong_level/3.png");
    loadTexture(&textures["HARD"][0],"Images/Do_bong_level/4.png");
    loadTexture(&textures["EXTREMELY HARD"][0],"Images/Do_bong_level/5.png");

    // load anh main images
    loadTexture(&textures["Hangman2"][0],"Images/Main_images/1.png");
    loadTexture(&textures["Hangman2"][1],"Images/Main_images/2.png");
    loadTexture(&textures["Hangman2"][2],"Images/Main_images/3.png");
    loadTexture(&textures["Hangman2"][3],"Images/Main_images/4.png");
    loadTexture(&textures["Hangman2"][4],"Images/Main_images/5.png");
    loadTexture(&textures["Hangman2"][5],"Images/Main_images/6.png");
    loadTexture(&textures["Hangman2"][6],"Images/Main_images/7.png");
    loadTexture(&textures["Hangman2"][7],"Images/Main_images/8.png");
    loadTexture(&textures["Hangman2"][8],"Images/Main_images/9.png");
    loadTexture(&textures["Hangman2"][9],"Images/Main_images/10.png");
    loadTexture(&textures["Hangman2"][10],"Images/Main_images/11.png");
    loadTexture(&textures["Hangman2"][11],"Images/Main_images/12.png");
    loadTexture(&textures["Hangman2"][12],"Images/Main_images/13.png");
    loadTexture(&textures["Hangman2"][13],"Images/Main_images/14.png");
    loadTexture(&textures["Hangman2"][14],"Images/Main_images/15.png");

    // load anh co tiep tuc choi hay khong
    loadTexture(&textures["Option"][0],"Images/Option/1.png");
    loadTexture(&textures["YES"][0],"Images/Option/2.png");
    loadTexture(&textures["NO"][0],"Images/Option/3.png");
    loadTexture(&textures["QUIT"][0],"Images/Option/4.png");

    // load anh an mung, thua cuoc
    loadTexture(&textures["Congrate"][0],"Images/Game_announcement/1.png");
    loadTexture(&textures["Congrate"][1],"Images/Game_announcement/2.png");
    loadTexture(&textures["Congrate"][2],"Images/Game_announcement/3.png");
    loadTexture(&textures["Congrate"][3],"Images/Game_announcement/4.png");
    loadTexture(&textures["Congrate"][4],"Images/Game_announcement/5.png");
    loadTexture(&textures["Congrate"][5],"Images/Game_announcement/6.png");
    loadTexture(&textures["Congrate"][6],"Images/Game_announcement/7.png");
    loadTexture(&textures["Congrate"][7],"Images/Game_announcement/8.png");
    loadTexture(&textures["Congrate"][8],"Images/Game_announcement/9.png");
    loadTexture(&textures["Congrate"][9],"Images/Game_announcement/10.png");
    loadTexture(&textures["Congrate"][10],"Images/Game_announcement/11.png");
    loadTexture(&textures["Congrate"][11],"Images/Game_announcement/12.png");
    loadTexture(&textures["Congrate"][12],"Images/Game_announcement/13.png");
    loadTexture(&textures["Congrate"][13],"Images/Game_announcement/14.png");
    loadTexture(&textures["Congrate"][14],"Images/Game_announcement/15.png");
    loadTexture(&textures["Congrate"][15],"Images/Game_announcement/16.png");
    loadTexture(&textures["Congrate"][16],"Images/Game_announcement/17.png");
    loadTexture(&textures["Congrate"][17],"Images/Game_announcement/18.png");

    loadTexture(&textures["WIN"][0],"Images/Game_announcement/19.png");
    loadTexture(&textures["WIN_REACH_RECORD"][0],"Images/Game_announcement/20.png");
    loadTexture(&textures["WIN_REACH_RECORD_do_bong"][0],"Images/Game_announcement/21.png");
    loadTexture(&textures["WIN_BREAKING_RECORD"][0],"Images/Game_announcement/22.png");
    loadTexture(&textures["WIN_BREAKING_RECORD_do_bong"][0],"Images/Game_announcement/23.png");

    loadTexture(&textures["LOSE"][0],"Images/Game_announcement/24.png");
    loadTexture(&textures["LOSE_do_bong"][0],"Images/Game_announcement/25.png");

    // image chuyen canh
    loadTexture(&textures["VAO GAME"][0],"Images/Chuyen_canh/Start_game.png");

}

SDL_Texture* Resources::getTexture(string textureName, int frame){

    return textures[textureName][frame];

}

Resources::~Resources(){

    TTF_Quit();

}
