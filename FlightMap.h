/*
 *Kerem Tekik
 *22002730
 *CS 201-2
 *
 */

#ifndef FLIGHTMAP_FLIGHTMAP_H
#define FLIGHTMAP_FLIGHTMAP_H

using namespace std;
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
#include "City.h"

class FlightMap {
public:
    FlightMap( const string cityFile, const string flightFile );
    ~FlightMap();
    void displayAllCities() const;
    void displayAdjacentCities( const string cityName ) const;
    void displayFlightMap() const;
    void findFlights( const string deptCity, const string destCity ) const;
    map<string, City*> citiesMap;
    list<Flight> flightList;
    void markVisited(City* originCity, City* from) const;
    void unvisitAll() const;
    City * getNextCity(City* city, stack<City*> cs) const;


};
#endif //FLIGHTMAP_FLIGHTMAP_H
