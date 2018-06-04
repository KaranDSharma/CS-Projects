#include <stdio.h>
#include <iostream>

using namespace std;


void story1()
{
    string pNoun;
    string occupation;
    string animal;
    string place;
    cout<<"Enter a plural noun: "<<endl;
    cin>>pNoun;
    cout<<"Enter an occupation: "<<endl;
    cin>>occupation;
    cout<<"Enter an animal name: "<<endl;
    cin>>animal;
    cout<<"Enter a place: "<<endl;
    cin>>place;
    cout<<"In the book War of the "<<pNoun<<", the main character is an anonymous "<<occupation<<" who records the arrival of the "<<animal<<"s in "<<place<<"."<<endl;
}

void story2()
{
    string name;
    string state;
    cout<<"Enter a name: "<<endl;
    cin>>name;
    cout<<"Enter a state/country: "<<endl;
    cin>>state;
    cout<<name<<", I've got a feeling we're not in "<<state<<" anymore."<<endl;
}

void story3()
{
    string fName;
    string relative;
    string verb;
    cout<<"Enter a first name: "<<endl;
    cin>>fName;
    cout<<"Enter a relative: "<<endl;
    cin>>relative;
    cout<<"Enter a verb: "<<endl;
    cin>>verb;
    cout<<"Hello. My name is "<<fName<<". You killed my "<<relative<<". Prepare to "<<verb<<"."<<endl;
}

void menu()
{
    int loop=1;
    while(loop>0)
    {
        string input;
        cout<<"Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: "<<endl;
        cin>>input;
    
        if(input.compare("1") == 0)
        {
            story1();
        }
        else if(input.compare("2") == 0)
        {
            story2();
        }
        else if(input.compare("3") == 0)
        {
            story3();
        }
        else if(input.compare("q") == 0)
        {
            cout<<"good bye"<<endl;
            loop=0;
        }
        else
        {
        cout<<"Valid choice not selected."<<endl;
        }
    }    
}

int main() 
{
menu();
return(0);
}
