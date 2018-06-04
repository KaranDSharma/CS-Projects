// Author: Karan Sharma CS1300 Spring 2018
// Recitation: 101 – Akriti Kapur
// Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
// Rec11 
#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <string>
#include <math.h>
#include <iostream>
#include "planet.h"
using namespace std;
//header for solar system declaring all public n private variables
class solarSystem{
	public:
		solarSystem(string);
		~solarSystem();

		string getName();			// return the name of the solar system
		int getNumPlanets();		// return the number of planets in the system
		bool addPlanet(string, float);	//Adds a single planet to solar system
        planet getPlanet(int);  	// return an object of planet at provided index
		float radiusDifference(planet, planet);
		
	private:
		int maxNumPlanets; // This should be initialized to 10 in the constructor
		string systemName;
		int numPlanets;
		planet systemPlanets[10]; // array of object planet, each obj is a planet
		
};
#endif // SOLAR_SYSTEM_H
