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
#include "playerHand.h"

using namespace std;

        //player class holds instance of card unique to the player
        Player::Player()
        {
            currCard = NULL;  
        }
        
        void Player::getNewCard()
        {
            currCard = new Card;
            //currCard->setCardAtk(100); for testing edge cases
            //currCard->setCardHp(1);
        }
        void Player::deleteCard()
        {
            delete currCard;
            currCard = NULL;
        }
        
        Card * Player::getCard()
        {
            return currCard; 
        }
       