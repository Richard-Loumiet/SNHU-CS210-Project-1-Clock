#include <iostream>
#include <stdlib.h>
using namespace std;

int hr = 12;					//12 clock hours.
int minute = 0;					//Minutes used for both clocks.
int sec = 0;					//Seconds used for both clocks.
int hr24 = 0;					//To track 24 hour format.
int menuInput;					//Variable for menu.
bool exitChecker = true;		//if 4 is chosen in menu this becomes false and exits the program
int i = 0;						//i is used to track am/pm.

void printTime() {				//Prints time.
	cout << "***************************  ***************************" << endl;
	cout << "*       12-Hour Clock     *  *        24-Hour Clock    *" << endl;
	cout << "*       "; if (hr < 10) cout << "0"; cout << hr << ":"; if (minute < 10) cout << "0"; cout << minute << ":"; if (sec < 10) cout << "0"; cout << sec << " "; if (i == 0)cout << "AM"; else if (i == 1)cout << "PM"; cout << "       *  *        "; if (hr24 < 10) cout << "0"; cout << hr24 << ":"; if (minute < 10) cout << "0"; cout << minute << ":"; if (sec < 10) cout << "0"; cout << sec << "         *" << endl;
	cout << "***************************  ***************************" << endl;
}

void displayMenu() {			//Display menu.

	cout << "***************************\n";
	cout << "* 1 - Add One Hour        *\n";
	cout << "* 2 - Add One Minute      *\n";
	cout << "* 3 - Add One Second      *\n";
	cout << "* 4 - Exit Program        *\n";
	cout << "***************************\n";
}

void menuAction() {				//Used to track user inputs
	switch (menuInput) {
	case 1:						//Case #1
		hr24++;
		hr++;
		if (hr24 == 24) {
			hr24 = 0;
		}
		if (hr24 < 12) {
			i = 0;
		}
		if (hr == 13) {
			hr = 1;
		}
		if (hr24 >= 12) {
			i = 1;
		}
		break;
	case 2:						//Case #2
		minute++;
		if (minute == 60) {
			hr++;
			hr24++;
			minute = 0;
			if (hr24 < 12) {
				i = 0;
			}
			if (hr24 >= 12) {
				i = 1;
			}
			if (hr == 13) {
				hr = 1;
			}
			if (hr24 == 24) {
				hr24 = 0;
			}
		}
		break;
	case 3:						//Case #3
		sec++;
		if (sec == 60) {
			minute++;
			sec = 0;
			if (minute == 60) {
				hr++;
				hr24++;
				minute = 0;
				if (hr24 < 12) {
					i = 0;
				}
				if (hr == 13) {
					hr = 1;
				}
				if (hr24 >= 12) {
					i = 1;
				}
				if (hr24 == 24) {
					hr24 = 0;
				}
			}
		}
		break;
	case 4:						//Case #4
		cout << "Exiting Clock Program" << endl;
		exitChecker = false;
		break;
	default:
		cout << "Unexpected Input Received. Please Enter A Valid Menu Item." << endl;
	}

}

int main() {					//Main used for taking inputs and displaying information. 

	while (exitChecker) {
		printTime();
		displayMenu();
		cin >> menuInput;
		menuAction();
	}
	return 0;
}
