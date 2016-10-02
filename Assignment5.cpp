/*Nancy Tang Assignment 5
This program finds the longest shortest path between any two planets within the
galaxy. The actual distances between planets are hard-coded into the program at
the beginning. The program then takes in ship routes along the planets. The
program verifies that these routes are valid and then creates a universe with
the routes, connecting planets to each other. The program then finds the
longest shortest route and prints out one possible path of that length.*/

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include "Galaxy.h"
#include "Planet.h"
using namespace std;

int main() {

   // hard code travel times
   map <string, map<string, int> > distances;
   distances["Alderaan"]["Bespin"] = 8;
   distances["Alderaan"]["Corellia"] = 6;
   distances["Alderaan"]["Coruscant"] = 16;
   distances["Alderaan"]["Dagobah"] = 30;
   distances["Alderaan"]["Dantooine"] = 13;
   distances["Alderaan"]["Endor"] = 18;
   distances["Alderaan"]["Gamorr"] = 180;
   distances["Alderaan"]["Hoth"] = 27;
   distances["Alderaan"]["Sullust"] = 213;
   distances["Alderaan"]["Tatooine"] = 7;
   distances["Alderaan"]["Yavin"] = 5;
   distances["Bespin"]["Corellia"] = 6;
   distances["Bespin"]["Coruscant"] = 158;
   distances["Bespin"]["Dagobah"] = 27;
   distances["Bespin"]["Dantooine"] = 22;
   distances["Bespin"]["Endor"] = 32;
   distances["Bespin"]["Gamorr"] = 75;
   distances["Bespin"]["Hoth"] = 4;
   distances["Bespin"]["Sullust"] = 268;
   distances["Bespin"]["Tatooine"] = 16;
   distances["Bespin"]["Yavin"] = 11;
   distances["Corellia"]["Coruscant"] = 4;
   distances["Corellia"]["Dagobah"] = 31;
   distances["Corellia"]["Dantooine"] = 12;
   distances["Corellia"]["Endor"] = 17;
   distances["Corellia"]["Gamorr"] = 254;
   distances["Corellia"]["Hoth"] = 21;
   distances["Corellia"]["Sullust"] = 19;
   distances["Corellia"]["Tatooine"] = 4;
   distances["Corellia"]["Yavin"] = 15;
   distances["Coruscant"]["Dagobah"] = 302;
   distances["Coruscant"]["Dantooine"] = 19;
   distances["Coruscant"]["Endor"] = 156;
   distances["Coruscant"]["Gamorr"] = 387;
   distances["Coruscant"]["Hoth"] = 81;
   distances["Coruscant"]["Sullust"] = 194;
   distances["Coruscant"]["Tatooine"] = 542;
   distances["Coruscant"]["Yavin"] = 128;
   distances["Dagobah"]["Dantooine"] = 32;
   distances["Dagobah"]["Endor"] = 97;
   distances["Dagobah"]["Gamorr"] = 656;
   distances["Dagobah"]["Hoth"] = 89;
   distances["Dagobah"]["Sullust"] = 78;
   distances["Dagobah"]["Tatooine"] = 28;
   distances["Dagobah"]["Yavin"] = 314;
   distances["Dantooine"]["Endor"] = 21;
   distances["Dantooine"]["Gamorr"] = 86;
   distances["Dantooine"]["Hoth"] = 28;
   distances["Dantooine"]["Sullust"] = 126;
   distances["Dantooine"]["Tatooine"] = 20;
   distances["Dantooine"]["Yavin"] = 12;
   distances["Endor"]["Gamorr"] = 341;
   distances["Endor"]["Hoth"] = 60;
   distances["Endor"]["Sullust"] = 19;
   distances["Endor"]["Tatooine"] = 24;
   distances["Endor"]["Yavin"] = 10;
   distances["Gamorr"]["Hoth"] = 346;
   distances["Gamorr"]["Sullust"] = 74;
   distances["Gamorr"]["Tatooine"] = 40;
   distances["Gamorr"]["Yavin"] = 55;
   distances["Hoth"]["Sullust"] = 22;
   distances["Hoth"]["Tatooine"] = 56;
   distances["Hoth"]["Yavin"] = 39;
   distances["Sullust"]["Tatooine"] = 38;
   distances["Sullust"]["Yavin"] = 17;
   distances["Tatooine"]["Yavin"] = 15;
   distances["Brentaal"]["Chandrila"] = 1;
   distances["Brentaal"]["Corellia"] = 3;
   distances["Brentaal"]["Corulag"] = 2;
   distances["Brentaal"]["Coruscant"] =7; 
   distances["Brentaal"]["Esseles"] = 2;
   distances["Brentaal"]["Rhinnal"] = 5;
   distances["Brentaal"]["Ralltiir"] = 7;
   distances["Chandrila"]["Corellia"] = 2;
   distances["Chandrila"]["Corulag"] = 1;
   distances["Chandrila"]["Coruscant"] = 5;
   distances["Chandrila"]["Esseles"] = 3;
   distances["Chandrila"]["Rhinnal"] = 2;
   distances["Chandrila"]["Ralltiir"] = 4;
   distances["Corellia"]["Corulag"] = 1;
   distances["Corellia"]["Esseles"] = 4;
   distances["Corellia"]["Rhinnal"] = 7;
   distances["Corellia"]["Ralltiir"] = 9;
   distances["Corulag"]["Coruscant"] = 6;
   distances["Corulag"]["Esseles"] = 4;
   distances["Corulag"]["Rhinnal"] = 8;
   distances["Corulag"]["Ralltiir"] = 11;
   distances["Coruscant"]["Esseles"] = 8;
   distances["Coruscant"]["Rhinnal"] = 10;
   distances["Coruscant"]["Ralltiir"] = 12;
   distances["Esseles"]["Rhinnal"] = 2;
   distances["Esseles"]["Ralltiir"] = 4;
   distances["Rhinnal"]["Ralltiir"] = 1;
   distances["Corellia"]["Kashyyyk"] = 36;
   distances["Corellia"]["Myrkr"] = 81;
   distances["Corellia"]["Wayland"] = 99;
   distances["Corellia"]["Yaga Minor"] = 12;
   distances["Coruscant"]["Kashyyyk"] = 43;
   distances["Coruscant"]["Myrkr"] = 108;
   distances["Coruscant"]["Wayland"] = 58;
   distances["Coruscant"]["Yaga Minor"] = 15;
   distances["Kashyyyk"]["Myrkr"] = 55;
   distances["Kashyyyk"]["Wayland"] = 54;
   distances["Kashyyyk"]["Yaga Minor"] = 53;
   distances["Myrkr"]["Wayland"] = 21;
   distances["Myrkr"]["Yaga Minor"] = 55;
   distances["Wayland"]["Yaga Minor"] = 30;
   distances["Bakura"]["Corellia"] = 52;
   distances["Bakura"]["Corporate Sector"] = 60;
   distances["Bakura"]["Coruscant"] = 77;
   distances["Bakura"]["Hapes Cluster"] = 11;
   distances["Bakura"]["Kessel"] = 27;
   distances["Bakura"]["Mon Calamari"] = 22;
   distances["Corellia"]["Corporate Sector"] = 9;
   distances["Corellia"]["Hapes Cluster"] = 21;
   distances["Corellia"]["Kessel"] = 10;
   distances["Corellia"]["Mon Calamari"] = 6;
   distances["Corporate Sector"]["Coruscant"] = 15;
   distances["Corporate Sector"]["Hapes Cluster"] = 7;
   distances["Corporate Sector"]["Kessel"] = 9;
   distances["Corporate Sector"]["Mon Calamari"] = 24;
   distances["Coruscant"]["Hapes Cluster"] = 39;
   distances["Coruscant"]["Kessel"] = 27;
   distances["Coruscant"]["Mon Calamari"] = 12;
   distances["Hapes Cluster"]["Kessel"] = 12;
   distances["Hapes Cluster"]["Mon Calamari"] = 18;
   distances["Kessel"]["Mon Calamari"] = 9;
   
   // create galaxy
   Galaxy g;
   int planetCount = -1;
   map <string, int> planets;
   
   // read information from standard input
   char temp[120];
   char temp2[40];
   string ship, startPlanet, endPlanet;
   int startTime, endTime;
   stringstream ss, values;
   int test = cin.peek();
   if (test == 35 || test == 10) {
      cin.getline(temp, 120);
   }
   cin.getline(temp, 120);
   ss << temp;
   ss.getline(temp2, 40, '\t');
   values.str(temp2);
   ship = values.str();
   if (ss.fail()) {
      cout << "Input is invalid" << endl;
      return 1;
   }
   ss.getline(temp2, 40, '\t');
   values.clear();
   values.str(temp2);
   startPlanet = values.str();
   if (ss.fail()) {
      cout << "Input is invalid." << endl;
      return 1;
   }
   ss.getline(temp2, 40, '\t');
   values << " ";
   values.clear();
   values << temp2;
   values >> startTime;
   if (ss.fail()) {
      cout << "Input is invalid." << endl;
      return 1;
   }
   
   for (;;) {
      ss.getline(temp2, 40, '\t');
      values.clear();
      values.str(temp2);
      endPlanet = values.str();
      if (ss.fail()) {
         cout << "Input is invalid." << endl;
         return 1;
      }
      ss.getline(temp2, 40, '\t');
      values << " ";
      values.clear();
      values << temp2;
      values >> endTime;
      if(ss.fail()) {
         cout << "Input is invalid." << endl;
         return 1;
      }
      
      // check to make sure distance values are accurate
      if ((endTime - startTime) != distances[startPlanet][endPlanet] && endTime
         - startTime != distances[endPlanet][startPlanet]) {
         cout << "The distance between " << startPlanet << " and " << endPlanet
            << " is not " << (endTime - startTime) << "." << endl;
         return 1;
      }
      
      // adds information to map
      Planet* p;
      map <string, int>::iterator index;
      index = planets.find(startPlanet);
      if (index == planets.end()) {
         planets[startPlanet] = ++planetCount;
         p = new Planet(startPlanet);
         g.addPlanet(p);
      } else {
         p = g.getPlanet(index->second);
      }
      Planet* p2;
      index = planets.find(endPlanet);
      if (index == planets.end()) {
         planets[endPlanet] = ++planetCount;
         p2 = new Planet(endPlanet);
         g.addPlanet(p2);
      } else {
         p2 = g.getPlanet(index->second);
      }
      p->addDestination(p2, startTime, &ship, endTime);
      
      string oldShip = ship;
      int test = cin.peek();
      if (test == 35 || test == 10) {
         cin.getline(temp, 120);
      }
      cin.getline(temp, 120);
      ss << " ";
      ss.clear();
      ss << temp;
      ss.getline(temp2, 40, '\t');
      if (ss.eof()) {
         break;
      }
      values.str(temp2);
      ship = values.str();
      if (ss.fail()) {
         cout << "Input is invalid" << endl;
         return 1;
      }
      ss.getline(temp2, 40, '\t');
      values.clear();
      values.str(temp2);
      startPlanet = values.str();;
      if (ss.fail()) {
         cout << "Input is invalid." << endl;
         return 1;
      }
      ss.getline(temp2, 40, '\t');
      values << " ";
      values.clear();
      values << temp2;
      values >> startTime;
      if (ss.fail()) {
         cout << "Input is invalid." << endl;
         return 1;
      }
      
      // make sure input is valid
      if (oldShip.compare(ship) == 0) {
         if (endPlanet != startPlanet || (startTime-endTime < 4)) {
            cout << "There is a problem with your routing." << endl;
            return 1;
         }
      }
   }
   // find the longest shortest path
   g.findLongest();
}