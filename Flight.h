/*
 *Kerem Tekik
 *22002730
 *CS 201-2
 *
 */


#ifndef FLIGHTMAP_FLIGHT_H
#define FLIGHTMAP_FLIGHT_H

using namespace std;
#include <string>
#include <cstdlib>
#include "Flight.h"

class Flight{
private:

    string originCity;
    string destinationCity;
    int flightId;
    int cost;

public:
    Flight();
    Flight(string originCity, string destinationCity, int flightId, int cost );
    ~Flight();
    void setOriginCity(string city);
    void setDestinationCity(string city);
    void setFlightId(int id);
    void setCost(int cost);
    string  getOriginCity();
    string  getDestinationCity();
    int getFlightId();
    int getCost();
    Flight(Flight *pFlight);

};
#endif //FLIGHTMAP_FLIGHT_H
