export module Helpers;

import <iostream>;
import <string>;
import <random>;
import <fstream>;
import <cstring>;
import <vector>;

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

export template<typename T>
T stringToNumber(const std::string& str)
{
	// Check that the input string is not empty
	if (str.empty())
		throw std::invalid_argument("Input string is empty");

	// Create a string stream to parse the input string
	std::istringstream ss(str);

	// Try to extract a value of type T from the string stream
	T value;
	ss >> value;

	// Check that the extraction was successful and that there are no trailing characters
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("Input string contains non-numeric characters");

	return value;
}

export void stringToLower(std::string& str) {
	// Loop all characters
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = std::tolower(str[i]);
	}
}

// This function splits a string into substrings using a specified delimiter character.
export std::vector<std::string> splitString(const std::string& inputString, char delimiter) {
	std::vector<std::string> outputVector;

	// The start position for the next substring to be extracted.
	size_t startPos = 0;
	// The end position of the current delimiter.
	size_t endPos = 0;

	// Loop through the input string, extracting substrings between the specified delimiter character.
	while ((endPos = inputString.find(delimiter, startPos)) != std::string::npos) {
		// Extract the substring and add it to the output vector.
		outputVector.push_back(inputString.substr(startPos, endPos - startPos));
		// Set the start position for the next substring to be extracted.
		startPos = endPos + 1;
	}

	// Extract the last substring, which may not be followed by the delimiter character.
	outputVector.push_back(inputString.substr(startPos));
	return outputVector;
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

export class CustomString {
private:
	char* str;
public:
	CustomString(const char* s = "") {
		str = new char[std::strlen(s) + 1];
		strcpy_s(str, std::strlen(s) + 1, s);
	}

	CustomString(const CustomString& s) {
		str = new char[std::strlen(s.str) + 1];
		strcpy_s(str, std::strlen(s.str) + 1, s.str);
	}

	~CustomString() {
		delete[] str;
	}

	// Assignment operator that takes a CustomString object as input
	// and returns a reference to this object
	CustomString& operator=(const CustomString& s) {
		// Check for self-assignment
		if (this == &s) {
			return *this;
		}

		// Free the existing memory and create a new char array of the appropriate size
		delete[] str;
		str = new char[std::strlen(s.str) + 1];

		// Copy the input string
		strcpy_s(str, std::strlen(s.str) + 1, s.str);

		// Return a reference to this object
		return *this;
	}

	// Prints the char array to the console
	void display() {
		std::cout << str << std::endl;
	}

	// [] overloading
	char& operator[](int index) {
		if (index < 0 || index >= strlen(str)) {
			throw std::out_of_range("Index out of range");
		}
		return str[index];
	}

	const char& operator[](int index) const {
		if (index < 0 || index >= strlen(str)) {
			throw std::out_of_range("Index out of range");
		}
		return str[index];
	}
};