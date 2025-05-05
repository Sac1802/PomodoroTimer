/*****************************************************************//**
 * \file   TimeManager.cpp
 * \brief  Implementation of TimerManager class methods.
 * 
 * Controls the Pomodoro timer for study sessions and manages rest periods.
 * Uses time-based functions and sound notifications to enhance productivity.
 * 
 * \author Acost
 * \date   May 2025
 *********************************************************************/
#include "TimerManager.hpp"

 /// Controller instance for managing tasks.
ControllerTask controllerTasks;
/// Instance for handling timer sounds.
TimeSound timeSound;
/// Browser instance for opening study-related URLs.
OpenBrowser openBrowser;

/**
 * @brief Initializes a study session using the Pomodoro technique.
 *
 * Prompts the user for study and rest durations, validates input,
 * and initiates a task selection before starting the timer.
 */
void TimerManager::getTimerStudy() {
	std::string getMinutes;
	std::string getMinutesRest;
	int minutes;
	int minutesRest;
	std::cout << "[                        *PomodoroTimer*                          ]" << std::endl;
	std::cout << "Enter how long you want to study (enter in minutes please): ";
	std::getline(std::cin, getMinutes);

	std::cout << "Enter the rest time in minutes: ";
	std::getline(std::cin, getMinutesRest);
	try
	{
		minutes = std::stoi(getMinutes);
		minutesRest = std::stoi(getMinutesRest);
	}
	catch (const std::exception&)
	{
		std::cout << "Please enter an integer value." << std::endl;
		return;
	}
	openBrowser.selectUrl();
	controllerTasks.selectTask();
	managerTimer(minutes, minutesRest);
}

/**
 * @brief Runs the Pomodoro timer, switching between study and rest phases.
 *
 * Tracks time using multithreading and plays sound notifications
 * to indicate transitions between study and rest periods.
 *
 * @param timeStudy Duration of the study session (in minutes).
 * @param timeRest Duration of the rest session (in minutes).
 */
void TimerManager::managerTimer(int timeStudy, int timeRest) {

	int secondsStudy = timeStudy * 60;
	int secondsRest = timeRest * 60;
	int secondsTotal = secondsStudy + secondsRest;
	int index = secondsStudy;
	bool isRest = false;
	timeSound.Initialization();

	std::cout << "Time:" << std::endl;
	while (secondsTotal != 0) {
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::chrono::seconds timer(index);
		int minutes = index / 60;
		int seconds = index % 60;

		if (index == 0) {
			timeSound.loadSound();
			timeSound.playSound();
			timeSound.stopSound();
			index = secondsRest;
			isRest = true;
			std::cout << "\r                             \r";
			std::cout << "Time of Rest" << std::endl;
		}
		std::cout << "\r                             \r";
		std::cout << "\r" << std::setw(2) << std::setfill('0') << minutes << ":"
			<< std::setw(2) << std::setfill('0') << seconds << std::flush;
		index--;
		secondsTotal--;
	}

	std::cout << "\n¡ Study and rest complete!" << std::endl;
	timeSound.stopSound();
}