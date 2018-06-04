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

        Card::Card()
        {
            //randomly generates stats
            cardAtk = rand() % 9 + 1;
            cardHp = rand() % 9 + 1;
            //alternates consonants and vowels for name
            string vowel[5] = {"a","e","i","o","u"};
            string consonant[21] = {"b","c","d","f","g","h","j","k","l","m","n","p","q","r","s","t","v","w","x","y","z"};
            randLength = rand() % 4 + 2;
            
            for(int i=0; i<randLength;i++)
            {
                buffer = rand() % 21;
                randConsonant = consonant[buffer];
                cardName.append(randConsonant);
                
                buffer = rand() % 5;
                randVowel = vowel[buffer];
                cardName.append(randVowel);
            }
            
        }
        
        Card::~Card()
        {
            cardAtk = 0;
            cardHp = 0;
            cardName = "";
        }
        
        int Card::getCardAtk()
        {
            return cardAtk;
        }
        
        void Card::setCardAtk(int atk)
        {
            cardAtk = atk;
        }
        
        int Card::getCardHp()
        {
            return cardHp;
        }
        
        void Card::setCardHp(int hp)
        {
            cardHp = hp;
        }
    
        string Card::getCardName()
        {
            return cardName;
        }
        
        void Card::setCardName(string name)
        {
            cardName = name;
        }
