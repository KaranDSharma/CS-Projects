#ifndef playerHand
#define playerHand

#include <iostream>
#include <tuple>
#include <limits>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <math.h>
#include <stdlib.h>


using namespace std;

class Player
{
    private:
        Card *currCard;
    public:
        Player();
        void getNewCard();
        void deleteCard();
        Card * getCard();
        
};

#endif