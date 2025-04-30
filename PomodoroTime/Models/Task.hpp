#ifndef Task_HPP
#define Task_HPP
#include <string>
#pragma once

class Task {
private: 
	int idTask;
	std::string nameTask, Description;

public:
	Task();
	Task(int idTask, std::string nameTask, std::string description);

	int getIdTask();

	void setIdTask(int idTask);

	std::string getName();

	void setName(std::string nameTask);

	std::string getDescription();

	void setDescription(std::string description);

};

#endif // Task_HPP
