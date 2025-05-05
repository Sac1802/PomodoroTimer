/*****************************************************************//**
 * \file   Menu.hpp
 * \brief  Header file for view the available options
 * definition of the function to be able to see the options.
 * \author Acost
 * \date   May 2025
 *********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#pragma once

 /// Standard libraries
#include <iostream> /// C++ standard library
#include <string> /// C++ library for managing strings objects 
#include <vector> ///< Standard library container for dynamic arrays.

// Project of file
#include "../Models/Task.hpp" /// Task class representation.

/**
 * @class Menu
 * @brief Displays menu options for Pomodoro Time.
 *
 * Provides functionality to display the available options to the user.
 */

class Menu {

public:
	/**
	 * @brief Default constructor.
	 *
	 * Initializes a Menu instance for displaying options.
	 */
    Menu();
	/**
	 * @brief Displays the Pomodoro Time menu.
	 *
	 * Outputs the available options to the user.
	 */
    void ShowMenu();
};

#endif // MENU_HPP


