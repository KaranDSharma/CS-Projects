#include <stdio.h>
#include <iostream>

using namespace std;

void calcPay(float hours, float rate)
{
    float overtime = hours - 40;
    
    if (hours > 40 and rate >= 0)
    {
        float extra = overtime*rate*1.5;
        float total = 40*rate + extra;
        cout<<"Your pay is $"<<total<<"."<<endl;
    }
    
    else if (hours >= 0 and hours <= 40 and rate >= 0)
    {
        float total = hours*rate;
        cout<<"Your pay is $"<<total<<"."<<endl;
    }
    
    else if (hours < 0 or rate < 0)
    {
        cout<<"Pay rate and hours worked cannot be negative values."<<endl;
    }
    
    else
    {
        cout<<"Pay rate and hours worked cannot be negative values."<<endl;
    }
}

int main() 
{
	calcPay(41,10); 
	calcPay(39,10); 
    return 0;
}


