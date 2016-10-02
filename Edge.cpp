/*Nancy Tang Assignment 5 Edge.cpp file
This file contains the functions for the Edge class. Edges keep track of all
the possible routes from one planet to another. They keep track of which ship
will make the route, when it departs, and when it arrives at the destination.*/

#include "Edge.h"
using namespace std;

Edge::Edge(Planet* planet) {
   destination = planet;
}

Edge::~Edge() {
   for (int i = 0; i < travels.size(); i++) {
      delete travels[i];
      travels[i] = NULL;
   }
   destination = NULL;
}

int Edge::print(int time) {
   int minTime = INT_MAX;
   int index = INT_MAX;
   for (int i = 0; i < travels.size(); i++) {
      int temp = travels[i]->getTime();
      if (temp >= time && temp < minTime) {
         minTime = travels[i]->getArrivalTime();
         index = i;
      }
   }
   return travels[index]->print();
}

void Edge::addTrip(int time, string* vessel, int arrival, string* start,
      string* end) {
   Trip* t = new Trip(vessel, start, end, time, arrival);
   travels.push_back(t);
}

Planet* Edge::getDestination() {
   return destination;
}

int Edge::getNext(int time) {
   int minTime = INT_MAX;
   for (int i = 0; i < travels.size(); i++) {
      int temp = travels[i]->getTime();
      if (temp >= time && temp < minTime) {
         minTime = travels[i]->getArrivalTime();
      }
   }
   return minTime;
}