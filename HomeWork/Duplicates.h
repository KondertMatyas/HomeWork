#pragma once

#include <stdio.h>
#include <iostream>

using namespace std;

class Duplicates
{
private:
	string street;
	char type;
	int low;
	int high;
public:
	Duplicates(string street,char type,int num) {
		this->street = street;
		this->type = type;
		this->low = num;
		this->high = num;
	}

	void addToSeries(char type) {
		if (type == 'O' || type == 'E')
			this->high++;
		this->high++;
	}

	void print() {
		cout << street << ": " << type << " " << low << " " << high << '\n';
	}
};

