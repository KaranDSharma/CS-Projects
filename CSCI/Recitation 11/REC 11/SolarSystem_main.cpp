// Author: Karan Sharma CS1300 Spring 2018
// Recitation: 101 – Akriti Kapur
// Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
// Rec11 
#include <iostream>
#include "planet.h"
#include "solarSystem.h"
#include <math.h>
#include <map> 

using namespace std;


/* 
    This function implements the logic to find the difference between the radius 
    of all the planets in the given solar system.
    
    Notes:
        * having more or less outputs means that your logic is not quite correct.
        * do not hard code the cout statements; use a smart logic instead.
        * use fabs() to compute the absolute value of the difference (do it either in your impementation of
          radiusDifference(planet,planet) or use it after you return the function call to radiusDifference(planet,planet)
        * your output should have the following structure:
            cout<<"Radius difference between planet " <<  <<" and planet "<< <<
                    " is => "<< <<endl;
        * for 5 planets you should have 10 outputs.
        
*/

/**
* Algorithm: compares radius of planets 
*   1. nested for loop and subtracts distance between getplanet i and getplanet x 
*   Input parameters: object solar, integer numPlanets
*   Output: prints 2 planet names and radius difference
*   Returns: nothing
*/
void compareRadii(solarSystem solar, int numPlanets){
    for(int i = 0; i < numPlanets; ++i){
        for(int x = i+1; x < numPlanets; ++x){ //<numplanets
            cout << "The distance between " << solar.getPlanet(i).getName() << " and " << solar.getPlanet(x).getName() << " is " << solar.radiusDifference(solar.getPlanet(i), solar.getPlanet(x)) << endl;
        }
    }
}


int main(){
  
    /* 1) Ask the user to create a solar system by promting him for 5 instances
     of type Planet. You will ask the user for name and radius of each
     Planet. Each object will have to have a unique name.
    */
    map<string, float> planetMap;
    
    string pName;
    float pRadius;
    string solarName;

    cout << "Welcome! What would you like to name your solar system?" << endl;
    cin >> solarName;
    solarSystem newSolar(solarName);
    
    cout << "Lets add five planets to " << solarName << "." << endl;

    int count = 0;
    while(count < 5){
        cout << "Please enter a planet name: " << endl;
        cin >> pName;
        
        cout << "Please enter " << pName << "\'s radius: " << endl;
        cin >> pRadius;
        
        if (planetMap.find(pName) == planetMap.end()){
            planetMap[pName] = pRadius;
            newSolar.addPlanet(pName, pRadius);
            count++;
        }else{
            cout << "That planet has been previously added." << endl;
        }
    }
    
    
    
    int i,j;
    bool unique;
    string name;
    string radius;
    
    // i = 0;
    // int num_of_planets = newSolar.getNumPlanets();
    
    // if (num_of_planets < 5) {
        
    //     cout<<"Your system has less than 5 planets!"<<endl;
    // }
    
    // while(i < num_of_planets) {
    //     cout << "This is planet " << i << " with name: " << newSolar.getPlanet(i).getName() << 
    //     " and radius: " << newSolar.getPlanet(i).getRadius() << endl;
    //     i++;
    // }

    
    /* 2) Add the method radiusDifference(...) to the SolarSytem class. This method
     takes two objects of type Planet and returns the difference of their
     radius. Develop a logic to return the difference among all the planets in a 
     function called compareRadii(...) that takes two params, a solarSystem and the
     number of planets in the system. You can find the function definition above 
     the main. Once you are done implementing it call it.
     */
    
    /*
    !!NOTE: here "<obj_of_type_solarSystem>" and "<num_of_planets> are placeholders
    you should use the name of your solarSystem instance created (hopefully) above 
    and the number of planets currently in the solarSystem.
    */
    
    compareRadii(newSolar, newSolar.getNumPlanets());
    
    return 0;
}
