#pragma once
#include <string>
#include <vector>

enum AccountType {
	Unrecognized,
	Worker,
	Director
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

