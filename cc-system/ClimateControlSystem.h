#pragma once
#include <string>
#include "Settings.h"
#include "Scheduler.h"
#include "Authorizer.h"
#include "Interface.h"

class ClimateControlSystem
{
public:
	ClimateControlSystem(); //should load all sub-modules and other 
	~ClimateControlSystem();
	bool Authorize(std::string login, std::string password); // assigns interface of account 
	bool CreateAccount(std::string login, std::string password, AccountType acountType);
	void ShowMenu(); // calls Interface's menu and reacts to user input by calling other methods in sub-modules 
	void StopSystem(); // calls saving processes 
	void ExitAccount(); // for changing account 
private:
	bool isUserAuthorized = false; // User acnt access system without authorizing 
	//Settings* settings;
	//Scheduler* scheduler;
	Authorizer* authorizer;
	//Interface* currentUserInterface = nullptr;
};


