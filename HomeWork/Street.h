#pragma once
#include <iostream>
#include <string>
#include <set>
#include <list>
#include "Duplicates.h"

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
				if (i % 2 == 1) {
					numbers_odd.insert(i);
				}
			}
		}
		else if (side == "\"E\"") {
			for (int i = low; i <= high; i++) {
				if (i % 2 == 0) {
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

	list<Duplicates> getAllDups() {
		list<Duplicates> dups;
		if (this->numbers_odd.size() > 0) {
			list<Duplicates> dupsO = getDupsInList(this->numbers_odd, 'O');
			dups.splice(dups.end(), dupsO);
		}
		if (this->numbers_even.size() > 0) {
			list<Duplicates> dupsE = getDupsInList(this->numbers_even, 'E');
			dups.splice(dups.end(), dupsE);
		}
		if (this->numbers_mixed.size() > 0) {
			list<Duplicates> dupsM = getDupsInList(this->numbers_mixed, 'M');
			dups.splice(dups.end(), dupsM);
		}
		return dups;
	}

	list<Duplicates> getDupsInList(multiset<int> nums,char type) {
		list<Duplicates> dups;
		int prev = *nums.begin();
		auto it = nums.begin();
		bool inSegment = false;
		int prevNoInSegment = -1;
		if (it != nums.end()) {
			++it;
		}
		while (it != nums.end()) {
			if (*it == prev)
			{
				if (inSegment && 
					(((type == 'O' || type == 'E') && prevNoInSegment + 2 == prev) || 
						(type == 'M' && prevNoInSegment + 1 == prev)))
						dups.back().addToSeries(type);
				else
					dups.push_back(Duplicates(streetName, type, prev));
				inSegment = true;
				prevNoInSegment = prev;
				while (*it == prev && it != nums.end()) {
					prev = *it;
					++it;
				}
				if (it == nums.end()) {
					break;
				}
			}
			else {
				inSegment = false;
			}
			prev = *it;
			++it;
		}
		return dups;
	}
};

