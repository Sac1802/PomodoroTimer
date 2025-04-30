#ifndef ControllerTask_HPP
#define ControllerTask_HPP

#pragma once

#include <iostream>
#include <string>
#include "../Models/Task.hpp"
#include "../ClearTerminal/ClearTermnal.hpp"
#include <vector>
class ControllerTask {
private:
	std::vector<Task> listTask;

public:
	void addTask();
	void viewListTask();
	void completeTask();
	void selectTask();
};


#endif // !ControllerTask_HPP
