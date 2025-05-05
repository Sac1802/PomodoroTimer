/*****************************************************************//**
 * \file   TimerManager.hpp
 * \brief  Provides timer management functionality for study sessions.
 * 
 * Defines the TimerManager class, which controls the study timer
 * and manages rest intervals using multithreading.
 * 
 * \author Acost
 * \date   May 2025
 *********************************************************************/
#ifndef TimerManager_HPP
#define TimerManager_HPP

#pragma once

#include <iostream> /// Standard input/output library.
#include <thread> /// Library for multithreading operations.
#include <chrono> /// Library for time-based functions.
#include "../Controller/ControllerTask.hpp" /// Task controller integration.
#include "../TimeSound/TimeSound.hpp" /// Sound system for timer notifications.
#include "../OpenBrowser/Open.hpp" /// Browser integration for study sessions.
#include <iomanip> /// Formatting utilities for output.

 /**
  * @class TimerManager
  * @brief Manages study and rest timers using multithreading.
  *
  * This class provides functionality to start a study timer and manage
  * rest periods efficiently.
  */
class TimerManager {
public: 
    /**
     * @brief Starts a Pomodoro study session timer.
     *
     * Initializes the timer for study periods and plays sound notifications.
     */
	void getTimerStudy();
    /**
     * @brief Manages study and rest intervals.
     *
     * Handles time tracking for study and rest cycles using multithreading.
     *
     * @param timeStudy Duration of the study period (in minutes).
     * @param timeRest Duration of the rest period (in minutes).
     */
	void managerTimer(int timeStudy, int timeRest);

};

#endif // !TimerManager_HPP
