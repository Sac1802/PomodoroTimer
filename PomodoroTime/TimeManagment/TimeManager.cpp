#include "TimerManager.hpp"

ControllerTask controllerTasks;
TimeSound timeSound;

void TimerManager::getTimerStudy() {
	std::string getMinutes;
	std::string getMinutesRest;
	int minutes;
	int minutesRest;

	std::cout << "Enter how long you want to study (enter in minutes please): ";
	std::cin.ignore();
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
	controllerTasks.selectTask();
	managerTimer(minutes, minutesRest);
}

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