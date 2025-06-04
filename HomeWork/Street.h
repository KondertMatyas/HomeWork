#pragma once
#include <iostream>
#include <string>
#include <set>

using namespace std;

class Street
{
private:
	string streetName;
	string cityName;
	multiset<int> numbers_odd;
	multiset<int> numbers_even;
	multiset<int> numbers_mixed;
public:
	Street(string streetName, string cityName) {
		this->streetName = streetName;
		this->cityName = cityName;
	}

	void addSegment(int low, int high,string side) {
		if (side == "\"M\"" || side == "\"\"") {
			for (int i = low; i <= high; i++) {
				numbers_mixed.insert(i);
			}
		}
		else if (side == "\"O\""){
			for (int i = low; i <= high; i++) {
				if (i % 2 == 0) {
					numbers_odd.insert(i);
				}
			}
		}
		else if (side == "\"E\"") {
			for (int i = low; i <= high; i++) {
				if (i % 2 == 1) {
					numbers_even.insert(i);
				}
			}
		}
	}

	bool isSameStreet(string street, string city) {
		return this->cityName == city && this->streetName == street;
	}

	void print() {
		cout << this->cityName << ": " << streetName << '\n';
		cout << "O: [";
		for (int number : numbers_odd) {
			cout << number << ", ";
		}
		cout << "]\n";
		cout << "E: [";
		for (int number : numbers_even) {
			cout << number << ", ";
		}
		cout << "]\n";
		cout << "M: [";
		for (int number : numbers_mixed) {
			cout << number << ", ";
		}
		cout << "]\n";
	}
};

