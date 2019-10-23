#pragma once
#include <map>
#include <ctime>
#include "ClimateMode.h"

class Scheduler
{
public:
	Scheduler();
	~Scheduler();

	void DisplayTasks();
	void AddTask(std::string climateModeName, time_t time);
	void RemoveTask(std::string climateModename);
	void RemoveTask(time_t time);
private:
	void PerformTask(time_t time);
	std::map<std::string, time_t > tasks;
};