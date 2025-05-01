#ifndef App_HPP
#define App_HPP
#pragma once

#include <iostream>
#include <string>
#include "../ClearTerminal/ClearTermnal.hpp"
#include "../Controller/ControllerTask.hpp"
#include "../TimeSound/TimeSound.hpp"

class App {
public:
	App();
	void run() const;
	void election(int option) const;

};

#endif // !App_HPP

