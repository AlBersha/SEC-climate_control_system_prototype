#pragma once
#include <string>
#include <vector>
#include <fstream>

enum AccountType
{
	worker,
	director,
	unknown
};

class Account {
public:
	std::string login;
	std::string password;
	AccountType accountType;
	Account(std::string login, std::string password, AccountType accountType) {
		this->login = login;
		this->password = password;
		this->accountType = accountType;
	}
};

class SimpleAccountsHolder {
public:
	SimpleAccountsHolder(std::string dataBasePath = "AccountsHolder/database.ah");
	~SimpleAccountsHolder();
	AccountType CheckRecord(std::string login, std::string password);
	bool CreateRecord(std::string login, std::string password, AccountType userType);
private:
	std::string dataBasePath;
	std::vector<Account> accounts;
	void Save();
};
