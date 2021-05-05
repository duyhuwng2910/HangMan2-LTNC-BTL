#include "Choose_Word.h"
#include <cstring>
#include <fstream>

using namespace std;

// day la qua trinh chon tu, co 5 cap do, va 3 goi tu vung tuy thuoc vao level nguoi choi chon thi goi tu vung tuong ung se duoc su dung

string chooseWord(Level level) {

    vector<string> Word_list;

    // Muc do rat de
    if (level == VERY_EASY) {

        ifstream myfile("Vocab/vocab_easy.txt");

        if (myfile.is_open()) {

            string word;

            while (getline(myfile,word)) {
                //myfile >> word;
                Word_list.push_back(word);

            }

            myfile.close();

        }

        else {

            cout << "Unable to open file." << endl;

        }

    }

    // Muc do de va trung binh
    else if (level == EASY || level == MEDIUM) {

        ifstream myfile("Vocab/vocab_medium.txt");

        if (myfile.is_open()) {

            string word;

            if (level == EASY) {

                while (!myfile.eof()) {

                    if (getline(myfile,word) && word.length() <= 7) {

                        Word_list.push_back(word);

                    }

                }

            }

            else {

                while (!myfile.eof()) {

                    if (getline(myfile,word)) {

                        Word_list.push_back(word);

                    }

                }

            }

            myfile.close();

        }

        else {

            cout << "Unable to open file." << endl;

        }

    }

    // Muc do kho va rat kho
    else if (level == HARD || level == EXTREMELY_HARD) {

        ifstream myfile("Vocab/vocab_hard.txt");

        if (myfile.is_open()) {

            string word;

            if (level == HARD) {

                while (!myfile.eof()) {

                    if (getline(myfile,word) && word.length() <= 7) {

                        Word_list.push_back(word);

                    }

                }

            }

            else {

                while (!myfile.eof()) {

                    if (getline(myfile,word)){

                        Word_list.push_back(word);

                    }

                }

            }

            myfile.close();

        }

        else {

            cout << "Unable to open file." << endl;

        }

    }

    // Random chon tu
    if (Word_list.size() > 1) {

        int index = rand() % Word_list.size();

        string WORD = Word_list[index];

        for (int i = 0; i < WORD.length(); i++) {

            if (WORD[i] >= 97) {
                WORD[i] -= 32;
            }

        }

        return WORD;

    }

    else {

        return "";

    }

}



