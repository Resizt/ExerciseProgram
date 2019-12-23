#include <iostream>
#include <sstream>

using namespace std;

void startup(string[10][5], int[10][4], int);

int main(){

	string	tINPUTS[10][5];
	int		nINPUTS[10][4];
	int		x = 1, choice;
	cout << "Exercise program"	<< endl;
	cout << "-------------------------------------------" << endl;

	cout << "1. New User"		<< endl;
	cout << "2. Existing User"	<< endl;
	cout << "X. Exit Program"	<< endl;
	
	cin >> choice;

	while (choice != 3){
		switch (choice){
			case 1:
				startup(tINPUTS, nINPUTS, x);
				save(tINPUTS, nINPUTS);
			case 2:
			//	loadup();
			//	calorielimit(input, x)
			case 3:
				exit(0);
		}
	}
}

void startup(string tINPUTS[10][5], int nINPUTS[10][4], int x) { // Rename function to New User 
	int bmi;
	float bmi2;

	cout << "Enter your name please" << endl;
	cin.ignore();
	getline(cin, tINPUTS[x][1]);


	cout << "Choose your Sex" << endl;
	cin.ignore();
	getline(cin, tINPUTS[x][2]);

	cout << "Enter your Height in inches (So 5'5 would be 66)" << endl;
	cin.ignore();
	cin >> nINPUTS[x][1];

	cout << "Enter your Age" << endl;
	cin.ignore();
	cin >> nINPUTS[x][2];

	cout << "Enter your Weight (Just the numbers in lbs)" << endl;
	cin.ignore();
	cin >> nINPUTS[x][3];

	bmi = (703 * nINPUTS[x][3]) / (nINPUTS[x][1] * nINPUTS[x][1]);
	bmi2 = (703 * nINPUTS[x][3]) / (nINPUTS[x][1] * nINPUTS[x][1]);
	nINPUTS[x][4] = bmi;
//	nINPUTS[x][4] = bmi2;

	cout << "Your BMI is; " << bmi << endl << "This is floating BMI; " << bmi2;
}
/*
void calorielimit(string tINPUTS[10][6], int nINPUTS[10][5], int x) {
	//if(input[10][6] < 80)
}

void BMIAdjustment(string tINPUTS[10][6], int nINPUTS[10][5], int x) {

}
*/