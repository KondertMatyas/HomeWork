// HomeWork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Street.h"

using namespace std;

list<Street> load(string fileName) {
    list<Street> streets;
    ifstream in(fileName);
    string line;
    vector<string> result;
    while (getline(in, line)) {
        stringstream linestream(line);
        string cell;

        while (getline(linestream, cell, ',')) {
            result.push_back(cell);
        }

        int lowNum = stoi(result[1]);
        int highNum = stoi(result[2]);
        string street = result[16];
        string streetType = result[17];
        street = street.substr(1, street.length() - 2);
        streetType = streetType.substr(1, streetType.length() - 2);
        string streetName = street + " " + streetType;
        string cityName = result[26];
        cityName = cityName.substr(1, cityName.length() - 2);
        string side = result[20];
        auto it = find_if(streets.begin(), streets.end(), [&](Street& s) {
            return s.isSameStreet(streetName, cityName);
        });
        if (it == streets.end()) {
            streets.push_back(Street(streetName, cityName));
            streets.back().addSegment(lowNum, highNum, side);
        }
        else {
            it->addSegment(lowNum, highNum, side);
        }
        result.clear();
    }
    return streets;
}


int main()
{
    string fileName;
    cout << "Please input the name of the file you would like to process(ex. network.mid):";
    cin >> fileName;
    list<Street> streets = load(fileName);

    for (Street street : streets)
    {
        street.print();
    }

    return 0;
}

