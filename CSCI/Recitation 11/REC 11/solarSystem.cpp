#include "solarSystem.h"

solarSystem::solarSystem(string name){
    maxNumPlanets = 10;
	systemName = name;
	numPlanets = 0;
}

solarSystem::~solarSystem(){
       
}

/**
* Algorithm: getter for name of planet
*   1.  returns systemname
*   Input parameters: ø
*   Output: ø
*   Returns: string systemname
*/
string solarSystem::getName(){
    return systemName;
}

/**
* Algorithm: getter for num of planets
*   1. returns num of planets
*   Input parameters: ø
*   Output: ø
*   Returns: int numplanets
*/
int solarSystem::getNumPlanets(){
    return numPlanets;
}

/**
* Algorithm: add planet to solar system
*   1. if numplanets is less than maxplanets, add planet to numplanet index of the array
*   Input parameters: string name and float radius
*   Output: nothing
*   Returns: true or false (bool)
*/
bool solarSystem::addPlanet(string name, float radius){
    if(numPlanets < maxNumPlanets){
        systemPlanets[numPlanets++] = planet(name, radius);
    }
}

/**
* Algorithm: getter for planet
*   1. checks if index is less than equal to numplanets, if so returns index planet in the system
*   Input parameters: int index
*   Output: nothing
*   Returns: planet type planet
*/
planet solarSystem::getPlanet(int index){
    if(index <= numPlanets){
        return systemPlanets[index];
    }
}

/**
* Algorithm: calculate diff of radius  
*   1.  gets radius for p1 and p2 and subtracts them
*   Input parameters: planet objects p1 and p2
*   Output: nothing
*   Returns: float value difference
*/
float solarSystem::radiusDifference(planet p1, planet p2){
    return fabs(p1.getRadius() - p2.getRadius());
}