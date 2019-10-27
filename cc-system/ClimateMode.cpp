#include "ClimateMode.h"

ClimateMode::ClimateMode(string modeName, double temp, double hum, string flav) {
	this->name = modeName;
	this->temperature = temp;
	this->humidity = hum;
	this->flavor = flav;
}

ClimateMode::ClimateMode() {

}

ClimateMode::~ClimateMode() {

}

void ClimateMode::SetName(string newName)
{
	name = newName;
}

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

