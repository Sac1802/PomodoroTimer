#include "ControllerTask.hpp"

ClearTerminal clearT;

void ControllerTask::addTask() {
	Task task;
	std::string nameTask;
	std::string description;

	std::cout << "Enter the task name: ";
	std::cin.ignore();
	std::getline(std::cin, nameTask);
	task.setName(nameTask);

	std::cout << "Enter the task description: ";
	std::getline(std::cin, description);
	task.setDescription(description);

	task.setIdTask(listTask.size() + 1);
	listTask.push_back(task);
	ControllerTask::viewListTask();
}


void ControllerTask::viewListTask() {
	for (auto task : listTask) {
		std::cout << "Task ID: " << task.getIdTask() << std::endl;
		std::cout << "Task Name: " << task.getName() << std::endl;
		std::cout << "Task Description: " << task.getDescription() << std::endl;
		std::cout << "|------------------------------|" << std::endl;
	}
}

void ControllerTask::completeTask() {
	int idSearch;
	std::cout << "Enter the ID of the task to complete: ";
	std::cin >> idSearch;
	for (auto tasks : listTask) {
		if (tasks.getIdTask() == idSearch) {
			listTask.erase(listTask.begin() + idSearch - 1);
			std::cout << "Task completed successfully!" << std::endl;
		}
		else {
			std::cout << "Task not found!" << std::endl;
		}
	}
}

void ControllerTask::selectTask() {
	int idSerch;
	ControllerTask::viewListTask();
	std::cout << "Enter the ID of the Task you want to start performing";
	std::cin >> idSerch;
	for (auto tasks : listTask) {
		if (tasks.getIdTask() == idSerch) {
			clearT.clear();
			std::cout << "Id: " << tasks.getIdTask() << std::endl;
			std::cout << "You have selected the task: " << tasks.getName() << std::endl;
			std::cout << "Description: " << tasks.getDescription() << std::endl;
		}
		else {
			std::cout << "Task not found!" << std::endl;
		}
	}
}

