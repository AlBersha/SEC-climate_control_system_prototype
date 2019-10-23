#include "SimpleAccountsHolder.h"
#include <fstream>

SimpleAccountsHolder::SimpleAccountsHolder(std::string dataBasePath) {
	this->dataBasePath = dataBasePath;
	std::ifstream database(dataBasePath);
	std::string input;
	std::getline(database, input);

	while (input != "") {
		size_t pos = input.find(" ");
		std::string login = input.substr(0, pos);
		input = input.substr(pos + 1);
		pos = input.find(" ");
		std::string password = input.substr(0, pos);
		input = input.substr(pos + 1);
		AccountType accountType = (AccountType)(input[0] - '0');
		input = "";

		accounts.push_back(Account(login, password, accountType));

		std::getline(database, input);
	}

	if (accounts.size() == 0) {
		accounts.push_back(Account("chak", "franklin", Worker));
		accounts.push_back(Account("mukha", "ip", Director));
	}

	database.close();
}

void SimpleAccountsHolder::Save() {
	std::ofstream database(dataBasePath);
	for (int i = 0; i < accounts.size(); i++) {
		database << accounts[i].login << " " << accounts[i].password << " " << accounts[i].accountType << std::endl;
	}

	database.close();
}

SimpleAccountsHolder::~SimpleAccountsHolder() {
	Save();
}

AccountType SimpleAccountsHolder::CheckRecord(std::string login, std::string password) {
	for (unsigned int i = 0; i < accounts.size(); i++) {
		if (accounts[i].login == login && accounts[i].password == password) return accounts[i].accountType;
	}
	return Unrecognized;
}

bool SimpleAccountsHolder::CreateRecord(std::string login, std::string password, AccountType userType) {
	accounts.push_back(Account(login, password, userType));
	Save();
	return true;
}