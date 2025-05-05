/*****************************************************************//**
 * \file   ClearTerminal.cpp
 * \brief  Implementation of ClearTerminal class functions.
 * 
 * This file provides the functionality to clear the terminal screen
 * depending on the operating system.
 * 
 * \author Acost
 * \date   May 2025
 *********************************************************************/
#include "ClearTermnal.hpp"

 /**
  * @brief Clears the terminal screen.
  *
  * Uses system-specific commands to refresh the console.
  */

void ClearTerminal::clear() {
#ifdef _WIN32
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = { 0, 0 };

    if (hStdOut == INVALID_HANDLE_VALUE) return;

    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    if (!FillConsoleOutputCharacter(hStdOut, ' ', cellCount, homeCoords, &count)) return;
    if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) return;

    SetConsoleCursorPosition(hStdOut, homeCoords);
#else
    std::cout << "\033[2J\033[1;1H";
#endif
}