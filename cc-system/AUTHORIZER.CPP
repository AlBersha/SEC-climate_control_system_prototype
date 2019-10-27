#include <iostream>
#include "Authorizer.h"
using namespace std;

Authorizer::Authorizer() {
}

Authorizer::~Authorizer()
{
}

AccountType Authorizer::TryAuthorize() {
	string login;
	string password;
	cout << " ***Enter your login ***" << endl << " Login: ";
	cin >> login;
	cout << " ***Enter your password ***" << endl << " Password:";
	cin >> password;
	AccountType TypeOfAccount = accountsHolder.CheckRecord(login, password);
	if (TypeOfAccount == 0) {
		system("cls");
		cout << " PLEASE TRY AGAIN, UNCORRECT LOGIN OR PASSWORD " << endl;
		return TypeOfAccount;
	}
	if(TypeOfAccount == 1){
		system("cls");
		cout << " You is authorized as a worker" << endl;
		return TypeOfAccount;
	}
	if(TypeOfAccount == 2){
		system("cls");
		cout << " You is authorized as a director" << endl;
		return TypeOfAccount;
	}
}

bool Authorizer::CreateAccount(string login, string password, AccountType type) {
	AccountType check = accountsHolder.CheckRecord(login, password);
	if (check == Unrecognized){
		return accountsHolder.CreateRecord(login, password,type);
	}
	else {
		return false;
	}
}