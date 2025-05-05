/*****************************************************************//**
 * \file   App.cpp
 * \brief  Implementation of the App class.
 * This file contains the logic for managing the application's flow,
 * including user interaction, menu display, and task handling.
 * \author Acost
 * \date   May 2025
 *********************************************************************/

#include "App.hpp"
#include "../Menu/Menu.hpp"

/**
 * @brief External instance for terminal clearning.
 */
extern ClearTerminal clearT;

///  Controller for managing tasks.
ControllerTask controllerTask;
/// Timer manager for handling Pomodoro sessions.
TimerManager timerManager;
/// Menu instance for user interaction.
Menu menu;

/**
 * @brief Default constructor for the App class.
 * 
 * Initializes an instance of App.
 */
App::App() {
	
}

/**
 * @brief Runs the application loop.
 *
 * Displays the menu, collects user input, validates selections,
 * and calls the election function to execute the desired option.
 */

void App::run() const {
	int option = 0;
	std::string select;
	do {
		menu.ShowMenu();
		std::cout << "Select an option: ";
		std::getline(std::cin, select);
 
		try
		{
			option = std::stoi(select);
		}
		catch (const std::exception&)
		{
			std::cout << "Invalid option. Please try again." << std::endl;
			option = 0;
			clearT.clear();
			continue;
		}
		if (option < 1 || option > 6 || option == 0) {
			std::cout << "Invalid option. Please try again." << std::endl;
			clearT.clear();
		}
		App::election(option);
	} while (option != 5);
}

/**
 * @brief Executes the action based on user selection.
 *
 * Calls the appropriate function depending on the selected option.
 *
 * @param option User-selected menu option (1-5).
 */

void App::election(int option) const {
	switch (option) {
	case 1:
		std::cout << "Starting Pomodoro..." << std::endl;
		timerManager.getTimerStudy();
		clearT.clear();
		break;
	case 2:
		controllerTask.addTask();
		std::cout << "Task added successfully!" << std::endl;
		clearT.clear();
		break;
	case 3:
		controllerTask.viewListTask();
		break;
	case 4:
		controllerTask.completeTask();
		clearT.clear();
		break;
	case 5:
		std::cout << "Exiting the program..." << std::endl;
		break;
	default:
		break;
	}

}