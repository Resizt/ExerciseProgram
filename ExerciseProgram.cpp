#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <Windows.h>
#include <sstream>

using namespace std;

/* Menu */
void menu();
void memberMenu(string[11][1], string[11][5], float[11][4], int&, int&);

void newMember(string[11][1], string[11][5], float[11][4], int&);
void newSave(string[11][1], string[11][5], float[11][4], int&);
void printUser(string[11][1], string[11][5], float[11][4], int&);
void systemLoadup(string[11][1], string[11][5], float[11][4], int&);
void databaseUpdate(string[11][1], string[11][5], float[11][4], int&);
void memberPrint(string[11][1], string[11][5], float[11][4], int&);
void memberSelect(string[11][1], string[11][5], float[11][4], int&, int&);
void deleteMember(string[11][1], string[11][5], float[11][4], int&, int&);
void memberLoadup(string[11][1], string[11][5], float[11][4], int&, int&);
void memberEdit(string[11][1], string[11][5], float[11][4], int&, int&);
void UIMember(string[11][1], string[11][5], float[11][4], int&, int&);
void nameupdate(string[11][1], string[11][5], float[11][4], int&, int&);
void fileupdate(string[11][1], string[11][5], float[11][4], int&, int&);
void bmicalculate(string[11][1], string[11][5], float[11][4], int&, int&);
void memberSex(string[11][1], string[11][5], float[11][4], int&, int&);

/*Diet Section*/
void memberEdit(string[11][1], string[11][5], float[11][4], int&, int&);
void diet	    (string[11][1], string[11][5], float[11][4], int&, int&);

// void exerciseRec	(string[11][1], string[11][5], float[11][4], int&);

/* Validation Fucntions */
void namecheck(string[11][1], int&);

/* Other Functions */
void cleanup();
void empty(); // Soon to be added

void bmi(float);
void usermenu();
void editmenu();

/* Diet */
void rNutrition(string[11][1], string[11][5], float[11][4], int&, int&);   // Rich Nutrion
void tCalories(string[11][1], string[11][5], float[11][4], int&, int&);    // T
void lCalories(string[11][1], string[11][5], float[11][4], int&, int&);    // Low Calories
void lCarb(string[11][1], string[11][5], float[11][4], int&, int&);
void Vegan(string[11][1], string[11][5], float[11][4], int&, int&);
void fruitnveg(string[11][1], string[11][5], float[11][4], int&, int&);
void lFat(string[11][1], string[11][5], float[11][4], int&, int&);
void lSalt(string[11][1], string[11][5], float[11][4], int&, int&);
void iFasting(string[11][1], string[11][5], float[11][4], int&, int&);
void fruitnveg(string[11][1], string[11][5], float[11][4], int&, int&);
void cProtein(string[11][1], string[11][5], float[11][4], int&, int&);
void glutenFree (string[11][1], string[11][5], float[11][4], int&, int&);

