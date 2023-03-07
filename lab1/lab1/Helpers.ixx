export module Helpers;

import <iostream>;
import <string>;
import <random>;
import <fstream>;

import Structs;
import Logger;

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

export void pause(const char str) {
	std::cout << str;

	std::cin.ignore(); // Clear any input left in memory
	std::cin.ignore(); // Wait for user to press enter
}

export void pause(const std::string& str) {
	std::cout << str;

	std::cin.ignore(); // Clear any input left in memory
	std::cin.ignore(); // Wait for user to press enter
}

export void save_to_csv(const Item* items, const int length, const std::string& fileName) {
	if (items == nullptr) {
		logger::warning("There is no items to save");
		return;
	}

	// Open the file for writing
	std::ofstream file(fileName);

	// Write column headers
	file << "Name,Price\n";

	// Write the data for each item
	for (size_t i = 0; i < length; i++)
	{
		file << items[i].name << "," << items[i].price << "\n";
	}

	file.close();

	logger::ok("Items saved to: " + fileName);
}