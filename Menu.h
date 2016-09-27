#pragma once

using namespace std;
#include <iostream>;
#include <string>;
#include "list.h";
#include "Term.h";

bool Validate_input(string validCharacters, string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (validCharacters.find(input[i]) == -1)
		{
			cout << endl << input[i];
			cout << " is not a valid input character." << endl << endl;
			return false;
		}
	}
	return true;
}

string Get_Choice(string firstPolynomial, string secondPolynomial)
{
	bool validInput = false;
	string choice;
	string validInputString = "012";
	while (!validInput)
	{
		cout << endl;
		cout << "________Menu________" << endl;
		cout << "Please select from the options below.(use the number representing the choice)" << endl << endl;
		cout << "0) Exit Program" << endl;
		cout << "1) Enter the 1st Polynomial ";
		if (firstPolynomial.size() > 0)
			cout << ": (" << firstPolynomial << ")" << endl;
		else
			cout << endl;

		cout << "2) Enter the 2nd Polynomial ";
		if (secondPolynomial.size() > 0)
			cout << ": (" << secondPolynomial << ")" << endl;
		else
			cout << endl;
		if (firstPolynomial.size() > 0 && secondPolynomial.size() > 0) {

			cout << "3) Add the two Polynomials. " << endl;
			cout << "4) Add the two Polynomials and replace the first with the result." << endl;
			cout << "[0-4]:";
			validInputString = "01234";
		}
		else {
			cout << "[0-2]:";
		}
		cin >> choice;
		validInput = Validate_input(validInputString, choice);
	}
	return choice;
}

string Get_Input()
{
	bool validInput = false;
	string input;
	while (!validInput)
	{
		cout << "Please enter Your Polynomial in the following form.   3X^3-1X^2+1" << endl;
		cout << " :";
		cin >> input;
		validInput = Validate_input("0123456789xX-+^", input);
	}
	return input;
}

string Display_polynomial(list<Term> polynomial, string firstPolynomial, string secondPolynomial)
{
	string outputPolynomial = "";
	list<Term>::iterator itr = polynomial.begin();
	Term first = *itr;
	if (first.get_coefficient() != 0)
		outputPolynomial = to_string(first.get_coefficient());
	if (first.get_exponent() > 0)
	{
		outputPolynomial = outputPolynomial + "x";
		if (first.get_exponent() > 1)
			outputPolynomial = outputPolynomial + "^" + to_string(first.get_exponent());
	}
	itr++;
	for (itr; itr != polynomial.end(); itr++)
	{
		Term Node = *itr;
		int coefficient = Node.get_coefficient();
		int exponent = Node.get_exponent();
		if (coefficient > 0)			//this if statement adds an operator to positive numbers for output
			outputPolynomial = outputPolynomial + "+" + to_string((*itr).get_coefficient());
		else if (coefficient == 0)
			continue;
		else
			outputPolynomial = outputPolynomial + to_string((*itr).get_coefficient());

		if (exponent > 0)
		{
			outputPolynomial = outputPolynomial + "x";
			if (exponent > 1)
			{
				outputPolynomial = outputPolynomial + "^" + to_string((*itr).get_exponent());
			}
		}
	}
	cout << endl;
	cout << "  " << firstPolynomial << endl;
	cout << "+ " << secondPolynomial << endl;
	cout << "= " << outputPolynomial << endl;
	return outputPolynomial;
}
