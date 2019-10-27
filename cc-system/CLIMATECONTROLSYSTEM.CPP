#include "ClimateControlSystem.h"
#include <iostream>
using namespace std;

ClimateControlSystem::ClimateControlSystem() {
	authorizer = new Authorizer();
	TypeOfAccount = authorizer->TryAuthorize();
	if (TypeOfAccount == 0) {
		system("cls");
		cout << " !!!PLEASE TRY AGAIN, UNCORRECT LOGIN OR " << endl;
	}
	else if (TypeOfAccount == 1) {
		cout << "!!! You is authorized as a worker" << endl;
	}
	else {
		cout << "!!! You is authorized as a director" << endl;
	}
}

ClimateControlSystem::~ClimateControlSystem()
{
	delete authorizer;
}
