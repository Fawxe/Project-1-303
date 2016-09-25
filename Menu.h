#pragma once

using namespace std;
#include <iostream>;
#include <string>;



	string Get_Choice(bool complete)//complete shows if there is something to display
	{
		{
			cout << "________Menu________" << endl;
			cout << "Please select from the options below.(use the number representing the choice)" << endl << endl;
			cout << "1) Enter First Polynomial" << endl;
			cout << "2) Add Polynomial" << endl;
			cout << "3) Display Polynomial Again" << endl;
			cout << "4) Exit Program" << endl;

		}
		string choice;
		cin >> choice;
		return choice;
	}

	string Get_Input() 
	{
		cout << "Please enter Your Polynomial in the following form.   3X^3–1X^2+1" << endl;
		string input;
		cin >> input;
		return input;
	}
