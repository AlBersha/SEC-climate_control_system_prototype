#include"Settings.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <fstream>
#include "ClimateMode.h"

using namespace std;

Settings::Settings() {
	ifstream SavedSettings("ClimateMode.txt");
	string input;
	getline(SavedSettings, input);

	while (input != "") {
		int pos = input.find(" ");
		string nameOfMode = input.substr(0, pos);
		input = input.substr(pos + 1);
		pos = input.find(" ");
		double temperature = stod(input.substr(0, pos));
		input = input.substr(pos + 1);
		pos = input.find(" ");
		double humidity = stod(input.substr(0, pos));
		string flav = input.substr(pos + 1);
		input = "";
	
		prefabClimateMode.push_back(ClimateMode(nameOfMode,temperature,humidity,flav));

		getline(SavedSettings, input);
	}

	SavedSettings.close();

	ifstream CurrentMode("CurrentClimateMode.txt");
	getline(CurrentMode, input);

	int pos = input.find(" ");
	string nameOfMode = input.substr(0, pos);
	input = input.substr(pos + 1);
	pos = input.find(" ");
	double temperature = stod(input.substr(0, pos));
	input = input.substr(pos + 1);
	pos = input.find(" ");
	double humidity = stod(input.substr(0, pos));
	string flav = input.substr(pos + 1);
	input = "";

	currentClimateMode = ClimateMode(nameOfMode, temperature, humidity, flav);
	

	CurrentMode.close();
}

void Settings::Save() {
	ofstream database("ClimateMode.txt");
	for (int i = 0; i < prefabClimateMode.size(); i++) {
		database << prefabClimateMode[i].GetName() << " " << prefabClimateMode[i].GetTemperature() << " " << prefabClimateMode[i].GetHumidity() << " " << prefabClimateMode[i].GetFlavor() << endl;
	}
	database.close();

	ofstream CurrentMode("CurrentClimateMode.txt");
	CurrentMode << currentClimateMode.GetName() << " " << currentClimateMode.GetTemperature() << " " << currentClimateMode.GetHumidity() << " " << currentClimateMode.GetFlavor() << endl;
	CurrentMode.close();
}

Settings::~Settings() {
	//Save();
}

bool CheckTemperature(int temp) {
	if (temp > 15 && temp < 35) {
		return true;
	}
	return false;
}

bool CheckHumidity(int hum)
{
	if (hum > 30 && hum < 65) {
		return true;
	}
	return false;
}

void Settings::ShowCurrentSettings(){
	cout << "For now the current settings are as follows:" << endl;
	if (currentClimateMode.GetName() != "") {
		cout << "Name of climat mode:  " << currentClimateMode.GetName() << endl;
	}
	cout << "Temperature: " << currentClimateMode.GetTemperature() << endl;
	cout << "Humidity: " << currentClimateMode.GetHumidity() << endl;
	cout << "Flavor: " << currentClimateMode.GetFlavor() << endl;
}

void Settings::ChangeCurrentSettings()
{
	int n = 1;
	int num;
	while (n == 1) {
		cout << "Choose parameter, you would like to change:\n";
		cout << "1. Temperature\n2. Humidity\n3. Flavor\n";
		cout << "Input num of parameter, you want to change: ";
		cin >> num;
		switch (num)
		{
		case(1): {
				int temp;
				cout << "Input temperature value: ";
				bool checker = true;
					while (checker) {
						cin >> temp;
						if (CheckTemperature(temp)) {
							currentClimateMode.SetTemperature(temp);
							checker = false;
							cout << "Temperature value set successfully.\n";
						}
						else {
							cout << "You have entered an inappropriate value.\nPlease try one more time\n";
						}
					}
				break;
			}

		case(2) :{
				int hum;
				cout << "Input humidity value: ";
				bool checker = true;
				while (checker) {
					cin >> hum;
					if (CheckHumidity(hum)) {
						currentClimateMode.SetHumidity(hum);
						checker = false;
						cout << "Humidity value set successfully.\n";
					}
					else {
						cout << "You have entered an inappropriate value.\nPlease try one more time\n";
					}
				}
				break;
			}

		case(3): {
				int num;
				//TODO
				//decide where to keep vector<string> Flavors 
				//and how to fill in it(from file or manually)
				//display list of Flavors
				cout << "Input num of flavor, you want to set: ";
				cin >> num;
				//currentClimateMode.SetFlavor(Flavors[num - 1]);
				break;
			}

			default: {
				cout << "You have entered wrong number.\nPlease try one more time or finish execution.";
				break; 
			}
		}
		cout << "To continue changing setting, input 1\n";
		cout << "Stop changing settings, input 0\n";
		cin >> n;
	}
}

void Settings::CreateClimateMode(){
	string name;
	double temp;
	double hum;
	string flav;

	cout << "Input the name of your climat mode: ";
	cin >> name;
	cout << "\nInput the value of temperature for climat mode colled " << name << " : ";
	cin >> temp;
	cout << "\nInput the value of humidity: ";
	cin >> hum;
	cout << "\nInput num of flavor: " << endl;
	//TODO
	//decide where to keep vector<string> Flavors and how to fill in it(from file or manually)
	//display list of Flavors
	cin >> flav;
	ClimateMode newClimateMode(name, temp, hum, flav);
	prefabClimateMode.push_back(newClimateMode);
	string answer;
	cout << endl << "\nDo you want to apply new climat mode now? [Y/N]: ";
	getline(cin,answer);
	if (answer == "Y" || answer == "y") {
		currentClimateMode = newClimateMode;
	}
}

void Settings::ApplyClimateMode(){
	int num;
	for (int i = 0; i < prefabClimateMode.size(); i++) {
		string climatName = prefabClimateMode[i].GetName();
		double temp = prefabClimateMode[i].GetTemperature();
		double hum = prefabClimateMode[i].GetHumidity();
		string flav = prefabClimateMode[i].GetFlavor();
		cout << i + 1 << ". " << climatName << " (Temperature: " << temp << ", Humidity: " << hum << ", Flavor: " << flav << ")" << endl;
	}
	cout << "Input num of climat mode, you want to apply: ";
	bool flag = true;
	while (flag) {
		cin >> num;
		if (num <= prefabClimateMode.size() && num > 0) {
			currentClimateMode = prefabClimateMode[num - 1];
			cout << " Climate mode successfully applied.\n";
			flag = false;
		}
		else {
			cout << endl << " You entered an incorrect value, try again!" << endl;
		}
	}
	
}




