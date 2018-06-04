#ifndef card
#define card

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

class Card
{
    private: 
        int cardAtk;
        int cardHp;
        
        int randLength;
        int buffer;
        string randConsonant;
        string randVowel;
        string cardName;
        
    public:
        Card();
        ~Card();
        
        int getCardAtk();
        void setCardAtk(int );
        int getCardHp();
        void setCardHp(int );
        string getCardName();
        void setCardName(string );
};

#endif