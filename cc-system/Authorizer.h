#pragma once
#include "SimpleAccountsHolder.h"

class Authorizer
{
public:
	Authorizer();
	AccountType TryAuthorize();
	void CreateAccount(std::string login, std::string password, AccountType acountType);
	~Authorizer();
private:
	SimpleAccountsHolder accountsHolder;
};


