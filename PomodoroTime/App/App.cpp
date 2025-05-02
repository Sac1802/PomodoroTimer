#include "App.hpp"
#include "../Menu/Menu.hpp"


extern ClearTerminal clearT;
ControllerTask controllerTask;
TimerManager timerManager;
Menu menu;
App::App() {
	
}

void App::run() const {
	int option;
	do {
		menu.ShowMenu();
		std::cout << "Select an option: ";
		std::cin >> option;
		if (option < 1 || option > 6) {
			std::cout << "Invalid option. Please try again." << std::endl;
			clearT.clear();
			menu.ShowMenu();
		}
		App::election(option);
	} while (option != 5);
}

void App::election(int option) const {
	switch (option) {
	case 1:
		std::cout << "Starting Pomodoro..." << std::endl;
		timerManager.getTimerStudy();
		clearT.clear();
		break;
	case 2:
		controllerTask.addTask();
		std::cout << "Task added successfully!" << std::endl;
		clearT.clear();
		break;
	case 3:
		controllerTask.viewListTask();
		break;
	case 4:
		controllerTask.completeTask();
		clearT.clear();
		break;
	case 5:
		std::cout << "Exiting the program..." << std::endl;
		break;
	default:
		break;
	}

}