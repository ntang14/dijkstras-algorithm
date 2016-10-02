/*Nancy Tang Assignment 5 Galaxy.cpp file
This file contains the functions for a Galaxy class that holds Planets. The
Galaxy also finds the longest shortest path between any two given Planets in
the Galaxy.*/

#include "Galaxy.h"
using namespace std;

Galaxy::Galaxy() {

}

Galaxy::~Galaxy() {
   for(int i = 0; i < system.size(); i++) {
      delete system[i];
      system[i] = NULL;
   }
}

void Galaxy::addPlanet(Planet* p) {
   system.push_back(p);
}

Planet* Galaxy::getPlanet(int index) {
   return system[index];
}

// goes through each planet to see which one has the longest shortest path
void Galaxy::findLongest() {
   int maxCost = 0;
   vector<Planet*> longestPath;
   vector<Planet*> path;
   for (int i = 0; i < system.size(); i++) {
      system[i]->setCost(0);
      int cost = dijkstra(system[i], path);
      if (cost > maxCost) {
         maxCost = cost;
         longestPath = path;
      }
      reset();
      path.clear();
   }
   int time = 0;
   for (int i = longestPath.size() - 1; i > 0; i--) {
      Planet* p = longestPath[i];
      int travelTime = p->print(longestPath[i - 1], time);
      time = travelTime + LAYOVER_TIME;
   }
}

// tells each planet to set all path-related variables back to default
void Galaxy::reset() {
   for (int i = 0; i < system.size(); i++) {
      system[i]->reset();
   }
}

// takes the destinations from one planet and finds the longest shortest path
int Galaxy::dijkstra(Planet* p, vector<Planet*>& longestPath) {
   DHeap<Planet>* destinations = new DHeap<Planet>(Planet::compare);
   for (int i = 0; i < system.size(); i++) {
      system[i]->setPriority(destinations->push(system[i]));
   }
   Planet* temp;
   while (!destinations->is_empty()) {
      temp = destinations->pop();
      if (temp->getCost() == INT_MAX) {
         cout << *p->getName() << " could not reach " << *temp->getName() << "."
               << endl;
      } else {
         temp->updateCosts(destinations);
      }
      temp->setPriority(-1);
   }
   if (temp->getCost() != INT_MAX) {
      Planet* current = temp;
      while (current != p) {
         longestPath.push_back(current);
         current = current->getParent();
      }
      longestPath.push_back(p);
   }
   delete destinations;
   return temp->getCost();
}