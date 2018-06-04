#include <stdio.h>
#include <iostream>

using namespace std;


int getDigitCount(string sentence)
{
    int chars=0;
    
    if(sentence.length()<=0)
    {
        return 0;
    }
    
    else
    {
        for(int i = 0; i < sentence.length();i++)
        {
            if(isdigit(sentence[i]))
            {
                chars = chars + 1;
            }
        }
        
    return chars;
    }
    
   
}

int main() 
{
    getDigitCount("yg123j");
}