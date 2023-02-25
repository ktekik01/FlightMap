/*
 *Kerem Tekik
 *22002730
 *CS 201-2
 *
 */


#include "Flight.h"

Flight::Flight() {

}

Flight::Flight(string originCity, string destinationCity, int flightId, int cost) {
    this->originCity = originCity;
    this->destinationCity = destinationCity;
    this->flightId = flightId;
    this->cost = cost;
}

Flight::~Flight() {

}

void Flight::setCost(int cost) {
    this->cost = cost;
}

void Flight::setDestinationCity(string city) {
    this->destinationCity = city;
}

void Flight::setFlightId(int id) {
    this->flightId = id;
}

void Flight::setOriginCity(string city) {
    this->originCity = city;
}

int Flight::getCost() {
    return this->cost;
}

int Flight::getFlightId() {
    return this->flightId;
}

string Flight::getDestinationCity() {
    return destinationCity;
}

string Flight::getOriginCity() {
    return this->originCity;
}

Flight::Flight(Flight *pFlight) {
    this->originCity = pFlight->originCity;
    this->destinationCity = pFlight->destinationCity;
    this->flightId = pFlight->flightId;
    this->cost = pFlight->cost;
}

