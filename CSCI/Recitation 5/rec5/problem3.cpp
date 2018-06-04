#include <stdio.h>
#include <iostream>
#include<string>

using namespace std;

int getMatchCount(string subString, string wholeString)
{
    int times = 0;
    
    if(subString.length()<=0 or wholeString.length()<=0)
    {
        return -1;
    }
    
    else if(subString.length() > wholeString.length())
    {
        return -2;
    }
    
    else
    {
        for(int i = 0; i < wholeString.length();i++)
        {

            if (wholeString.substr(i,subString.length()) == subString)
            {
                times++;
            }
        }
        return times;
    }
}


int main() 
{
    getMatchCount("si","mississippi");
}