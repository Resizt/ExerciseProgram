#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdio.h> 
#include <io.h>

using namespace std;

void newMember	(string[10][1], string[10][5], float[10][4], int&);
void newSave	(string[10][1], string[10][5], float[10][4], int&);
void printUser	(string[10][1], string[10][5], float[10][4], int&);
void loadup		(string[10][1], string[10][5], float[10][4], int&);
void selectmember(string[10][1], string[10][5], float[10][4], int&);

void menu();

int main(){
	string	uINPUTS[10][1], 
			tINPUTS[10][5];

	float	nINPUTS[10][4];
	int		memberCount = 0;
	int		choice = 0;

	loadup(uINPUTS, tINPUTS, nINPUTS, memberCount);

	while (choice != 3){
		menu();
		cin >> choice;
		switch (choice){
			case 1:
				newMember(uINPUTS, tINPUTS, nINPUTS, memberCount);
				newSave(uINPUTS, tINPUTS, nINPUTS, memberCount);
				break;
			case 2:
				selectmember(uINPUTS, tINPUTS, nINPUTS, memberCount);
			//	loadup();
			//	calorielimit(input, x)
				break;
			case 3:
				exit(0);
				break;
		}
	}
}


void newMember(string uINPUTS[10][1], string tINPUTS[10][5], float nINPUTS[10][4], int& memberCount) { // Rename function to New User 
	float bmi;
	string newUser;
	ofstream newFile;

	cout << "Enter your name please" << endl;
	cin.ignore();
	getline(cin, uINPUTS[memberCount][1]);


	cout << "Choose your Sex" << endl;
	getline(cin, tINPUTS[memberCount][1]);

	cout << "Enter your Height in inches (So 5'5 would be 66)" << endl;
	cin >> nINPUTS[memberCount][1];

	cout << "Enter your Age" << endl;
	cin >> nINPUTS[memberCount][2];

	cout << "Enter your Weight (Just the numbers in lbs)" << endl;
	cin >> nINPUTS[memberCount][3];

	bmi = (703 * (nINPUTS[memberCount][3] / (nINPUTS[memberCount][1] * nINPUTS[memberCount][1])));
	nINPUTS[memberCount][4] = bmi;

	printUser(uINPUTS, tINPUTS, nINPUTS, memberCount);
}

void newSave(string uINPUTS[10][1], string tINPUTS[10][5], float nINPUTS[10][4], int& memberCount) {
	string newUser, nameHolder;
	ofstream newFile, database;

	newUser = uINPUTS[memberCount][1];
	newUser = newUser + ".txt";

	database.open("Membership.txt");
	newFile.open(newUser);


	for (int i = 1; i <= memberCount; i++){
		database << uINPUTS[i][1] << endl;
		nameHolder = uINPUTS[i + 1][1];
		if (nameHolder != "" || i = 2) {
			database << uINPUTS[i + 1][1] << endl;
		}
	}

	cout << "New file being created" << endl;
	newFile << uINPUTS[memberCount][1] << endl;
	newFile << tINPUTS[memberCount][1] << endl;
	newFile << nINPUTS[memberCount][1] << endl;
	newFile << nINPUTS[memberCount][2] << endl;
	newFile << nINPUTS[memberCount][3] << endl;
	newFile << nINPUTS[memberCount][4] << endl;


	newFile.close();
	memberCount++;
}

void printUser(string uINPUTS[10][1], string tINPUTS[10][5], float nINPUTS[10][4], int& memberCount) {
	system("CLS");
	cout << "Welcome to the program, here's your record so far" << endl;
	cout << "Name; "	<< uINPUTS[memberCount][1] << endl;
	cout << "Height; "	<< nINPUTS[memberCount][1] << endl;
	cout << "Weight; "	<< nINPUTS[memberCount][3] << endl;
	cout << "Age; "		<< nINPUTS[memberCount][2] << endl;
	cout << "BMI; "		<< nINPUTS[memberCount][4] << endl;
	cout << "------------------------------------------" << endl;
}

void loadup (string uINPUTS[10][1], string tINPUTS[10][5], float nINPUTS[10][4], int& memberCount) {
	string dbList, nameHolder;
	ifstream database;
	database.open("Membership.txt");
	if (!database) {
		cout << "First time boot" << endl;
	}
	else {
		for (int mebNum = 0; mebNum < 10; mebNum++) {
			getline(database, nameHolder);
			if (nameHolder != "") {
				memberCount++;
			//	cout << nameHolder << " is the " << mebNum << " in the program" << endl;
				uINPUTS[memberCount][1] = nameHolder;
				cout << "New member added, this is the " << memberCount << " memeber added" << endl;
			}
		}
	}
}

void menu() {
	cout << "Exercise program" << endl;
	cout << "-------------------------------------------" << endl;

	cout << "1. New User" << endl;
	cout << "2. Existing User" << endl;
	cout << "X. Exit Program" << endl;
}

void selectmember(string uINPUTS[10][1], string tINPUTS[10][5], float nINPUTS[10][4], int& memberCount) {
	system("CLS");
	for (int i = 1; i <= memberCount; i++) {
		cout << i << ". " << uINPUTS[i][1] << endl;
	}

	cout << "There are " << memberCount << " members in the database" << endl;
}

/*
void calorielimit(string tINPUTS[10][6], int nINPUTS[10][5], int x) {
	//if(input[10][6] < 80)
}
*/