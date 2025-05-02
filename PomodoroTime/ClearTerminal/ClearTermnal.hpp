#ifndef ClearTerminal_HPP
#define ClearTerminal_HPP
#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32


#pragma once

#include <iostream>

class ClearTerminal {
public:
	static void clear();
};

#endif // !ClearTerminal_HPP
