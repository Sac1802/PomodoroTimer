#include "TimerManager.hpp"

void TimerManager::getTimerStudy() {
	std::string getMinutes;
	std::string getMinutesRest;
	int minutes;
	int minutesRest;

	std::cout << "Enter how long you want to study (enter in minutes please): ";
	std::cin.ignore();
	std::getline(std::cin, getMinutes);

	std::cout << "Enter the rest time in minutes: ";
	std::cin.ignore();
	std::getline(std::cin, getMinutesRest);
	try
	{
		minutes = std::stoi(getMinutes);
		minutesRest = std::stoi(getMinutesRest);
	}
	catch (const std::exception&)
	{
		std::cout << "Please enter an integer value." << std::endl;
	}
	ControllerTask::selectTask;
}

void TimerManager::managerTimer(int timeStudy, int timeRest) {
	int secondsStudy = timeStudy * 60;
	int secondsRest = timeRest * 60;
	int secondsTotal = secondsStudy + secondsRest;
	int index = secondsStudy;
	std::cout << "Time:" << std::endl;
	while (secondsTotal != 0) {
		std::chrono::seconds timer(index);
		if (index == 0) {
			std::this_thread::sleep_for(std::chrono::seconds(60));
			index = secondsRest;
		}
		std::cout << "\r                             \r";
		std::cout << std::chrono::duration_cast<std::chrono::minutes>(timer).count() << ":";
		std::cout << std::chrono::duration_cast<std::chrono::seconds>(timer).count();
		index--;
		secondsTotal--;
	}
}