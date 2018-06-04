#include <stdio.h>
#include <iostream>

using namespace std;


void printEvenNums(int max)
{
    int i = 0;
    
    while(max > 0)
    {
        
        if(i<max)
        {
            i = i + 1;
            if(i%2 == 0)
            {
            cout << i << endl;
            }
        }
        else
        {
            break;
        }

    }
}

int main () 
{
	printEvenNums(15); 
	printEvenNums(14); 
    return 0;
}