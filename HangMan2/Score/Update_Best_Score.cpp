#include "Update_Best_Score.h"
#include <fstream>
#include <sstream>

using namespace std;

void update_Best_score(long &score) {

    int temp;
    string best;

	ifstream Myfile("Score/Best_score.txt");

    if (Myfile.is_open()) {
        while (getline(Myfile,best)) {

        }
        Myfile.close();
    }

    else {
        cout << "Unable to open file." << endl;
    }

    stringstream ss(best);

    ss >> temp;

    if (score > temp) {

        temp = score;

        fstream Update("Score/Best_score.txt");

        while (getline(Update,best)) {}
        if (Update.is_open()) {
            Update << score;
            Update.close();
        }
    }

}


