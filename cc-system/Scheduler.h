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
	void AddTask();
	void RemoveTask();
private:
	void PerformTask(time_t time);
	std::map<std::string, time_t > tasks;
};