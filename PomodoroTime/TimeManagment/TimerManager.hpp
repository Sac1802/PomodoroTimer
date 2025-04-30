#ifndef TimerManager_HPP
#define TimerManager_HPP

#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include "../Controller/ControllerTask.hpp"

class TimerManager {
public: 
	void getTimerStudy();
	void managerTimer(int timeStudy, int timeRest);

};

#endif // !TimerManager_HPP
