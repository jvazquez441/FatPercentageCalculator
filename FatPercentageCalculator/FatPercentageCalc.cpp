/*
Jonathan Vazquez Rivera
jvazquez441@email.uagm.edu
Computer Science Tutor

Decision making laboratory
Assigment for COSC-131 students

Assigment:	Create an application that allows the user to enter the number of calories and fat grams in a food.
			The application should display the percentage of the calories that come from fat. If the calories
			from fat are less than 30% of the total calories of the food, it should also display a message
			indicating the food is low in fat.

			One gram of fat has 9 calories, so:
			Calories from fat = fat grams * 9

			The percentage of calories from fat can be calculated as:
			Percentage of calories from fat = Calories from fat / total calories

			Input validation: Make sure the number of calories are not less than 0. Also, the number of
			calories from fat cannot be greater than the total number of calories. If that happens, display an
			error message indicating that either the calories or fat grams were incorrectly entered.

			Use the following test data to determine if the application is calculating properly:
			Calories and Fat Percentage Fat
			200 calories, 8 fat grams Percentage of calories from fat: 36%
			150 calories 2 fat grams Percentage of calories from fat: 12%
			(a low-fat food)
			500 calories, 30 fat grams Percentage of calories from fat: 54%

										****NOTICE****
			Program made with what has been seen in class. No advanced programming.
*/

#include <iostream>

using namespace std;

int main()
{
	// Variables used in the program.
	double fatGrams;
	double totalCalories;
	double caloriesFromFat;
	double percentageCalFromFat;

	cout << "Fat Percentage Calculator" << endl;
	cout << "Please enter the total of calories: ";
	cin >> totalCalories;

	if (totalCalories > 0)
	{
		cout << "Enter the amount of fat grams(Cant be greater than the total calories):";
		cin >> fatGrams;
		caloriesFromFat = fatGrams * 9;

		if (fatGrams < 0)
		{
			// cout << "\033[2J\033[1;1H"; <---- Command used to clear the console for the user. 
			// System("CLS") not used because is a system command and it could cause problem when running program on Linux.
			cout << "\033[2J\033[1;1H"; 
			cout << "Fat grams can't be a negative number. Try again" << endl;
			cout << "Fat grams: " << fatGrams << endl;
		}
		else
		{
			if (caloriesFromFat < totalCalories)
			{
				percentageCalFromFat = (caloriesFromFat / totalCalories) * 100;

				if (percentageCalFromFat < 30)
				{
					cout << "\033[2J\033[1;1H";
					cout << "*****Your food information*****" << endl;
					cout << "Total calories: " << totalCalories << endl;
					cout << "Calories from Fat: " << caloriesFromFat << endl;
					cout << "Percentage of Fat:" << percentageCalFromFat << "%" << endl;
					cout << "This meal is low on fat (Below 30%)." << endl;
				}
				else
				{
					cout << "\033[2J\033[1;1H";
					cout << "*****Your food information*****" << endl;
					cout << "Total calories: " << totalCalories << endl;
					cout << "Calories from Fat: " << caloriesFromFat << endl;
					cout << "Percentage of Fat:" << percentageCalFromFat << "%" << endl;
				}
			}
			else
			{
				cout << "\033[2J\033[1;1H";
				cout << "The amount of calories from fat is greater than the total calories" << endl;
				cout << "Total calories: " << totalCalories << endl;
				cout << "Calories from Fat: " << caloriesFromFat << endl;
			}
		}
	}
	else
	{
		cout << "\033[2J\033[1;1H";
		cout << "Total calories are below zero and amount has been set to 1. Try again.";
		totalCalories = 1;
	}

	return 0;
}