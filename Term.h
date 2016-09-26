#pragma once

using namespace std;
#include <string>;


class Term {

private:
	int exponent = 0;
	int coefficient = 0;


public:
	int get_exponent() { return exponent; }  //simple getter
	int get_coefficient() { return coefficient; } //simple getter
	void set_exponent(int new_expo) { exponent = new_expo; } //simple setter
	void set_coefficient(int new_coeff) { coefficient = new_coeff; } //simple setter



	friend bool operator<(Term left, Term right)
	{
		return (left.exponent < right.exponent);
	}

	friend bool operator==(const Term& left, const Term& right) //checking only exponent is necessary 
	{
		return (left.exponent == right.exponent);
	}

	friend Term operator+(Term& left, Term& right) //allows addition of Terms
	{
		left.coefficient = right.coefficient + left.coefficient; //issues with additioin caused more specific declaration
		return left;
	}

};




