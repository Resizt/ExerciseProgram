#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdio.h> 
#include <io.h>
#include <Windows.h>

using namespace std;

void newMember		(string[11][1], string[11][5], float[11][4], int&);
void newSave		(string[11][1], string[11][5], float[11][4], int&);
void printUser		(string[11][1], string[11][5], float[11][4], int&);
void loadup			(string[11][1], string[11][5], float[11][4], int&);
void databaseUpdate	(string[11][1], string[11][5], float[11][4], int&);
void memberPrint	(string[11][1], string[11][5], float[11][4], int&);
void memberSelect	(string[11][1], string[11][5], float[11][4], int&, int);
void deleteMember	(string[11][1], string[11][5], float[11][4], int&, int);

/* User Selection */

//void diet			(string[11][1], string[11][5], float[11][4], int&);
//void exerciseRec	(string[11][1], string[11][5], float[11][4], int&);

/* Validation Fucntions */
void namecheck(string[11][1], int&);

/* Other Functions */ 
void cleanup();
void empty	(); // Soon to be added
void menu	();
void menu2	(string[11][1], string[11][5], float[11][4], int&, int);

int main(){
	string	uINPUTS[11][1], 
			tINPUTS[11][5];

	float	nINPUTS[11][4];
	int		memberCount = 0;
	int		choice = 0;
	int		select = 0;

	loadup(uINPUTS, tINPUTS, nINPUTS, memberCount);

	while (choice != 4){

		menu();
		cin >> choice;
		while (choice < 0 || choice > 4) {
			cout << "Your input is invalid, please try again" << endl;
			cin >> choice;
		}

		switch (choice){
			case 1:
			if (memberCount < 10) {
					newMember		(uINPUTS, tINPUTS, nINPUTS, memberCount);
					newSave			(uINPUTS, tINPUTS, nINPUTS, memberCount);
					memberCount++;
					databaseUpdate	(uINPUTS, tINPUTS, nINPUTS, memberCount);
					break;
				}
				else {
					cleanup();
					cout << "The Storage is full, please remove someone if you want to add a new member" << endl;
				}
			break;
			case 2:
				cout << "This is membercount: " << memberCount << endl;
				if (memberCount != 0) {
					// memberSelect	(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
					//	calorielimit(input, x);
					break;
				}
				else if(memberCount == 0){
					cleanup();
					cout << "The database is empty" << endl;
				}
				break;
			case 3:
				if (memberCount != 0) {
					deleteMember	(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
					databaseUpdate	(uINPUTS, tINPUTS, nINPUTS, memberCount);
					break;
				}
				else if (memberCount == 0) {
					cleanup();
					cout << "The database is empty" << endl;
				}
				break;
			case 4:
				exit(0);
				break;
		}
	}
}

void menu2(string uINPUTS[11][1], string tINPUTS[11][5], float nINPUTS[11][4], int& memberCount, int select) {

	cout << "User: " << uINPUTS[select][1] << " Weight: " << nINPUTS[select][3] << " Current BMI: " << nINPUTS[select][4] << endl;
	/*
	while (choice != 4) {

		menu();
		cin >> choice;
		while (choice < 0 || choice > 4) {
			cout << "Your input is invalid, please try again" << endl;
			cin >> choice;
		}

		switch (choice) {
		case 1:
			if (memberCount < 10) {
				newMember(uINPUTS, tINPUTS, nINPUTS, memberCount);
				newSave(uINPUTS, tINPUTS, nINPUTS, memberCount);
				memberCount++;
				databaseUpdate(uINPUTS, tINPUTS, nINPUTS, memberCount);
				break;
			}
			else {
				cleanup();
				cout << "The Storage is full, please remove someone if you want to add a new member" << endl;
			}
			break;
		case 2:
			cout << "This is membercount: " << memberCount << endl;
			if (memberCount != 0) {
				memberSelect(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
				//	calorielimit(input, x);
				break;
			}
			else if (memberCount == 0) {
				cleanup();
				cout << "The database is empty" << endl;
			}
			break;
		case 3:
			if (memberCount != 0) {
				deleteMember(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
				databaseUpdate(uINPUTS, tINPUTS, nINPUTS, memberCount);
				break;
			}
			else if (memberCount == 0) {
				cleanup();
				cout << "The database is empty" << endl;
			}
			break;
		case 4:
			exit(0);
			break;
		}
	}
	*/
}



void newMember(string uINPUTS[11][1], string tINPUTS[11][5], float nINPUTS[11][4], int& memberCount) { // Rename function to New User 
	float bmi;
	string newUser;
	ofstream newFile;
	cout << "Enter your name please" << endl;
	cin.ignore();
	getline(cin, uINPUTS[memberCount][1]);

	namecheck(uINPUTS, memberCount);

	
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


	// printUser(uINPUTS, tINPUTS, nINPUTS, memberCount);
}

void newSave(string uINPUTS[11][1], string tINPUTS[11][5], float nINPUTS[11][4], int& memberCount) {
	string newUser;
	ofstream newFile;

	newUser = uINPUTS[memberCount][1];
	newUser = newUser + ".txt";

	newFile.open(newUser);

	newFile << uINPUTS[memberCount][1] << endl;
	newFile << tINPUTS[memberCount][1] << endl;
	newFile << nINPUTS[memberCount][1] << endl;
	newFile << nINPUTS[memberCount][2] << endl;
	newFile << nINPUTS[memberCount][3] << endl;
	newFile << nINPUTS[memberCount][4] << endl;

	newFile.close();
}

void databaseUpdate(string uINPUTS[11][1], string tINPUTS[11][5], float nINPUTS[11][4], int& memberCount) {
	ofstream database;
	string name;

	database.open("Membership.txt");
	for (int i = 0; i <= memberCount; i++) {
		database << uINPUTS[i][1] << endl;
	}

	for (int i = 0; i <= memberCount; i++) {
		if (uINPUTS[i][1] == "" && i != memberCount && i + 1 < memberCount) {
			name = uINPUTS[i][1];
			if (i + 1 < memberCount) {
				uINPUTS[i][1] = uINPUTS[i + 1][1];
				uINPUTS[i + 1][1] = name;
			}
		}
	}
}

void printUser(string uINPUTS[11][1], string tINPUTS[11][5], float nINPUTS[11][4], int& memberCount) {
	system("CLS");
	cout << "Welcome to the program, here's your record so far" << endl;
	cout << "Name; "	<< uINPUTS[memberCount][1] << endl;
	cout << "Height; "	<< nINPUTS[memberCount][1] << endl;
	cout << "Weight; "	<< nINPUTS[memberCount][3] << endl;
	cout << "Age; "		<< nINPUTS[memberCount][2] << endl;
	cout << "BMI; "		<< nINPUTS[memberCount][4] << endl;
	cout << "------------------------------------------" << endl;
}

void loadup(string uINPUTS[11][1], string tINPUTS[11][5], float nINPUTS[11][4], int& memberCount) {
	string dbList, nameHolder;
	ifstream database;
	database.open("Membership.txt");
	if (!database) {
		cout << "First time boot" << endl;
	}
	else {
		//system("Membership.txt");
		while (getline(database, dbList)) {
			uINPUTS[memberCount][1] = dbList;
			memberCount++;
			if (dbList == "") {
				memberCount--;
			}
		}
	}
}

void memberPrint(string uINPUTS[11][1], string tINPUTS[11][5], float nINPUTS[11][4], int& memberCount) {
	system("CLS");
	for (int i = 0; i < memberCount; i++) {
		cout << i+1 << ". " << uINPUTS[i][1] << endl;
	}
	cout << "---------------------" << endl;
}

void memberSelect(string uINPUTS[11][1], string tINPUTS[11][5], float nINPUTS[11][4], int& memberCount, int select){
	
	memberPrint(uINPUTS, tINPUTS, nINPUTS, memberCount);
	cout << "Please select a member" << endl;
	cout << "---------------------" << endl;
	cin >> select;

	cleanup();
	menu2(uINPUTS, tINPUTS, nINPUTS, memberCount, select);

}

void deleteMember(string uINPUTS[11][1], string tINPUTS[11][5], float nINPUTS[11][4], int& memberCount, int select) {
	string file, name;

	system("CLS");
	memberPrint(uINPUTS, tINPUTS, nINPUTS, memberCount);

	cout << "Select a member to remove" << endl;
	cin >> select;

	cout << "User: " << uINPUTS[select-1][1] << " has been deleted" << endl;

	file = uINPUTS[select - 1][1] + ".txt";
	remove(file.c_str());

	uINPUTS[select-1][1] = "";

	for (int i = 0; i <= memberCount; i++) {
		if (uINPUTS[i][1] == "" && i != memberCount && i + 1 < memberCount) {
			name = uINPUTS[i][1];
			if (i + 1 < memberCount) {
				uINPUTS[i][1] = uINPUTS[i + 1][1];
				uINPUTS[i + 1][1] = name;
			}
		}
	}
	memberCount--;
}

/* Functions */

void namecheck(string uINPUTS[11][1], int& memberCount) {
	bool exist = true;

	for (int i = 1; i <= memberCount; i++)
		if(i != memberCount)
				while (uINPUTS[memberCount][1] == uINPUTS[i][1] && exist == true) {
					cout << "This person already exist in the system. Please eneter another name" << endl;
					getline(cin, uINPUTS[memberCount][1]);
					for (int check2 = 1; check2 <= memberCount; check2++)
						if (check2 != memberCount)
							if (uINPUTS[memberCount][1] == uINPUTS[check2][1]) {
								exist = true;
								i = 1;
							}
							else
								exist = false;
				}
}

void menu() {
	cout << "Exercise program" << endl;
	cout << "---------------------" << endl;

	cout << "1. New User"		<< endl;
	cout << "2. Select User"	<< endl;
	cout << "3. Delete User"	<< endl;
	cout << "4. Exit Program"	<< endl;
}

void cleanup() {
	system("CLS");
	cout << "---------------------" << endl;
}

/*
void calorielimit(string tINPUTS[11][6], int nINPUTS[11][5], int x) {
	//if(input[11][6] < 80)
}
*/