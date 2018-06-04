#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

float windChillCalculator(float T, float V)
{
    if(V>=0)
    {
        float windChill = 35.74 + 0.6215*T - 35.75*pow(V,0.16) + 0.4275*T*pow(V,0.16);
        cout<<"The wind chill is "<<windChill<<" degrees F for an air temperature of "<<T<<" degrees F and a wind speed of "<<V<<" mph."<<endl;
        return windChill;
    }
    
    else
    {
        cout<<"Not applicable"<<endl;
        return 0;
    }
}

void printWindChill(float T, float low_wind_speed, float high_wind_speed, float wind_speed_step)
{
    if (low_wind_speed > high_wind_speed or wind_speed_step < 0)
    {
        cout<<"Invalid input"<<endl;
    }
    while (high_wind_speed >= low_wind_speed and  wind_speed_step > 0)
    {
        float V = low_wind_speed;
        windChillCalculator(T,V);
        low_wind_speed = low_wind_speed + wind_speed_step;
    }
    
}

int main() 
{
    printWindChill(30,5,8,1);
    printWindChill(30,6,2,-1);
}
