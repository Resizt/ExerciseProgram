#include <iostream>
#include <sstream>

// Weight
// Height
// Age
// Calories level target

using namespace std;

void startup(string[10][5],int);

int main(){

	string input[10][5];
	int x = 1, choice;
	cout << "Exercise program" << endl;
	cout << "-------------------------------------------" << endl;

	cout << "1. New User" << endl;
	cout << "2. Existing User" << endl;
	cout << "X. Exit Program" << endl;
	
	cin >> choice;

	while (choice != 3){
		switch (choice){
			case 1:
				startup(input, x);
			case 2:
				//	loadup();
			case 3:
				exit(0);
		}
	}
}

void startup(string input[10][5], int x) {
	cout << "Enter your name please" << endl;
	cin.ignore();
	getline(cin, input[x][1]);


	cout << "Choose your Sex" << endl;
	cin.ignore();
	getline(cin, input[x][2]);

	cout << "Enter your Height in inches (So 5'5 would be 66)" << endl;
	cin.ignore();
	getline(cin, input[x][3]);

	cout << "Enter your Age" << endl;
	cin.ignore();
	getline(cin, input[x][4]);

	cout << "Enter your Weight (Just the numbers in lbs)" << endl;
	cin.ignore();
	getline(cin, input[x][5]);
}