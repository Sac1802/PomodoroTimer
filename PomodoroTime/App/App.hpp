#ifndef App_HPP
#define App_HPP
#pragma once
// Standard libraries
#include <iostream> /// C++ standard library
#include <string> /// C++ library for managing strings objects 
#include <cctype> /// Functions for character manipulation.
#include <sstream> /// Handling text streams.
#include <limits> /// Data boundary definitions.

// Project of file
#include "../ClearTerminal/ClearTermnal.hpp" /// Cleaning the terminal for better viewing.
#include "../Controller/ControllerTask.hpp" /// Management and control of scheduled tasks.
#include "../TimeSound/TimeSound.hpp" /// Sound module for timing.
#include "../TimeManagment/TimerManager.hpp" /// Timer management.

/**
 * @class App
 * @brief Class to manage the app section or option selection.
 *
 * This class allows users to choose one of the available options within the Pomodoro time.
 */


class App {
public:
	/**
	 * @brief empty constructor.
	 * 
	 * Class with empty constructor, for class instantiation
	 */
	App();

	/**
	 * @brief main call function.
	 * 
	 * Run function, which is the main one since through this
	 * function we are going to implement the logic for the 
	 * correct functioning of the project.
	 */
	void run() const;

	/**
	 * @brief Function for election management.
	 * 
	 * Function for handling user choice
	 * 
	 * @param option Selected option ID.
	 */
	void election(int option) const;

};

#endif // !App_HPP

