/*****************************************************************//**
 * \file   Task.hpp
 * @brief Defines the Task class for managing task attributes.
 *
 * Represents a task with an ID, name, and description.
 * Provides methods for retrieving and modifying task details.
 * 
 * \author Acost
 * \date   May 2025
 *********************************************************************/
#ifndef Task_HPP
#define Task_HPP
/// C++ library for managing strings objects 
#include <string>
#pragma once

/**
 * @class Task
 * @brief Represents a task in the Pomodoro system.
 *
 * Stores attributes such as task ID, name, and description.
 * Provides methods to modify and access these attributes.
 */

class Task {
private: 
	/// Unique identifier for the task.
	int idTask;
	/// Name of the task and Description of the task
	std::string nameTask, Description;

public:
	/**
	 * @brief Default constructor.
	 *
	 * Initializes a task without predefined attributes.
	 */

	Task();
	/**
	 * @brief Parameterized constructor.
	 *
	 * Initializes a task with the given ID, name, and description.
	 *
	 * @param idTask Unique identifier for the task.
	 * @param nameTask Name of the task.
	 * @param description Description of the task.
	 */
	Task(int idTask, std::string nameTask, std::string description);
	/**
	 * @brief Retrieves the task ID.
	 * @return int The task ID.
	 */
	int getIdTask();
	/**
	 * @brief Sets the task ID.
	 * @param idTask Unique identifier to be assigned.
	 */
	void setIdTask(int idTask);
	/**
	 * @brief Retrieves the task name.
	 * @return std::string The task name.
	 */
	std::string getName();
	/**
	 * @brief Sets the task name.
	 * @param nameTask Name to be assigned.
	 */
	void setName(std::string nameTask);
	/**
	 * @brief Retrieves the task description.
	 * @return std::string The task description.
	 */
	std::string getDescription();
	/**
	 * @brief Sets the task description.
	 * @param description Description to be assigned.
	 */

	void setDescription(std::string description);

};

#endif // Task_HPP
