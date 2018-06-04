// Author: Karan Sharma CS1300 Spring 2018
// Recitation: 101 – Akriti Kapur
// Cloud9 Workspace Editor Link: https://ide.c9.io/kash0329/karansharma-csci1300
// Rec11 
#include "planet.h"

planet::planet(){
	radius = 0.0;
}

planet::planet(string planetName, float planetRadius){
	name = planetName;
	radius = planetRadius;
}

planet::~planet(){
	//letting compiler handle deconstruction of the class
}

void planet::setName(string planetName){
	name = planetName;
}

string planet::getName(){
	return name;
}

void planet::setRadius(float planetRadius){
	radius = planetRadius;
}

float planet::getRadius(){
	return radius;
}

