#include <iostream>
#include <sstream>
#include <fstream>	

using namespace std;

void newMember(string[10][5], int[10][4], int);

int main(){
	string	tINPUTS[10][5];
	int		nINPUTS[10][4];
	int		x = 1, choice = 0;
	cout << "Exercise program"	<< endl;
	cout << "-------------------------------------------" << endl;

	cout << "1. New User"		<< endl;
	cout << "2. Existing User"	<< endl;
	cout << "X. Exit Program"	<< endl;

	while (choice != 3){
		cin >> choice;
		switch (choice){
			case 1:
				newMember(tINPUTS, nINPUTS, x);
			//	newSave(tINPUTS, nINPUTS);
			case 2:
			//	loadup();
			//	calorielimit(input, x)
			case 3:
				exit(0);
		}
	}
}


void newMember(string tINPUTS[10][5], int nINPUTS[10][4], int x) { // Rename function to New User 
	int bmi;
	float bmi2;
	string newUser;
	ofstream newFile;

	cout << "Enter your name please" << endl;
	cin.ignore();
	getline(cin, tINPUTS[x][1]);


	cout << "Choose your Sex" << endl;
	getline(cin, tINPUTS[x][2]);

	cout << "Enter your Height in inches (So 5'5 would be 66)" << endl;
	cin >> nINPUTS[x][1];

	cout << "Enter your Age" << endl;
	cin >> nINPUTS[x][2];

	cout << "Enter your Weight (Just the numbers in lbs)" << endl;
	cin >> nINPUTS[x][3];

	bmi = nINPUTS[x][3] / (nINPUTS[x][1] * nINPUTS[x][1]);

	nINPUTS[x][4] = bmi;

	//	bmi2 = (703 * nINPUTS[x][3]) / (nINPUTS[x][1] * nINPUTS[x][1])
	//	nINPUTS[x][4] = bmi2;

	cout << "Your BMI is; " << bmi << endl;

	newUser = tINPUTS[x][1];
	newUser = newUser + ".txt";
	newFile.open(newUser);

	newFile << tINPUTS[x][1] << endl;
	newFile << tINPUTS[x][2] << endl;
	newFile << nINPUTS[x][1] << endl;
	newFile << nINPUTS[x][2] << endl;
	newFile << nINPUTS[x][3] << endl;
	newFile << nINPUTS[x][4] << endl;


	newFile.close();
}
/*
void calorielimit(string tINPUTS[10][6], int nINPUTS[10][5], int x) {
	//if(input[10][6] < 80)
}

void BMIAdjustment(string tINPUTS[10][6], int nINPUTS[10][5], int x) {

}
*/