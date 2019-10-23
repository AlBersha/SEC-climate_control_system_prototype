#include "ClimateMode.h"
using namespace std;

void ClimateMode::SetTemperature(double newTemperature)
{
	temperature = newTemperature;
}

void ClimateMode::SetHumidity(double newHumidity)
{
	humidity = newHumidity;
}

void ClimateMode::SetFlavor(string newFlavor)
{
	flavor = newFlavor;
}

double ClimateMode::GetTemperature()
{
	return temperature;
}

double ClimateMode::GetHumidity()
{
	return humidity;
}

string ClimateMode::GetFlavor()
{
	return flavor;
}

string ClimateMode::GetName()
{
	return name;
}







