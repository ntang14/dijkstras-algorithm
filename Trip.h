/*Nancy Tang Assignment 5 Trip.h file
This file contains the information for a Trip object. Trip objects keep track
of one trip made by a given ship. The Trip object keeps track of the ship that
made the trip, the starting planet, the ending planet, the departure time, and
the arrival time.*/

#ifndef TRIP_H
#define TRIP_H
#include <string>
#include <iostream>
#include <vector>
#include <climits>
class Trip {

public:
   Trip(std::string* vessel, std::string* firstPlanet,
         std::string* destination, int startTime, int endTime);
   int getTime();
   int print();
   int getArrivalTime();
   
private:
   std::string ship, startPlanet, endPlanet;
   int departureTime, arrivalTime;
};

#endif