int main() {
    string uINPUTS[11][1], tINPUTS[11][5];
    float nINPUTS[11][4];
    int memberCount = 0, choice = 0, select = 0;

    systemLoadup(uINPUTS, tINPUTS, nINPUTS, memberCount);

    while (choice != 4) {
        menu();
        cin >> choice;
        while (choice <= 0 || choice > 4) {
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
                cout << "The Storage is full, please remove someone if you want to "
                    "add a new member"
                    << endl;
            }
            break;
        case 2:
            if (memberCount != 0) {
                memberSelect(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
                // calorielimit(input, x);
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
}

void memberMenu(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    int choice = 0;

    memberLoadup(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
    UIMember(uINPUTS, tINPUTS, nINPUTS, memberCount, select);

    while (choice != 4) {
        usermenu();
        cin >> choice;
        while (choice < 0 || choice > 4) {
            cout << "Your input is invalid, please try again" << endl;
            cin >> choice;
        }
        switch (choice) {
        case 1:
            cleanup();
            diet(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 2:
            cout << "This is a test for the exercise plan" << endl;
            break;
        case 3:
            memberEdit(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 4:
            cleanup();
            memberSelect(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        }
    }
}

/* Database Functions */
void newSave(string uINPUTS[11][1], string tINPUTS[11][5], float nINPUTS[11][4],
    int& memberCount) {
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

void databaseUpdate(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount) {
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

void fileupdate(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    string file;
    ofstream openFile;

    file = uINPUTS[select][1] + ".txt";

    openFile.open(file);
    openFile << uINPUTS[select][1] << endl;
    openFile << tINPUTS[select][1] << endl;
    openFile << nINPUTS[select][1] << endl;
    openFile << nINPUTS[select][2] << endl;
    openFile << nINPUTS[select][3] << endl;
    openFile << nINPUTS[select][4] << endl;

    openFile.close();
}

void nameupdate(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    string newName, oldName, first, last, name;
    ofstream newFile;
    int result;

    oldName = uINPUTS[select][1];

    cout << "Correct your name" << endl;
    cout << "First name: ";
    cin >> first;
    cout << "Last Name: ";
    cin >> last;

    newName = first + " " + last;
    namecheck(uINPUTS, memberCount);
    uINPUTS[select][1] = newName;

    newName = newName + ".txt";
    oldName = oldName + ".txt";

    result = rename(oldName.c_str(), newName.c_str());
}

void namecheck(string uINPUTS[11][1], int& memberCount) {
    bool exist = true;

    for (int i = 1; i <= memberCount; i++)
        if (i != memberCount)
            while (uINPUTS[memberCount][1] == uINPUTS[i][1] && exist == true) {
                cout << "This person already exist in the system. Please eneter "
                    "another name"
                    << endl;
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

void systemLoadup(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount) {
    string dbList, nameHolder;
    ifstream database, number;
    int i = 0;
    float numbers = 0;

    nameHolder = uINPUTS[memberCount][1] + ".txt";
    database.open("Membership.txt");
    if (!database) {
        cout << "First time boot" << endl;
    }
    else {
        while (getline(database, dbList)) {
            uINPUTS[memberCount][1] = dbList;
            memberCount++;
            if (dbList == "") {
                memberCount--;
            }
        }

        while (number >> numbers) {
            if (i == 1) {
            }
            // tINPUTS[memberCount][1] = dbList;
            else if (i == 2)
                nINPUTS[memberCount][1] = numbers;
            else if (i == 3)
                nINPUTS[memberCount][1] = numbers;
            else if (i == 4)
                nINPUTS[memberCount][1] = numbers;
            else if (i == 5)
                nINPUTS[memberCount][1] = numbers;
            i++;
        }
    }
}

/* Calculation Functions */
void bmi(float weight) {
    if (weight <= 18.5) {
        cout << "Status: Underweight" << endl;
    }
    else if (weight >= 18.5 && weight < 25) {
        cout << "Status: Healthy" << endl;
    }
    else if (weight >= 25 && weight < 30) {
        cout << "Status: Overweight" << endl;
    }
    else if (weight >= 30) {
        cout << "Status: Obese" << endl;
    }
}

void bmicalculate(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    nINPUTS[select][4] =
        (703 * (nINPUTS[select][3] / (nINPUTS[select][1] * nINPUTS[select][1])));
}

/* Member Functions */
void newMember(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount) {
    // Rename function to New User
    string newUser;
    ofstream newFile;
    int sex;
    cout << "Enter your name please" << endl;
    cin.ignore();
    getline(cin, uINPUTS[memberCount][1]);

    namecheck(uINPUTS, memberCount);

    cout << "Choose your Sex" << endl;
    cout << "1. Male \n2. Female \n3. Other" << endl;
    cin >> sex;
    if (sex == 1)
        tINPUTS[memberCount][1] = "Male";
    else if (sex == 2)
        tINPUTS[memberCount][1] = "Female";
    else if (sex == 3) {
        cout << "Please enter what you want to be identified as: ";
        cin >> tINPUTS[memberCount][1];
    }

    cout << "Enter your Height in inches (So 5'5 would be 65)" << endl;
    cin >> nINPUTS[memberCount][1];

    cout << "Enter your Age" << endl;
    cin >> nINPUTS[memberCount][2];

    cout << "Enter your Weight (Just the numbers in lbs)" << endl;
    cin >> nINPUTS[memberCount][3];

    nINPUTS[memberCount][4] =
        (703 * (nINPUTS[memberCount][3] /
            (nINPUTS[memberCount][1] * nINPUTS[memberCount][1])));
}

void memberLoadup(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    string mbInfo;
    ifstream fileLoadup;
    int info = 0;
    fileLoadup.open(uINPUTS[select][1] + ".txt");
    if (!fileLoadup) {
        cout << "There's an error, this shouldn't ocurr unless you moved the file "
            "from the respected folder"
            << endl;
    }
    else {
        while (getline(fileLoadup, mbInfo)) {
            if (info == 0) {
                // User Load in
                uINPUTS[select][1] = mbInfo;
            }
            else if (info == 1) {
                // Sex Load in
                tINPUTS[select][1] = mbInfo;
            }
            else
                nINPUTS[select][info - 1] = stof(mbInfo);
            info++;
        }
    }
}

void memberPrint(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount) {
    system("CLS");
    for (int i = 0; i < memberCount; i++) {
        cout << i + 1 << ". " << uINPUTS[i][1] << endl;
    }
    cout << "---------------------" << endl;
}

void memberSelect(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    memberPrint(uINPUTS, tINPUTS, nINPUTS, memberCount);
    cout << "Please select a member or Type in 0 to go back" << endl;
    cout << "---------------------" << endl;
    cin >> select;
    if (select != 0) {
        while (select > memberCount) {
            cleanup();
            cout << "Your input is invalid, please try again" << endl;
            memberPrint(uINPUTS, tINPUTS, nINPUTS, memberCount);
            cin >> select;
        }
        select = select - 1;

        cleanup();
        memberMenu(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
    }
    else {
        cleanup();
        cout << "Returning to Main Menu" << endl;
    }
}

void deleteMember(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    string file, name;
    system("CLS");
    memberPrint(uINPUTS, tINPUTS, nINPUTS, memberCount);

    cout << "Select a member to remove or type in 0 to go back" << endl;
    cout << "---------------------" << endl;
    cin >> select;
    if (select != 0) {
        cout << "User: " << uINPUTS[select - 1][1] << " has been deleted" << endl;

        file = uINPUTS[select - 1][1] + ".txt";
        remove(file.c_str());

        uINPUTS[select - 1][1] = "";

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
    else {
        cleanup();
        cout << "Returning to menu" << endl;
    }
}

void memberEdit(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    string name, sex, first, last;
    cleanup();
    UIMember(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
    editmenu();
    int choice = 0;

    cin >> choice;
    while (choice < 0 || choice > 5) {
        cout << "Your input is invalid, please try again" << endl;
        cin >> choice;
    }
    switch (choice) {
    case 1:
        nameupdate(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
        cout << "The name is updated" << endl;
        break;
    case 2:
        cout << "Update Weight" << endl;
        cout << "Current Weight: ";
        cin >> nINPUTS[select][3];
        cout << "The weight is updated" << endl;
        cleanup();
        break;
    case 3:
        cout << "Update Sex" << endl;
        memberSex(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
        break;
    case 4:
        cout << "Update your age" << endl;
        cout << "Current Age: ";
        cin >> nINPUTS[select][2];
        cleanup();
        break;
    case 5:
        cleanup();
        memberMenu(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
        break;
    }
    fileupdate(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
    databaseUpdate(uINPUTS, tINPUTS, nINPUTS, memberCount);
    cleanup();
    memberMenu(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
}

void memberSex(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    int sex;
    cout << "Choose your Sex" << endl;
    cout << "1. Male \n2. Female \n3. Other" << endl;
    cin >> sex;
    if (sex == 1)
        tINPUTS[select][1] = "Male";
    else if (sex == 2)
        tINPUTS[select][1] = "Female";
    else if (sex == 3) {
        cout << "Please enter what you want to be identified as: ";
        cin >> tINPUTS[select][1];
    }
}

/* Other */
void printUser(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount) {
    system("CLS");
    cout << "Welcome to the program, here's your record so far" << endl;
    cout << "Name; " << uINPUTS[memberCount][1] << endl;
    cout << "Height; " << nINPUTS[memberCount][1] << endl;
    cout << "Weight; " << nINPUTS[memberCount][3] << endl;
    cout << "Age; " << nINPUTS[memberCount][2] << endl;
    cout << "BMI; " << nINPUTS[memberCount][4] << endl;
    cout << "------------------------------------------" << endl;
}

void UIMember(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    bmicalculate(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
    cout << "User: " << uINPUTS[select][1] << endl;
    cout << "---------------------" << endl;
    cout << "Age: " << nINPUTS[select][2] << " | "
        << "Weight: " << nINPUTS[select][3] << " | "
        << "Current BMI: " << nINPUTS[select][4] << endl;
    bmi(nINPUTS[select][4]);
    cout << "---------------------" << endl;
}

void diet(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    int diet;
    UIMember(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
    if (nINPUTS[select][4] <= 18.5) {
        cout << "1. Restoring Nutrition\n2. 3000 Calories Diet\n3. Large Calorie intake" << endl;
        }
        else if (nINPUTS[select][4] >= 18.5 && nINPUTS[select][4] < 25) {
            cout << "1. Low Carb, whole food\n2. Vegan \n3. Gluten-free" << endl;
        }
        else if (nINPUTS[select][4] >= 25 && nINPUTS[select][4] < 30) {
            cout << "1. Fruit and Vegetable\n2. Low Fat Intake \n3. Lower-salt" << endl;
        }
        else if (nINPUTS[select][4] >= 30) {
            cout << "1. Concentrated Protein \n2. Fruit and Vegetable \n3. Intermittent fasting" << endl;
        }

    cout << "---------------------\n Pick a diet that you feel will suit you\n Diet #:";
    cin >> diet;

    if (nINPUTS[select][4] <= 18.5) {
        switch (diet) {
        case 1:
         //   rNutrition(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 2:
          //  tCalories(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 3:
         //   lCalories(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        }
    }
    else if (nINPUTS[select][4] >= 18.5 && nINPUTS[select][4] < 25) {
        switch (diet) {
        case 1:
          //  lCarb(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 2:
          //  Vegan(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 3:
           // glutenFree(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        }
    }
    else if (nINPUTS[select][4] >= 25 && nINPUTS[select][4] < 30) {
        switch (diet) {
        case 1:
            fruitnveg(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 2:
        //    lFat(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 3:
         //   lSalt(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        }
    }

    else if (nINPUTS[select][4] >= 30) {
        switch (diet) {
        case 1:
         //   cProtein(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 2:
            fruitnveg(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 3:
         //   iFasting(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        }
    }
    }

void exercise(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    int exercise;
    UIMember(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
    if (nINPUTS[select][4] <= 18.5) {
        cout << "1. Restoring Nutrition\n2. 3000 Calories Diet\n3. Large Calorie intake" << endl;
    }
    else if (nINPUTS[select][4] >= 18.5 && nINPUTS[select][4] < 25) {
        cout << "1. Low Carb, whole food\n2. Vegan \n3. Gluten-free" << endl;
    }
    else if (nINPUTS[select][4] >= 25 && nINPUTS[select][4] < 30) {
        cout << "1. Fruit and Vegetable\n2. Low Fat Intake \n3. Lower-salt" << endl;
    }
    else if (nINPUTS[select][4] >= 30) {
        cout << "1. Concentrated Protein \n2. Fruit and Vegetable \n3. Intermittent fasting" << endl;
    }

    cout << "---------------------\n Pick a diet that you feel will suit you\n Diet #:";
    cin >> exercise;

    if (nINPUTS[select][4] <= 18.5) {
        switch (exercise) {
        case 1:
            //   rNutrition(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 2:
            //  tCalories(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 3:
            //   lCalories(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        }
    }
    else if (nINPUTS[select][4] >= 18.5 && nINPUTS[select][4] < 25) {
        switch (exercise) {
        case 1:
            //  lCarb(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 2:
            //  Vegan(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 3:
            // glutenFree(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        }
    }
    else if (nINPUTS[select][4] >= 25 && nINPUTS[select][4] < 30) {
        switch (exercise) {
        case 1:
            fruitnveg(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 2:
            lFat(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 3:
            lSalt(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        }
    }

    else if (nINPUTS[select][4] >= 30) {
        switch (exercise) {
        case 1:
            cProtein(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 2:
            fruitnveg(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        case 3:
             iFasting(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
            break;
        }
    }
}

/* Diet options */

void fruitnveg(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    int cls = 0;
    cleanup();
    UIMember(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
    cout << "Here is your selected diet" << endl;
    cout << "---------------------" << endl;
    cout << "Morning\n1. Apples\n2. Few Berries\n3. One glass of water \nLunch\n1. Mellon(s)\n2. Two glasses of water\nDinner\n1. Watermelon\n2. Berries\n3. One glass of water" << endl;
    cout << "---------------------" << endl;
    cout << "Please press 1 to continue..." << endl;

    while (cls != 1) {
        cin >> cls;
        if (cls != 1) {
            cout << "Wrong entry, please try again" << endl;
        }
        else {
            cleanup();
        }
    }
}

void iFasting(string uINPUTS[11][1], string tINPUTS[11][5],
    float nINPUTS[11][4], int& memberCount, int& select) {
    int cls = 0;
    cleanup();
    UIMember(uINPUTS, tINPUTS, nINPUTS, memberCount, select);
    cout << "Here is your selected diet" << endl;
    cout << "---------------------" << endl;
    cout << "Morning\nYou're fasting all of the morning \n---------------------\n \nLunch (12 PM)\n1. Full meal fruit enrichen\n2. Two glasses of water\nDinner (8PM)\n1. Watermelon\n2. Berries\n3. One glass of water" << endl;
    cout << "---------------------" << endl;
    cout << "Please press 1 to continue..." << endl;

    while (cls != 1) {
        cin >> cls;
        if (cls != 1) {
            cout << "Wrong entry, please try again" << endl;
        }
        else {
            cleanup();
        }
    }
}

/* Menus */

void menu() {
    cout << "Exercise program" << endl;
    cout << "---------------------" << endl;

    cout << "1. New User" << endl;
    cout << "2. Select User" << endl;
    cout << "3. Delete User" << endl;
    cout << "4. Exit Program" << endl;
}

void usermenu() {
    cout << "1. Diet Choice" << endl;
    cout << "2. Exercise Plan" << endl;
    cout << "3. Update Info" << endl;
    cout << "4. Log Out" << endl;
}

void editmenu() {
    cout << "1. Change Name" << endl;
    cout << "2. Change Weight" << endl;
    cout << "3. Change Sex" << endl;
    cout << "4. Change Age" << endl;
    cout << "5. Go Back" << endl;
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