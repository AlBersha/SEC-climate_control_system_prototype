#pragma once 
#include <string>
using namespace std;

enum Flavors {
	None,
	Rose,
	Arctic,
	Forest
};

class ClimateMode
{
public:
	ClimateMode(string,double,double,string);
	ClimateMode();
	~ClimateMode();

	void SetName(string newName);
	void SetTemperature(double newTemperature);
	void SetHumidity(double newHumidity);
	//void SetFlavor(Flavors newFlavor);
	void SetFlavor(string newFlavor);
	double GetTemperature();
	double GetHumidity();
	//Flavors GetFlavor();
	string GetFlavor();
	string GetName();

private:
	string name = "";
	double temperature = 0;
	double humidity = 0;
	//Flavors flavor = None;
	string flavor;
};

