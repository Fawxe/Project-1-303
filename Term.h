#pragma once

using namespace std;
#include <string>;


class Term {

private:
	int exponent;
	int coefficient;


public:
	int get_exponent() { return exponent; }
	int get_coefficient() { return coefficient; }
	void set_exponent(int new_expo) { exponent = new_expo; }
	void set_coefficient(int new_coeff) { coefficient = new_coeff; }

	friend bool operator<(const Term& left, const Term& right)
	{
		return (left.exponent < right.exponent);
	}

};



