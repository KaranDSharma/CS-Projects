#ifndef botHand
#define botHand

#include <iostream>
#include <tuple>
#include <limits>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include "card.h"


using namespace std;

class Bot
{
    private:
        Card *currCard;
    public:
        Bot();
        void getNewCard();
        Card * getCard();
        void deleteCard();
};

#endif