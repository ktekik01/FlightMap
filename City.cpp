/*
 *Kerem Tekik
 *22002730
 *CS 201-2
 *
 */

#include "City.h"
#include <algorithm>
using namespace std;
City::City(string name) {
    this->cityName = name;
    this->isVisited = false;
}

City::~City() {
    for(Flight* fl: adjacentCityList) {
        if(fl != NULL) {
            delete fl;
            fl = NULL;
        }
    }
}

string City::getName() {
    return this->cityName;
}

void City::setName(string name) {
    this->cityName = name;
}

list<Flight *> City::getAdjCityList() {
    return this->adjacentCityList;
}


void City::addToAdjCityList(Flight* flight) {
    this->adjacentCityList.push_back(flight);
    this->adjacentCityList.sort([](auto f1, auto f2){
        if(f1->getDestinationCity() < f2->getDestinationCity())
            return true;
        else
            return false;
            });
}

bool City::getIsVisitedBy(City* from) {
    if(find(visitedByList.begin(), visitedByList.end(), from) == visitedByList.end()) {
        return false;
    }
    return true;
}

void City::setIsVisited(City* from) {
    visitedByList.push_back(from);
}

void City::unvisit(){
    isVisited = false;
}

void City::setNotVisited() {
    visitedByList.clear();
}
