/*****************************************************************//**
 * \file   ControllerTask.hpp
 * \brief  Header file defining CRUD operations for task management.
 * 
 * Provides functionality to add, view, delete, and select tasks
 * from a simulated task database stored in a vector.
 * 
 * \author Acost
 * \date   May 2025
 *********************************************************************/
#ifndef ControllerTask_HPP
#define ControllerTask_HPP

#pragma once
 // Standard libraries
#include <iostream> /// C++ standard library
#include <string> /// C++ library for managing strings objects 
#include <vector> ///< Standard library container for dynamic arrays.

// Project of file
#include "../Models/Task.hpp" /// Class or object to save 
#include "../ClearTerminal/ClearTermnal.hpp" /// Cleaning the terminal for better viewing.

/**
 * @class ControllerTask
 * @brief Manages task operations using a CRUD system.
 *
 * Provides functions to add, view, delete, and select tasks.
 */
class ControllerTask {
private:
	/**
	 * @brief Stores the list of tasks.
	 *
	 * Acts as a simulated database where tasks can be added, viewed, or removed.
	 */
	static std::vector<Task> listTask;

public:
	/**
	 * @brief Adds a new task to the list.
	 *
	 * Requests task details from the user and stores them in the vector.
	 */
	void addTask();
	/**
	 * @brief Displays all stored tasks.
	 *
	 * Iterates over the task list and prints their details to the console.
	 */
	void viewListTask();
	/**
	 * @brief Deletes a task from the list.
	 *
	 * Removes a task based on its ID, ensuring proper task management.
	 */
	void completeTask();
	/**
	* @brief Selects a task by its ID.
	*
	* Allows the user to choose a task and perform operations on it.
	*/
	void selectTask();
};


#endif // !ControllerTask_HPP
