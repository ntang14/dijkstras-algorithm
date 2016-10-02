/*Nancy Tang Assignment 5 Galaxy.h file
This file contains the information for a Galaxy object. Galaxy objects hold
Planets and figure out the longest shortest path between any two given Planets
within the Galaxy.*/

#ifndef GALAXY_H
#define GALAXY_H
#include <vector>
#include "Planet.h"
#include "DHeap.h"

class Galaxy {

public:
   Galaxy();
   ~Galaxy();
   void addPlanet(Planet* p);
   Planet* getPlanet(int index);
   void findLongest();
   
private:
   std::vector<Planet*> system;
   void reset();
   int dijkstra(Planet* p, std::vector<Planet*>& longestPath);
};

#endif