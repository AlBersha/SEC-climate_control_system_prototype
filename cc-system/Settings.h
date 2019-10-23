#pragma once
#include <vector>
#include "ClimateMode.h"

class Settings
{
public:
	Settings();
	~Settings();
	void ShowCurrentSettings();
	void ChangeCurrentSettings();
	void CreateClimateMode();
	void ApplyClimateMode();
private:
	ClimateMode currentClimateMode;
	std::vector<string> Flavors;
	std::vector<ClimateMode> prefabClimateMode;
};

bool CheckTemperature(int temp);
bool CheckHumidity(int hum);