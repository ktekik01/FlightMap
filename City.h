/*
 *Kerem Tekik
 *22002730
 *CS 201-2
 *
 */


#ifndef FLIGHTMAP_CITY_H
#define FLIGHTMAP_CITY_H

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include "Flight.h"


using namespace std;
class City{
private:
    string cityName;
    list <Flight*> adjacentCityList;
    bool isVisited;
public:
    list <City*> visitedByList;
    City(string name);
    ~City();
    string getName();
    list <Flight*> getAdjCityList();
    void setName(string name);
    void addToAdjCityList(Flight* flight );
    bool sortAdjCityList(const Flight& first, const Flight& second);
    bool getIsVisitedBy(City* from);
    void setIsVisited(City* from);
    void setNotVisited();
    void unvisitNeighbors();
    void unvisit();
};

#endif //FLIGHTMAP_CITY_H
