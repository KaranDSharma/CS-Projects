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
#include "botHand.h"
#include "UI.h"
#include "menu.h"

using namespace std;

int main()
{
        srand(time(NULL)); //single instance of srand declared to prevent overlap in randomization
        Menu newMenu;
        cout<<"Hello user please enter your name:"<<endl;
        string name;
        getline(cin,name); //handles 2 part names
        int choice1 = 0;
    
        while(true)
        {
            cout<<"Hello "<<name<<". Would you like to view your decklist(1), play the game(2), or quit(3)?"<<endl;
            cin>>choice1;
            if(choice1 == 1) //view your decklist
            {
                newMenu.readMyFile(); //reads all cards in file decklist
            }
            else if(choice1 == 2) //play the game
            {
                newMenu.openMyFile();
                while((newMenu.getBotScore()<10) and (newMenu.getPlayerScore()<10))
                {
                    newMenu.prompt(); //activates prompt running game
                }
                newMenu.closeMyFile();
            }
            else if(choice1 == 3) //quit
            {
                break;
            }
            else
            {
                cout<<"invalid input"<<endl;
            }
        }    
        cout<<"thanks for playing nerd."<<endl; //love you tho
        
}