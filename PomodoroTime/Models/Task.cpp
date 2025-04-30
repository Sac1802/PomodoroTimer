#include "Task.hpp"

Task::Task() {
}

Task::Task(int idTask, std::string nameTask, std::string description) {
	this->idTask = idTask;
	this->nameTask = nameTask;
	this->Description = description;
}

int Task::getIdTask() {
	return idTask;
}

void Task::setIdTask(int idTask) {
	this->idTask = idTask;
}

std::string Task::getName() {
	return nameTask;
}

void Task::setName(std::string nameTask) {
	this->nameTask = nameTask;
}

std::string Task::getDescription() {
	return Description;
}

void Task::setDescription(std::string description) {
	this->Description = description;
}