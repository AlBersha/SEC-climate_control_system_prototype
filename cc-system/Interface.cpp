#include "Interface.h"
#include <iostream>
using namespace std;

int Interface::DisplayMenu() {
	return 0;
}

bool Interface::Validation(int menuItem) {
	return 0;
}

int WorkerInterface::DisplayMenu() {
	cout << " *** MENU ***" << endl;
	cout << " 1) See Current Settings " << endl;
	cout << " 2) Change Settings " << endl;
	cout << " 3) Choose Climate Mode " << endl;
	cout << " 4) Exit " << endl;
	cout << " Select a menu item: ";

	int menuItem;
	cin >> menuItem;

	if (Validation(menuItem)) {
		return menuItem;
	}
	else {
		DisplayMenu();
	}
}

bool WorkerInterface::Validation(int menuItem) {
	if (menuItem > 4 || menuItem < 0) {
		system("cls");
		cout << " Uncorrect menu item, try again" << endl;
		return false;
	}
	else {
		return true;
	}
}

int DirectorInterface::DisplayMenu() {
	cout << " *** MENU ***" << endl;
	cout << " 1) See Current Settings " << endl;
	cout << " 2) Change Settings " << endl;
	cout << " 3) Choose Climate Mode " << endl;
	cout << " 4) Exit " << endl;
	cout << " 5) See Timing " << endl;
	cout << " 6) Create New Timing " << endl;
	cout << " 7) Create Climate Mode " << endl;
	cout << " Select a menu item: "; 

	int menuItem;
	cin >> menuItem;

	if (Validation(menuItem)) {
		return menuItem;
	}
	else {
		DisplayMenu();
	}

}

bool DirectorInterface::Validation(int menuItem) {
	if (menuItem > 8|| menuItem < 0) {
		system("cls");
		cout << " Uncorrect menu item, try again" << endl;
		return false;
	}
	else {
		return true;
	}
}