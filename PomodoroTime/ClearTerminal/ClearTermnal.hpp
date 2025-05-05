/*****************************************************************//**
 * \file   ClearTermnal.hpp
 * \brief  Header file for terminal clearing functionality.
 * 
 * Defines the ClearTerminal class to clear the console screen 
 * depending on the operating system.
 * 
 * \author Acost
 * \date   May 2025
 *********************************************************************/
#ifndef ClearTerminal_HPP
#define ClearTerminal_HPP
#ifdef _WIN32
// Standard libraries
#include <iostream> ///< C++ standard library for input/output operations.
#include <Windows.h> ///< Windows-specific API for system commands.
#endif // _WIN32


#pragma once

/**
* @class ClearTerminal.
* 
 * @brief Provides functionality to clear the console screen.
 * 
 * This class contains a static method to clear the terminal, adapting to 
 * different operating systems.
 * 
 */
class ClearTerminal {
public:
	/**
	 * @brief Clear the terminal screen.
	 * 
	 * Executes the appropiate command based on the operating system
	 */
	static void clear();
};

#endif // !ClearTerminal_HPP
