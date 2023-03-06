export module Helpers;

import <iostream>;
import <string>;
import <random>;
import <conio.h>;

import Structs;

export int stringToInt(const std::string& str)
{
	// Check that the input string is not empty
	if (str.empty())
		throw std::invalid_argument("Input string contains non-digit characters");
	
	// Check that the input string only contains digits
	for (char c : str)
	{
		if (!std::isdigit(c))
			throw std::invalid_argument("Input string contains non-digit characters");
	}

	// Convert the input string to an integer
	return std::stoi(str);
}

export void stringToLower(std::string& str) {
	// Loop all characters
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = std::tolower(str[i]);
	}
}

export void inline clearScreen(void) {
	#if defined _WIN32
		system("cls");
	#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");
	#elif defined(__APPLE__)
		system("clear");
	#endif
}

export void create(Item*& item) {
	item = new Item;
}

export void create(Item*& item, const size_t size) {
	item = new Item[size];
}

export void pause(const char str) {
	std::cout << str;
	_getch();
}

export void pause(const std::string& str) {
	std::cout << str;
	_getch();
}