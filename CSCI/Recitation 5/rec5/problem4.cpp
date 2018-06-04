#include <stdio.h>
#include <iostream>

using namespace std;

int getLastIndex(char x, string sentence)
{
    int times = 0;
    
    if(sentence.length()<=0)
    {
        return 0;
    }
    
    else
    {
        for(int i = 0; i < sentence.length();i++)
        {

            if (x == sentence[i])
            {
                times = i;
            }
            else
            {
                return 0;
            }
        }
        return times;
    }
}

int main() 
{
    getLastIndex('o',"lollipop");
}