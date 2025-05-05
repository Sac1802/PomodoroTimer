/*****************************************************************//**
 * \file   Task.cpp
 * \brief  Implementation of the Task class methods.
 * 
 * Defines the logic for managing task attributes such as ID, name,
 * and description.
 *
 * \author Acost
 * \date   May 2025
 *********************************************************************/
#include "Task.hpp"

 /**
  * @brief Default constructor.
  *
  * Initializes a Task object without predefined attributes.
  */

Task::Task() {
}

/**
 * @brief Parameterized constructor.
 *
 * Creates a Task object with a specified ID, name, and description.
 *
 * @param idTask Unique identifier for the task.
 * @param nameTask Name of the task.
 * @param description Description of the task.
 */
Task::Task(int idTask, std::string nameTask, std::string description) {
	this->idTask = idTask;
	this->nameTask = nameTask;
	this->Description = description;
}

/**
 * @brief Retrieves the task ID.
 * @return int The task's unique identifier.
 */
int Task::getIdTask() {
	return idTask;
}

/**
 * @brief Sets the task ID.
 * @param idTask Unique identifier to be assigned.
 */
void Task::setIdTask(int idTask) {
	this->idTask = idTask;
}

/**
 * @brief Retrieves the task name.
 * @return std::string The task name.
 */
std::string Task::getName() {
	return nameTask;
}

/**
 * @brief Sets the task name.
 * @param nameTask Name to be assigned.
 */
void Task::setName(std::string nameTask) {
	this->nameTask = nameTask;
}

/**
 * @brief Retrieves the task description.
 * @return std::string The task description.
 */
std::string Task::getDescription() {
	return Description;
}

/**
 * @brief Sets the task description.
 * @param description Description to be assigned.
 */
void Task::setDescription(std::string description) {
	this->Description = description;
}