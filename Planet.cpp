/*Nancy Tang Assignment 5 Planet.cpp file
This file contains the functions for a Planet class. Planets keep track of
their connections to other planets. When looking for the longest shortest path,
Planets keep track of which Planet came before them and the cost of travel to
get there.*/

#include "Planet.h"
#include <iostream>
using namespace std;

Planet::Planet(string planet) {
   name = planet;
}

Planet::~Planet() {
   for (int i = 0; i < destinations.size(); i++) {
      delete destinations[i];
      destinations[i] = NULL;
   }
}

int Planet::getPriority() {
   return priority;
}

void Planet::setPriority(int value) {
   priority = value;
}

void Planet::addDestination(Planet* planet, int departTime, string* ship,
      int arrival) {
   bool haveDestination = false;
   Edge* e;
   for (int i = 0; i < destinations.size(); i++) {
      if (planet == destinations[i]->getDestination()) {
         e = destinations[i];
         haveDestination = true;
         break;
      }
   }
   if (!haveDestination) {
      e = new Edge(planet);
      destinations.push_back(e);
   }
   e->addTrip(departTime, ship, arrival, &name, planet->getName());
}

bool Planet::compare(Planet* left, Planet* right) {
   return left->getCost() < right->getCost();
}

string* Planet::getName() {
   return &name;
}

// resets cost and parent information once a longest-shortest path has been
// found for a given planet to prepare for the next search
void Planet::reset() {
   parent = NULL;
   priority = INT_MAX;
   cost = INT_MAX;
}

void Planet::setCost(int num) {
   cost = num;
}

int Planet::print(Planet* next, int time) {
   for (int i = 0; i < destinations.size(); i++) {
      if (destinations[i]->getDestination() == next) {
         return destinations[i]->print(time);
      }
   }
}

int Planet::getCost() {
   return cost;
}

void Planet::updateCosts(DHeap<Planet>* connections) {
   for (int i = 0; i < destinations.size(); i++) {
      Planet* p = destinations[i]->getDestination();
      if (p->getPriority() != -1) {
         int newCost;
         if (cost != 0) {
            newCost = destinations[i]->getNext(cost + LAYOVER_TIME);
         } else {
            newCost = destinations[i]->getNext(cost);
         }
         if (p->getCost() > newCost) {
            p->setCost(newCost);
            connections->decreaseKey(p);
            p->setParent(this);
         }
      }
   }
}

Planet* Planet::getParent() {
   return parent;
}

void Planet::setParent(Planet* p) {
   parent = p;
}