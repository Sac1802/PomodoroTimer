/*****************************************************************//**
 * \file   Menu.cpp
 * \brief  
 * 
 * \author Acost
 * \date   May 2025
 *********************************************************************/
#include "Menu.hpp"

/**
 * @brief view the options.
 * 
 * Print all available options from starting Pomodoro to exiting the program
 */
void Menu::ShowMenu() {
	std::cout << " Welcome to the Pomodoro Timer!" << std::endl;
	std::cout << "[           *PomodoroTimer*          ]" << std::endl;
	std::cout << "[ 1.Start Pomodoro                   ]" << std::endl;
	std::cout << "[ 2.Add a task                       ]" << std::endl;
	std::cout << "[ 3.View Tasks                       ]" << std::endl;
	std::cout << "[ 4.Complete Task                    ]" << std::endl;
	std::cout << "[ 5.Exit                             ]" << std::endl;
}
/**
 * @brief Default constructor for the App class.
 *
 * Initializes an instance of Menu.
 */
Menu::Menu() {

}
