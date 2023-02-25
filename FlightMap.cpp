/*
 *Kerem Tekik
 *22002730
 *CS 201-2
 *
 */

using namespace std;
#include "FlightMap.h"
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include "City.h"

FlightMap::FlightMap(const string cityFile, const string flightFile) {

    // CITY LIST CONSTRUCTION
    int cityCount = 0;
    string cityName;
    ifstream cities;
    cities.open(cityFile.c_str(), ios_base::in);


    int flightCount = 0;
    string originCity;
    string destinationCity;
    string flightId;
    string cost;
    ifstream flights;
    flights.open(flightFile.c_str(), ios_base::in);

    if(!cities.is_open() && flights.is_open()){
        cout<<"Input file "<<cityFile<<" does not exist"<<endl;
        return;
    }
    if(cities.is_open() && !flights.is_open()){
        cout<<"Input file "<<flightFile<<" does not exist"<<endl;
        return;
    }
    if(!cities.is_open() && !flights.is_open()){
        cout<<"Input file "<<cityFile<<" does not exist"<<endl;
        cout<<"Input file "<<flightFile<<" does not exist"<<endl;
        return;
    }

    while(cities >> cityName){


        if(cityName == "") break;
        citiesMap.insert(pair <string, City*> (cityName, new City(cityName)));
        cityCount++;
    }
    cities.close();

    //FLIGHT LIST COUNSTRUCTION


    while(flights.eof() == false){
        getline(flights, originCity, ';');
        getline(flights, destinationCity, ';');
        getline(flights, flightId, ';');
        getline(flights, cost, '\n');
        if(originCity == ""){
            continue;
        }

        Flight* flight = new Flight(originCity, destinationCity, stoi(flightId), stoi(cost));
        flightList.push_back(flight);
        citiesMap[originCity]->addToAdjCityList(flight);
        flightCount++;

    }
    flights.close();

    cout<<cityCount<<" cities and "<<flightCount<<" flights have been loaded"<<endl;

}

FlightMap::~FlightMap() {
    for(pair<string, City*> temp: citiesMap){
        delete temp.second;
    }

}

void FlightMap::displayAllCities() const {
    cout<<"The list of the cities that HPAir serves is given below:"<<endl;
    for( pair<const string, City*> traverse : citiesMap){
        cout<<traverse.first<<", ";
    }
    cout<<endl;
}

void FlightMap::displayAdjacentCities(const string cityName) const {
    list <Flight*> headCity = citiesMap.at(cityName)->getAdjCityList();
    cout<<"The cities adjacent to "<<cityName<<" are:"<<endl;
    cout<<cityName;
    cout<<" -> ";
    for(Flight* a: headCity){
         cout<<a->getDestinationCity()<<", ";
    }
    cout<<endl;
}


void FlightMap::displayFlightMap() const {
    cout<<"The whole flight map is given below:"<<endl;
    for(pair<string, City*> temp: citiesMap){
        cout<<temp.first<<" -> ";
        for(Flight *c: temp.second->getAdjCityList()){
            cout<<c->getDestinationCity()<<", ";
        }
        cout<<endl;
    }

}

void FlightMap::findFlights(const string deptCity, const string destCity) const {
    stack <City*> cityStack;
    stack <City*> tempStack;
    bool isPath = false;
    cout<<"Request is to fly from "<<deptCity<<" to "<<destCity<<":"<<endl;
    struct output{
        vector<string> out;
        unsigned int cost;
    };
    vector<output> alloutputs;

    unvisitAll();

    cityStack.push(citiesMap.at(deptCity));
    for(pair<const string, City* > traverse:citiesMap) {
        markVisited(citiesMap.at(deptCity), traverse.second);

    }

    City* topCity = cityStack.top();
    while(!cityStack.empty() && (topCity != citiesMap.at(destCity))){

        City* nextCity = getNextCity(topCity, cityStack);


        if(nextCity == NULL){
            cityStack.pop();
        }
        else{
            cityStack.push(nextCity);
            if(nextCity->getName() == destCity){
                while(!cityStack.empty()){
                    tempStack.push(cityStack.top());
                    cityStack.pop();
                }
                City* temp1 = NULL;
                unsigned int totalCost = 0;
                output thisOutput;
                while(!tempStack.empty())
                {
                    temp1 = tempStack.top();
                    cityStack.push(temp1);
                    tempStack.pop();
                    if(tempStack.empty()) break;
                    for(Flight temp: flightList){
                        if(temp.getDestinationCity() == tempStack.top()->getName() && temp.getOriginCity() == temp1->getName()){
                            string tempstr = "";
                            tempstr = "Flight #" + to_string(temp.getFlightId()) + " from " + temp.getOriginCity() + " to " + temp.getDestinationCity() + ", Cost: " + to_string(temp.getCost()) + " TL";
                            thisOutput.out.push_back(tempstr);
                            totalCost += temp.getCost();
                        }
                    }
                }
                thisOutput.out.push_back("Total Cost: " + to_string(totalCost) + " TL");
                thisOutput.cost = totalCost;
                alloutputs.push_back(thisOutput);
                cityStack.pop();
                cityStack.pop();
            }
            else if(nextCity != NULL){
                markVisited(nextCity, topCity);
            }
        }

        if(!cityStack.empty()){
            topCity = cityStack.top();
        }
    }

    struct sortAllOutputs {
        bool operator() (const output& first, const output& second){
            if(first.cost < second.cost){
                return true;
            }
            else{
                return false;
            }
        }
    };
    if(alloutputs.empty()){
        cout<<"Sorry. HPAir does not fly from "<<deptCity<<" to "<<destCity<<"."<<endl;
    }
    sort(alloutputs.begin(), alloutputs.end(), sortAllOutputs());
    for(output& o: alloutputs){
        for(string& s: o.out){
            cout<<s<<endl;
        }
    }
    while(!cityStack.empty()){
        cout<<cityStack.top()->getName()<<endl;
        cityStack.pop();
    }
}

void FlightMap::markVisited(City* originCity, City* from) const{
    originCity->setIsVisited(from);
}

void FlightMap::unvisitAll() const {
    for(pair <string, City* > temp: citiesMap){
        temp.second->setNotVisited();
    }
}

City * FlightMap::getNextCity(City* city, stack<City*> cs) const {
    list <Flight*> temp =  city->getAdjCityList();
    for(Flight* foo: temp){
        if(!citiesMap.at(foo->getDestinationCity())->getIsVisitedBy(citiesMap.at(foo->getOriginCity()))){
            while(!cs.empty()){
                if(cs.top() == citiesMap.at(foo->getDestinationCity()))
                    return NULL;
                cs.pop();
            }
            return citiesMap.at(foo->getDestinationCity());
        }
    }
    return NULL;
}
