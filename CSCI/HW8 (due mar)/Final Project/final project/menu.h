#ifndef menu
#define menu

#include <iostream>
#include <tuple>
#include <limits>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <math.h>
#include <stdlib.h>
// #include "botHand.h"
// #include "playerHand.h"
//#include "card.h"

using namespace std;

class Menu
{
    private:
        Bot bot;
        Player player;
        int botScore;
        int playerScore;
        ofstream myFile;
        ifstream myDeckList;
    public:
        Menu()
        {
            botScore = 0;
            playerScore = 0;
        };
        int prompt();
        void saveCards(Player, Bot);
        int getBotScore();
        void setBotScore(int);
        void openMyFile();
        void closeMyFile();
        void readMyFile();
        int getPlayerScore();
        void setPlayerScore(int);
};

#endif