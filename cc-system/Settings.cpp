#include"Settings.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "ClimateMode.h"
using namespace std;

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
		cout << "Name of climat mode is " << currentClimateMode.GetName() << endl;
	}
	cout << "temperature: " << currentClimateMode.GetTemperature() << endl;
	cout << "humidity: " << currentClimateMode.GetHumidity() << endl;
	cout << "flavor: " << currentClimateMode.GetFlavor() << endl;
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
				currentClimateMode.SetFlavor(Flavors[num - 1]);
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
/*
void Settings::CreateClimateMode()
{
	string name;
	double param;

	cout << "Input the name of your climat mode: ";
	getline(cin,name);
	ClimateMode newClimatMode(name);
	cout << "\nInput the value of temperature for climat mode colled " << name << " : ";
	cin >> param;
	newClimatMode.SetTemperature(param);
	cout << "\nInput the value of humidity: ";
	cin >> param;
	newClimatMode.SetHumidity(param);
	cout << "\nInput num of flavor: " << endl;
	//TODO
	//decide where to keep vector<string> Flavors and how to fill in it(from file or manually)
	//display list of Flavors
	cin >> param;
	newClimatMode.SetFlavor(Flovers[param - 1]);
	prefabClimatMode.push_back(newClimatMode);
	string answer;
	cout << endl << "\nDo you want to apply new climat mode now? [Y/N]: ";
	getline(answer);
	if (answer == "Y" || answer == "y") {
		currentClimatMode = newClimatMode;
	}
}

void Settings::ApplyClimateMode()
{
	int num;
	for (int i = 0; i < prefabClimateMode.size(); i++) {
		string climatName = prefabClimateMode[i].GetName();
		cout << i + 1 << ". " << name << endl;
	}
	cout << "Input num of climat mode, you want to apply: ";
	cin << num;
	currentClimatMode = prefabClimateMode[i];
	cout << endl << "Climate mode successfully applied.\n";
}

*/



