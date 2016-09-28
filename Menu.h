#pragma once

using namespace std;
#include <iostream>;
#include <string>;
#include "list.h";
#include "Term.h";

bool Validate_input(string validCharacters, string input) //insures that only valid input is recieved
{
	for (int i = 0; i < input.size(); i++) //iterates through string input
	{
		if (validCharacters.find(input[i]) == -1) //look for character 
		{
			cout << endl << input[i];
			cout << " is not a valid input character." << endl << endl;  //inform user if it isn't there
			return false;
		}
	}
	return true;
}

string Get_Choice(string firstPolynomial, string secondPolynomial) // first menu allows user to choose action
{
	bool validInput = false;
	string choice;
	string validInputString = "012";  
	while (!validInput)
	{
		cout << endl;
		cout << "________Menu________" << endl;  //initial choice to allow input of the 2 polynomials
		cout << "Please select from the options below.(use the number representing the choice)" << endl << endl;
		cout << "0) Exit Program" << endl;
		cout << "1) Enter the 1st Polynomial ";
		if (firstPolynomial.size() > 0)
			cout << ": (" << firstPolynomial << ")" << endl;  //collects first polynomial
		else
			cout << endl;

		cout << "2) Enter the 2nd Polynomial ";
		if (secondPolynomial.size() > 0)
			cout << ": (" << secondPolynomial << ")" << endl; //collects second
		else
			cout << endl;
		if (firstPolynomial.size() > 0 && secondPolynomial.size() > 0) {  //opens up more options if there are polynomials to use

			cout << "3) Add the two Polynomials. " << endl;
			cout << "4) Add the two Polynomials and replace the first with the result." << endl;
			cout << "[0-4]:";
			validInputString = "01234";  //increase valid characters
		}
		else {
			cout << "[0-2]:";
		}
		cin >> choice;
		validInput = Validate_input(validInputString, choice);
	}
	return choice;
}

string Get_Input() //prompts for and recieves the polynomial
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

string Display_polynomial(list<Term> polynomial, string firstPolynomial, string secondPolynomial) //outputs the polynomial in the proper format
{
	string outputPolynomial = "";
	list<Term>::iterator itr = polynomial.begin();  //set up iterator for the list
	Term first = *itr;
	if (first.get_coefficient() != 0)
		outputPolynomial = to_string(first.get_coefficient());  // this first part is to allow no + signs in the first term
	if (first.get_exponent() != 0)
	{
		outputPolynomial = outputPolynomial + "x";
		outputPolynomial = outputPolynomial + "^" + to_string(first.get_exponent());
	}
	itr++;  //move iterator to the second term to continue the display
	for (itr; itr != polynomial.end(); itr++)  //iterate through terms
	{
		Term Node = *itr;
		int coefficient = Node.get_coefficient();
		int exponent = Node.get_exponent();
		if (coefficient > 0)			//this if statement adds an operator to positive numbers for output
			outputPolynomial = outputPolynomial + "+" + to_string((*itr).get_coefficient());
		else if (coefficient < 0 )
			outputPolynomial = outputPolynomial + to_string((*itr).get_coefficient());  //changes the sign for negative numbers
		else if (coefficient == 0)
			continue;
		else
			outputPolynomial = outputPolynomial + to_string((*itr).get_coefficient());

		if (exponent != 0)
		{
			outputPolynomial = outputPolynomial + "x";
			if (exponent > 1||exponent<0)
			{
				outputPolynomial = outputPolynomial + "^" + to_string((*itr).get_exponent());
			}
		}
	}
	cout << endl;
	cout << "  " << firstPolynomial << endl;
	cout << "+ " << secondPolynomial << endl;  //outputs addition and result
	cout << "= " << outputPolynomial << endl;
	return outputPolynomial;
}
