/*****************************************************************//**
 * \file   ControllerTask.cpp
 * \brief  Implementation of ControllerTask class functions.
 * This file provides the basic CRUD functionality (CREATE, READ, UPDATE, DELETE)
 * \author Acost
 * \date   May 2025
 *********************************************************************/
#include "ControllerTask.hpp"
 /**
  * @brief External instance for terminal clearning.
  */
ClearTerminal clearTer;

std::vector<Task> ControllerTask::listTask;

/**
 * @brief Adds a new task to the list.
 *
 * Requests user input to define the task name and description,
 * assigns an ID, and stores it in the task list.
 */
void ControllerTask::addTask() {
	Task task;
	std::string nameTask;
	std::string description;

	std::cout << "Enter the task name: ";
	std::getline(std::cin, nameTask);
	task.setName(nameTask);

	std::cout << "Enter the task description: ";
	std::getline(std::cin, description);
	task.setDescription(description);

	task.setIdTask(listTask.size() + 1);
	listTask.push_back(task);
	ControllerTask::viewListTask();
}

/**
 * @brief view listTasks.
 * 
 * Function to view all the data stored in the listTasks
 */

void ControllerTask::viewListTask() {
	for (auto task : listTask) {
		std::cout << "[           *PomodoroTimer*          ]" << std::endl;
		std::cout << "Task ID: " << task.getIdTask() << std::endl;
		std::cout << "Task Name: " << task.getName() << std::endl;
		std::cout << "Task Description: " << task.getDescription() << std::endl;
		std::cout << "--------------------------------------" << std::endl;
	}
}

/**
 * @brief Completes and removes a task.
 *
 * Searches for a task by ID and removes it from the task list.
 * Displays a success message or an error if the task is not found.
 *
 * @param idSearch Task ID to be removed.
 */

void ControllerTask::completeTask() {
	viewListTask();
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

/**
 * @brief select Task by ID.
 * 
 * Function to search for a Task by its ID
 */

void ControllerTask::selectTask() {
	int idSerach;
	viewListTask();
	std::cout << "Enter the ID of the Task you want to start performin: ";
	std::cin >> idSerach;
	for (auto tasks : listTask) {
		if (tasks.getIdTask() == idSerach) {
			clearTer.clear();
			std::cout << "[                    *PomodoroTimer*                      ]" << std::endl;
			std::cout << "Id: " << tasks.getIdTask() << std::endl;
			std::cout << "You have selected the task: " << tasks.getName() << std::endl;
			std::cout << "Description: " << tasks.getDescription() << std::endl;
		}
		else {
			std::cout << "Task not found!" << std::endl;
		}
	}
}

