#include <iostream>
#include <tuple>
#include <limits>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include "UI.h"

using namespace std;

        void Interface::interface(int botScore, int playerScore, int playerAtk, int playerHp, int botAtk, int botHp, bool joust)
        {
            if(joust == false)
            {
                cout<<"\n---------------------------"<<endl;
                cout<<"PLAYER - atk/hp"<<endl;
                cout<<"-----"<<endl;
                cout<<"|-"<<playerAtk<<"-|"<<endl;
                cout<<"|-"<<playerHp<<"-|"<<endl;
                cout<<"-----"<<endl;
                
                cout<<"\n"<<endl;
                cout<<"Player: "<<playerScore<<" Bot: "<<botScore<<endl;
                cout<<"DUEL"<<endl;
                cout<<"\n"<<endl;
                
                cout<<"BOT - atk/hp"<<endl;
                cout<<"-----"<<endl;
                cout<<"|-"<<botAtk<<"-|"<<endl;
                cout<<"|-"<<botHp<<"-|"<<endl;
                cout<<"-----"<<endl;
                cout<<"---------------------------"<<endl;
                // print duel phase animation
                // prints score to center of screen, attack and HP onto card
                // if joust is false, prints duel to center of screen
            }
            else if(joust == true)
            {
                //joust phase animation displays a card stacked ontop of another card
                cout<<"\n---------------------------"<<endl;
                cout<<"PLAYER - atk/hp"<<endl;
                cout<<"------"<<endl;
                cout<<"-----|"<<endl;
                cout<<"|-"<<playerAtk<<"-||"<<endl;
                cout<<"|-"<<playerHp<<"-||"<<endl;
                cout<<"-----"<<endl;
                
                cout<<"\n"<<endl;
                cout<<"Player: "<<playerScore<<" Bot: "<<botScore<<endl;
                cout<<"JOUST"<<endl;
                cout<<"\n"<<endl;
                
                cout<<"BOT - atk/hp"<<endl;
                cout<<"------"<<endl;
                cout<<"-----|"<<endl;
                cout<<"|-"<<botAtk<<"-||"<<endl;
                cout<<"|-"<<botHp<<"-||"<<endl;
                cout<<"-----"<<endl;
                cout<<"---------------------------"<<endl;
            }
        };