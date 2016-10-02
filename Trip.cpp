/*Nancy Tang Assignment 5 Trip.cpp file
This file contains the functions for a Trip object. Trip objects keep track
of one trip made by a given ship. The Trip object keeps track of the ship that
made the trip, the starting planet, the ending planet, the departure time, and
the arrival time.*/

#include "Trip.h"
using namespace std;

Trip::Trip(string* vessel, string* firstPlanet, string* destination,
      int startTime, int endTime) {

   ship = *vessel;
   startPlanet = *firstPlanet;
   endPlanet = *destination;
   departureTime = startTime;
   arrivalTime = endTime;
}

int Trip::getTime() {
   return departureTime;
}

int Trip::print() {
   cout << ship << "\t" << startPlanet << "\t" << departureTime << "\t" <<
         endPlanet << "\t" << arrivalTime << endl;
   return arrivalTime;
}

int Trip::getArrivalTime() {
   return arrivalTime;
}