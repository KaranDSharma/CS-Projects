#include <iostream>
#include <tuple>
#include <limits>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include "botHand.h"
#include "card.h"

using namespace std;

//bot class holds instance of card unique to the bot
Bot::Bot()
{
    currCard = NULL;  
}

void Bot::getNewCard()
{
    currCard = new Card;
    //currCard->setCardAtk(100); for testing edge cases
    //currCard->setCardHp(1);
}

void Bot::deleteCard()
{
    delete currCard;
    currCard = NULL;
}

Card * Bot::getCard()
{
    return currCard; 
}

       