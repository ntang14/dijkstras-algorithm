/*Nancy Tang Assignment 5 Edge.h file
This file contains the information for the Edge class. Edges keep track of all
the possible routes from one planet to another. They keep track of which ship
will make the route, when it departs, and when it arrives at the destination.*/

const int LAYOVER_TIME = 4;
#ifndef EDGE_H
#define EDGE_H
class Planet;
#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include "Trip.h"

class Edge {

public:
   Edge(Planet* planet = NULL);
   ~Edge();
   void addTrip(int time, std::string* vessel, int arrival, std::string* start,
         std::string* end);
   int print(int time);
   Planet* getDestination();
   int getNext(int time);
   
private:
   std::vector<Trip*> travels;
   Planet* destination;
};

#endif