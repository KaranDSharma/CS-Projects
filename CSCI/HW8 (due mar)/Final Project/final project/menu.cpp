#include <iostream>
#include <tuple>
#include <limits>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <unistd.h>
#include "botHand.h"
#include "playerHand.h"
#include "menu.h"
#include "card.h"
#include "UI.h"

using namespace std;

        int Menu::prompt() //used for 1 round
        {
            Interface newInterface;
            bot.getNewCard();
            player.getNewCard();
            cout<<"\n\n*****************************Starting Round******************************"<<endl;
            cout<<"here is your card: "<<endl;
            cout<<"\nAttack: "<<player.getCard()->getCardAtk()<<endl;
            cout<<"HP: "<<player.getCard()->getCardHp()<<endl;
            cout<<player.getCard()->getCardName()<<endl;
            // bot is given a card
            // player is given a card
            int input = 0;
            int count = 0;
            bool x = false;
            while(x == false and playerScore <10 and botScore<10)
            {
                cout<<"\nPlease enter an option:"<<endl;
                cout<<"1 redraw a card (up to 3 times)"<<endl;
                cout<<"2 lock your card"<<endl;
                cout<<"3 repeat the stats of your card"<<endl;
                cout<<"4 quit the game"<<endl;
                cin>>input;
                if(input == 4)
                {
                    cout<<"quitting the game..."<<endl;
                    exit(0);
                }
                else if(input == 1 and count >= 3)
                {
                    //if player has drawn more than 3 times, force the same card
                    cout<<"You have exceeded the draw limit of 3. Your card is set!"<<endl;
                    cout<<"here is your card: "<<endl;
                    cout<<"\nAttack: "<<player.getCard()->getCardAtk()<<endl;
                    cout<<"HP: "<<player.getCard()->getCardHp()<<endl;
                    cout<<player.getCard()->getCardName()<<endl;
                    //x = false
                }
                else if(input == 1 and count<=3)
                {
                    //if player asks for new card and has draws remaining
                    player.deleteCard();
                    player.getNewCard();
                    cout<<"\nAttack: "<<player.getCard()->getCardAtk()<<endl;
                    cout<<"HP: "<<player.getCard()->getCardHp()<<endl;
                    cout<<player.getCard()->getCardName()<<endl;
                    x = false;
                    count++;
                }
                else if(input == 2)
                {
                    //standard duel phase, compares card values
                    cout<<"duel!"<<endl;
                    saveCards(player,bot);
                    cout<<"here is the bot's card: "<<endl;
                    cout<<"\nAttack: "<<bot.getCard()->getCardAtk()<<endl;
                    cout<<"HP: "<<bot.getCard()->getCardHp()<<endl;
                    cout<<bot.getCard()->getCardName()<<"\n"<<endl;
                    
                    if((player.getCard()->getCardAtk() > bot.getCard()->getCardHp()) and (bot.getCard()->getCardAtk() < player.getCard()->getCardHp())) 
                    {
                        //if player atk > bot hp and bots attack < player hp
                        playerScore++;
                        cout<<"Player wins!"<<endl;
                        cout<<"Player: "<<playerScore<<" Bot: "<<botScore<<endl;
                        newInterface.interface(botScore, playerScore, player.getCard()->getCardAtk(), player.getCard()->getCardHp(), bot.getCard()->getCardAtk(), bot.getCard()->getCardHp(), false);
                    }
                    else if(bot.getCard()->getCardAtk() > player.getCard()->getCardHp() and (player.getCard()->getCardAtk() < bot.getCard()->getCardHp()))
                    {
                        //if bot attack > player hp and players attack < bot hp
                        botScore++;
                        cout<<"Bot wins!"<<endl;
                        cout<<"Player: "<<playerScore<<" Bot: "<<botScore<<endl;
                        newInterface.interface(botScore, playerScore, player.getCard()->getCardAtk(), player.getCard()->getCardHp(), bot.getCard()->getCardAtk(), bot.getCard()->getCardHp(), false);
                    }
                    else if((bot.getCard()->getCardHp() < player.getCard()->getCardAtk()) and (player.getCard()->getCardHp() < bot.getCard()->getCardAtk()))
                    {
                        //draw
                        cout<<"Draw! No points awarded!"<<endl;
                        cout<<"Player: "<<playerScore<<" Bot: "<<botScore<<endl;
                        newInterface.interface(botScore, playerScore, player.getCard()->getCardAtk(), player.getCard()->getCardHp(), bot.getCard()->getCardAtk(), bot.getCard()->getCardHp(), false);
                    }
                    else if((bot.getCard()->getCardHp() > player.getCard()->getCardAtk()) and (player.getCard()->getCardHp() > bot.getCard()->getCardAtk()))
                    {
                        //joust
                        cout<<"Joust! drawing new card..."<<endl;
                        Card playerCard1;
                        Card botCard1;
                        //variables for jousted stats
                        int playerAttack = playerCard1.getCardAtk() + player.getCard()->getCardAtk();
                        int playerHp = playerCard1.getCardHp() + player.getCard()->getCardHp();
                        int botAttack = botCard1.getCardAtk() + bot.getCard()->getCardAtk();
                        int botHp = botCard1.getCardHp() + bot.getCard()->getCardHp();
                        cout<<"New bot stats: " << botAttack <<"/"<<botHp<<endl;
                        cout<<"New player stats: "<< playerAttack<<"/"<<playerHp<<endl;
                        newInterface.interface(botScore, playerScore, playerAttack, playerHp, botAttack, botHp, true);
                        
                        if((playerAttack > botHp) and (botAttack < playerHp)) 
                        {
                            //if player atk > bot hp and bots attack < player hp
                            playerScore++;
                            cout<<"Player wins!"<<endl;
                            cout<<"Player: "<<playerScore<<" Bot: "<<botScore<<endl;
                            
                        }
                        else if((botAttack > playerHp) and (playerAttack < botHp))
                        {
                            //if bot attack > player hp and players attack < bot hp
                            botScore++;
                            cout<<"Bot wins!"<<endl;
                            cout<<"Player: "<<playerScore<<" Bot: "<<botScore<<endl;
                        }
                        else if((botHp < playerAttack) and (playerHp < botAttack))
                        {
                            //draw
                            cout<<"Draw! No points awarded!"<<endl;
                            cout<<"Player: "<<playerScore<<" Bot: "<<botScore<<endl;
                        }
                        else if((botHp > playerAttack) and (playerHp > botAttack))
                        {
                            cout<<"JOUST AGAIN?!! No points awarded!"<<endl;
                            cout<<"Player: "<<playerScore<<" Bot: "<<botScore<<endl;
                        }
                        else
                        {
                            cout<<"\nA worthy opponent..."<<endl;
                            cout<<"~you froze in awe~\n"<<endl;
                        }
                    }
                    else
                    {
                        cout<<"\nA worthy opponent..."<<endl;
                        cout<<"~you froze in awe~\n"<<endl;
                    }
                    x = true;
                    bot.deleteCard();
                    player.deleteCard();
                }
                else if(input == 3)
                {
                    cout<<"\nHere are the stats of your card again: "<<endl;
                    cout<<"Attack: "<<player.getCard()->getCardAtk()<<endl;
                    cout<<"HP: "<<player.getCard()->getCardHp()<<endl;
                    cout<<player.getCard()->getCardName()<<endl;
                    x = false;
                }
                else
                {
                    cout<<"Invalid input! Re-enter choice!"<<endl;
                    x = false;
                }
               
            }
            //^^^^^
            // bool x = false;
            // while(x = false)
            // prompts user to either draw card, lock card (1 2 or 3), or repeat existing stats -(1,2,3)
            // if invalid input alerts for invalid input
            // when 2 selected, x = true and breaks out of loop 
            // conducts comparison of cards:
            // if both cards have equal stats, discard both cards, both players get a point, and restart the round
            // if both cards have lower hp values than the opponent's attack value, discard both cards, neither player gets a point, and restart the round
            // if both cards have lower attack values then the opponent's HP value, x = false
            // while(true)
            // draw another card and add said card's stats to existing card
            // compare stats again, if both cards have lower attack values then the opponent's HP value, x = false, else x = true and breaks out of loop
            // return int score
        }
        
        int Menu::getBotScore()
        {
            return botScore;
        }
        
        void Menu::setBotScore(int scor)
        {
            botScore = scor;
        }
        int Menu::getPlayerScore()
        {
            return playerScore;
        }
        
        void Menu::setPlayerScore(int scor2)
        {
            playerScore = scor2;
        }
        
        void Menu::openMyFile()
        {
            
            myFile.open("decklist.txt");
        }
        
        void Menu::closeMyFile()
        {
            myFile.close();
        }
        
        void Menu::readMyFile()
        {
            //for reading the deck list
            myDeckList.open("decklist.txt");
            string line = ""; 
            cout<<"*****PRINTING THE DECK LIST!*****"<<endl;
            while(getline(myDeckList,line))
            {
                cout<<line<<endl; //prints each line till no lines remain
            }
            myDeckList.close();
            cout<<"*****DONE PRINTING THE DECK LIST!*****"<<endl;
        }
        
        void Menu::saveCards(Player player, Bot bot)
        {
            if (myFile.is_open()) //if can open file
            {
                myFile<< player.getCard()->getCardAtk()<< ","<<player.getCard()->getCardHp()<<","<<player.getCard()->getCardName()<<endl;
                myFile<< bot.getCard()->getCardAtk()<< ","<<bot.getCard()->getCardHp()<<","<<bot.getCard()->getCardName()<<endl;
            } //append file with new card entry
            else
            {
                cout<<"file does not open"<<endl;
            }
            // writes bot object containing bot card info to file
            // writes player object containing player card info to file
        }
