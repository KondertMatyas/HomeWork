// HomeWork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream in("network.mid");
    string input;
    while (getline(in, input)) {
        cout << input;
    }
}

