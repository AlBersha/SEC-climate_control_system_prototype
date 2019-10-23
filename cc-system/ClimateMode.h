#pragma once 
#include <string>
using namespace std;

class ClimateMode
{
public:
	ClimateMode(std::string name);
	~ClimateMode();

	void SetTemperature(double newTemperature);
	void SetHumidity(double newHumidity);
	//void SetFlavor(Flavors newFlavor);
	void SetFlavor(string newFlavor);
	double GetTemperature();
	double GetHumidity();
	//Flavors GetFlavor();
	string GetFlavor();
	std::string GetName();

private:
	string name;
	double temperature;
	double humidity;
	//Flavors flavor;
	string flavor;
};

//enum Flavors {
//	None,
//	Rose,
//	Arctic,
//	ConiferousForest
//};
