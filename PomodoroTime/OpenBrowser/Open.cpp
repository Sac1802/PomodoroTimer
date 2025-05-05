/*****************************************************************//**
 * \file   Open.cpp
 * \brief  Implementation of OpenBrowser class functions.
 * 
 * Handles the selection of music-related URLs and opens them in the default web browser.
 * Uses a mapped collection of predefined options to facilitate user interaction.
 * 
 * \author Acost
 * \date   May 2025
 *********************************************************************/
#include "Open.hpp"

 /**
  * @brief Selects the music URL based on the user's choice.
  *
  * Presents a menu with predefined music categories and assigns
  * the selected URL to the `url` attribute. Ensures valid input before proceeding.
  */
void OpenBrowser::selectUrl() {
	std::map<MusicOption, std::string> mapUrl = {
		{MusicOption::STUDY, "https://open.spotify.com/playlist/114I4IGwxOGKxzww8876lA"},
		{MusicOption::NCS, "https://open.spotify.com/playlist/0LvYmZs7u4gUEh2e1z7Yk3"},
		{MusicOption::MOTIVATE, "https://music.youtube.com/watch?v=r6zIGXun57U&list=RDAMVMr6zIGXun57U"}
	};
	int option;
	do {
		std::cout << "|------------------------------|" << std::endl;
		std::cout << "1. Music to study: " << std::endl;
		std::cout << "2. Music to NCS: " << std::endl;
		std::cout << "3. Music to motivate: " << std::endl;
		std::cout << "Select an option: ";
		if (!(std::cin >> option)) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid input. Please a enter a number. \n";
			continue;
		}
		auto it = mapUrl.find(static_cast<MusicOption>(option));
		if (it != mapUrl.end()) {
			url = it->second;
		}
		else {
			std::cout << "Invalid option. Please try again." << std::endl;
		}

	} while (option < 1 || option > 3);
	openUrl();
}

/**
 * @brief Opens the selected URL in the system's default web browser.
 *
 * Uses Windows Shell API to launch the browser with the stored URL.
 */
void OpenBrowser::openUrl() {
	ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
}