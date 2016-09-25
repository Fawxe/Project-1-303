#pragma once

using namespace std;
#include <iostream>;
#include <string>;
#include "list.h";
#include "Term.h";



	string Get_Choice()
	{
		{
			cout << "________Menu________" << endl;
			cout << "Please select from the options below.(use the number representing the choice)" << endl << endl;
			cout << "1) Enter First Polynomial (This will override your current polynomial)" << endl;
			cout << "2) Add Polynomial (Make sure to have already inserted Polynomial 1)" << endl;
			cout << "3) Display Polynomial Again (There must be a polynomial to display)" << endl;
			cout << "4) Exit Program" << endl;

		}
		string choice;
		cin >> choice;
		return choice;
	}

	string Get_Input() 
	{
		cout << "Please enter Your Polynomial in the following form.   3X^3-1X^2+1" << endl;
		string input;
		cin >> input;
		return input;
	}

	bool Display_polynomial(list<Term> polynomial)
	{
		if (polynomial.empty())
			return false;
		cout << endl;
		cout << "You're Polynomial is:" << endl;
		cout << endl;
		list<Term>::iterator itr = polynomial.begin();
		Term first = *itr;
		cout << first.get_coefficient();
		if (first.get_exponent() > 0)
		{
			cout << "x";
			if (first.get_exponent() > 1)
				cout << "^" + first.get_exponent();
		}
		itr++;
		for (itr; itr != polynomial.end(); itr++)
		{
			Term Node = *itr;
			int coefficient = Node.get_coefficient();
			int exponent = Node.get_exponent();
			if (coefficient > 0)			//this if statement adds an operator to positive numbers for output
				cout << "+" << coefficient;

			else if (coefficient == 0)
				continue;

			else
				cout << coefficient;

			if (exponent > 0)
			{
				cout << "x";
				if (exponent > 1)
				{
					cout << "^";
					cout << exponent;
				}
			}
		}
		cout << endl;
	}
