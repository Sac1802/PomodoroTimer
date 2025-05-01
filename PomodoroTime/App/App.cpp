#include "App.hpp"
#include "../Menu/Menu.hpp"


extern ClearTerminal clearT;
ControllerTask controllerTask;
TimeSound timeSound;
Menu menu;
App::App() {
	
}

void App::run() const {
	int option;
	menu.ShowMenu();
	std::cout << "Select an option: ";
	std::cin >> option;
	if (option < 1 || option > 6) {
		std::cout << "Invalid option. Please try again." << std::endl;
		clearT.clear();
		menu.ShowMenu();
	}
	App::election(option);
}

void App::election(int option) const {
	switch (option) {
	case 1:
		std::cout << "Starting Pomodoro..." << std::endl;
		break;
	case 2:
		controllerTask.addTask();
		std::cout << "Task added successfully!" << std::endl;
		break;
	case 3:
		timeSound.Initialization();
		timeSound.loadSound();
		timeSound.playSound();
		std::cout << "Playing sound..." << std::endl;
		timeSound.stopSound();
		break;
	default:
		break;
	}

}