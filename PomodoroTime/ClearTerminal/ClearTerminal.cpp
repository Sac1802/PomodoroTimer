#include "ClearTermnal.hpp"

void ClearTerminal::clear() {
	std::cout << "\033[2J\033[1;1H";
}