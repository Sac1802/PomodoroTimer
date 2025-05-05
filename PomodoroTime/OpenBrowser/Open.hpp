/*****************************************************************//**
 * \file   Open.hpp
 * \brief  Provides functionality to open a web browser with a specified URL.
 * 
 * This file defines the OpenBrowser class, which allows selecting and
 * opening a URL using system-specific commands. It also includes an
 * enumeration for music-related options.
 * 
 * \author Acost
 * \date   May 2025
 *********************************************************************/
#ifndef OpenBrowser_HPP
#define OpenBrowser_HPP
#include <iostream> /// Standard input/output library.
#include <string> /// Standard library for string handling.
#include <windows.h> /// Windows API for system calls
#include <shellapi.h> /// Windows Shell API for opening URLs.
#include <map> /// Standard library for mapping options.

#pragma once

 /**
  * @enum MusicOption
  * @brief Enumeration for selecting different music categories.
  *
  * Provides predefined options for music selection in the application.
  */
enum class MusicOption {
	STUDY = 1, ///  Music option for study sessions.
	NCS, /// No Copyright Sounds (NCS) music option.
	MOTIVATE /// Motivational music option.
};
/**
 * @class OpenBrowser
 * @brief Class for opening URLs in a web browser.
 *
 * Contains methods for selecting a URL and opening it using system commands.
 */

class OpenBrowser {
private:
	/// Stores the selected URL.
	std::string url;
public:
	/**
	 * @brief Selects the URL based on predefined options.
	 *
	 * Determines the appropriate URL according to the selected music option.
	 */
	void selectUrl();
	/**
	 * @brief Opens the selected URL in the system's default web browser.
	 *
	 * Uses Windows Shell API to launch the browser with the specified URL.
	 */
	void openUrl();
};

#endif // !OpenBrowser_HPP
