#include <stdio.h>
#include <iostream>

using namespace std;


int getWordCount(string sentence)
{
    int chars=1;
    
    if(sentence.length()<=0)
    {
        return 0;
    }
    
    else
    {
        for(int i = 0; i < sentence.length();i++)
        {
        
            if(sentence[i] == ' ')
            {
                chars = chars + 1;
            }

        }
        return chars;
    }    
    

}

int main() 
{
    getWordCount("Go");
}