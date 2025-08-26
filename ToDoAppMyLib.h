#pragma once

#include <iostream>
using namespace std;


namespace SecondaryFunctions
{

	int ValidateInputIsANumber()
	{
		int Number;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "\nInvalid input, please enter a number\n";
			cin >> Number;
		}

		return Number;
	}

	void AppHeader(string AppName)
	{
		cout << "\n\n";
		cout << "\t\t\t\t--------------------------------------------------------\n\n";
		cout << "\t\t\t\t\t\t " << AppName << "\n\n";
		cout << "\t\t\t\t--------------------------------------------------------\n\n\n";
	}


	int ReadHowMany(string Question)
	{
		int NumberOf;

		cout << Question << " ";
		NumberOf = ValidateInputIsANumber();

		return NumberOf;
	}



}
