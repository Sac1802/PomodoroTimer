#include "App.hpp"
#include "../Menu/Menu.hpp"
#include "../ClearTerminal/ClearTermnal.hpp"
#include "../Controller/ControllerTask.hpp"

ClearTerminal clearT;
ControllerTask controllerTask;
Menu menu;

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
	default:
		break;
	}

}