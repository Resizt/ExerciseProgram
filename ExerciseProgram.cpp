#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void newMember	(string[10][1], string[10][5], float[10][4], int);
void newSave	(string[10][1], string[10][5], float[10][4], int);
void printUser	(string[10][1], string[10][5], float[10][4], int);
void loadup		(string[10][1], string[10][5], float[10][4], int);

void menu();

int main(){
	string	uINPUTS[10][1], 
			tINPUTS[10][5];

	float	nINPUTS[10][4];
	int		x = 1, 
			choice = 0;

	loadup(uINPUTS, tINPUTS, nINPUTS, x);

	while (choice != 3){
		menu();
		cin >> choice;
		switch (choice){
			case 1:
				newMember(uINPUTS, tINPUTS, nINPUTS, x);
				newSave(uINPUTS, tINPUTS, nINPUTS, x);
				break;
			case 2:
			//	loadup();
			//	calorielimit(input, x)
				break;
			case 3:
				exit(0);
				break;
		}
	}
}


void newMember(string uINPUTS[10][1], string tINPUTS[10][5], float nINPUTS[10][4], int x) { // Rename function to New User 
	float bmi;
	string newUser;
	ofstream newFile;

	cout << "Enter your name please" << endl;
	cin.ignore();
	getline(cin, uINPUTS[x][1]);


	cout << "Choose your Sex" << endl;
	getline(cin, tINPUTS[x][1]);

	cout << "Enter your Height in inches (So 5'5 would be 66)" << endl;
	cin >> nINPUTS[x][1];

	cout << "Enter your Age" << endl;
	cin >> nINPUTS[x][2];

	cout << "Enter your Weight (Just the numbers in lbs)" << endl;
	cin >> nINPUTS[x][3];

	bmi = (703 * (nINPUTS[x][3] / (nINPUTS[x][1] * nINPUTS[x][1])));
	nINPUTS[x][4] = bmi;

	printUser(uINPUTS, tINPUTS, nINPUTS, x);
	x++;
}

void newSave(string uINPUTS[10][1], string tINPUTS[10][5], float nINPUTS[10][4], int x) {
	string newUser;
	ofstream newFile, database;

	newUser = uINPUTS[x][1];
	newUser = newUser + ".txt";

	database.open("Membership.txt");
	newFile.open(newUser);


	for (int i = 1; i <= x; i++) {
		database << uINPUTS[i][1] << endl;
	}
	newFile << uINPUTS[x][1] << endl;
	newFile << tINPUTS[x][1] << endl;
	newFile << nINPUTS[x][1] << endl;
	newFile << nINPUTS[x][2] << endl;
	newFile << nINPUTS[x][3] << endl;
	newFile << nINPUTS[x][4] << endl;


	newFile.close();
}

void printUser(string uINPUTS[10][1], string tINPUTS[10][5], float nINPUTS[10][4], int x) {
	system("CLS");
	cout << "Welcome to the program, here's your record so far" << endl;
	cout << "Name; "	<< uINPUTS[x][1] << endl;
	cout << "Height; "	<< nINPUTS[x][1] << endl;
	cout << "Weight; "	<< nINPUTS[x][3] << endl;
	cout << "Age; "		<< nINPUTS[x][2] << endl;
	cout << "BMI; "		<< nINPUTS[x][4] << endl;
	cout << "------------------------------------------" << endl;
}

void loadup (string uINPUTS[10][1], string tINPUTS[10][5], float nINPUTS[10][4], int x) { // Rename function to New User 
	string dbList;
	ifstream database;
	database.open("Membership.txt");
	for (int mebNum = 1; mebNum <= 10; mebNum++) {
		database >> uINPUTS[x][1];
		x++;
	}
}
void menu() {
	cout << "Exercise program" << endl;
	cout << "-------------------------------------------" << endl;

	cout << "1. New User" << endl;
	cout << "2. Existing User" << endl;
	cout << "X. Exit Program" << endl;
}

/*
void calorielimit(string tINPUTS[10][6], int nINPUTS[10][5], int x) {
	//if(input[10][6] < 80)
}
*/