#include <stdio.h>
#include <iostream>

using namespace std;

int collatzStep(int val)
{
    if((val % 2) > 0) //test for odd thru remainder
    {
        val = 3*val+1;
        return val;
    }
    else if((val % 2) == 0) //test for even thru remainder
    {
        val = (val/2);
        return val;
    }
    else if(val<0)
    {
        return 0;
    }
    else
    {
        cout<<":D"<<endl;
        return 0;
    }
}

int main() 
{
	collatzStep(5); 
	collatzStep(6); 
    return 0;
}