#include "ClimateControlSystem.h"
#include <iostream>
using namespace std;

ClimateControlSystem::ClimateControlSystem() {
	authorizer = new Authorizer();
	settings = new Settings();
	scheduler = new Scheduler();
}

ClimateControlSystem::~ClimateControlSystem()
{
	delete authorizer;
	delete settings;
}

void ClimateControlSystem::Authorize() {
	TypeOfAccount = authorizer->TryAuthorize();

	if (TypeOfAccount == 1) {
		currentUserInterface = new WorkerInterface();
	}
	else {
		currentUserInterface = new DirectorInterface();
	}
}

void ClimateControlSystem::ShowMenu() {
	int variantOfMenuItem;
	variantOfMenuItem = currentUserInterface->DisplayMenu();
	switch (variantOfMenuItem)
	{
		case 1: {
			system("cls");
			settings->ShowCurrentSettings();
			ShowMenu();
			break;
		}
		case 2: {
			system("cls");
			settings->ChangeCurrentSettings();
			ShowMenu();
			break;
		}
		case 3: {
			system("cls");
			settings->ApplyClimateMode();
			ShowMenu();
			break;
		}
		case 4: {
			system("cls");
			cout << " Exit";
			ShowMenu();
			break;
		}
		case 5: {
			system("cls");
			scheduler->DisplayTasks();
			ShowMenu();
			break;
		}
		case 6: {
			system("cls");
			scheduler->AddTask();
			ShowMenu();
			break;
		}
		case 7: {
			system("cls");
			scheduler->RemoveTask();
			ShowMenu();
			break;
		}
		case 8: {
			system("cls");
			settings->CreateClimateMode();
			ShowMenu();
			break;
		}
		default: {
			break;
		}
	}
}
