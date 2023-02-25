#include <iostream>

using namespace std;
#include <string>
#include <iostream>
#include "FlightMap.h"
int main() {

    // test 1
    /*
    FlightMap fm( "cityfilefile.txt", "flightFilefile.txt" );
    fm.displayAllCities();
    cout << endl;
    fm.displayAdjacentCities( "W" );
    cout << endl;
    fm.displayAdjacentCities( "X" );
    cout << endl;
    fm.displayFlightMap();
    cout << endl;
    fm.findFlights( "W", "Z" );
    cout << endl;
    fm.findFlights( "S", "P" );
    cout << endl;
    fm.findFlights( "Y", "Z" );
    cout << endl;
    fm.findFlights( "P", "Z" );
    cout << endl;
    cout << endl;

    fm.displayAllCities();
    cout << endl;

    fm.displayAdjacentCities( "X" );
    cout << endl;

    fm.displayAdjacentCities( "W" );
    cout << endl;

    fm.displayFlightMap();
    cout << endl;
    */

    // test 2


    FlightMap fm("testcity.txt", "testflight.txt");
    fm.displayAllCities();
    cout<<endl;
    fm.displayAdjacentCities("A");
    cout<<endl;
    fm.displayAdjacentCities("B");
    cout<<endl;
    fm.displayAdjacentCities("C");
    cout<<endl;
    fm.displayAdjacentCities("D");
    cout<<endl;
    fm.displayAdjacentCities("E");
    cout<<endl;
    fm.displayAdjacentCities("F");
    cout<<endl;
    fm.displayAdjacentCities("G");
    cout<<endl;
    fm.displayFlightMap();
    cout<<endl;
    fm.findFlights("A", "E");
    cout<<endl;
    fm.findFlights("A","F");
    cout<<endl;
    fm.findFlights("A", "G");
    cout<<endl;
    fm.findFlights("C","F");
    cout<<endl;
    fm.findFlights("F","A");
    cout<<endl;
    fm.displayAllCities();
    cout<<endl;
    fm.displayAdjacentCities("C");
    cout<<endl;
    fm.displayAdjacentCities("G");
    cout<<endl;
    fm.displayAdjacentCities("A");


    return 0;
}
