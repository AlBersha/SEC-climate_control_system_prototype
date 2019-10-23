#pragma once
#include "SimpleAccountsHolder.h"

class Authorizer
{
public:
	Authorizer();
	AccountType TryAuthorize(std::string login, std::string password);
	void CreateAccount(std::string login, std::string password, AccountType acountType);
	~Authorizer();
private:
	SimpleAccountsHolder accountsHolder;
};


