/*Nancy Tang Assignment 5 Planet.h file
This file contains the information for a Planet class. Planets keep track of
their connections to other planets. When looking for the longest shortest path,
Planets keep track of which Planet came before them and the cost of travel to
get there.*/

#ifndef PLANET_H
#define PLANET_H
#include <string>
#include <climits>
#include <vector>
#include "Edge.h"
#include "DHeap.h"

class Planet {

public:
   Planet(std::string planet = " ");
   ~Planet();
   int getPriority();
   void setPriority(int value);
   int getCost();
   void setCost(int num);
   void addDestination(Planet* planet, int departTime, std::string* ship,
         int arrivalTime);
   int print(Planet* next, int time);
   static bool compare(Planet* left, Planet* right);
   void reset();
   std::string* getName();
   void updateCosts(DHeap<Planet>* connections);
   Planet* getParent();
   void setParent(Planet* p);
   
private:
   std::string name;
   int cost = INT_MAX;
   std::vector<Edge*> destinations;
   int priority;
   Planet* parent = NULL;
};

#endif