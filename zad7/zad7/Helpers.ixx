export module Helpers;

import <iostream>;
import <random>;
import <charconv>;
import <optional>;

import Structs;
import Logger;

export template<typename T>
std::optional<T> stringToNumber(const std::string& str)
{
	// Check that the input string is not empty
	if (str.empty())
		return std::nullopt; // If the string is empty, return std::nullopt (empty optional)

	T value;
	// Convert the string to a numeric value
	// The result object contains information about the conversion.
	auto result = std::from_chars(str.data(), str.data() + str.size(), value);

	if (result.ec == std::errc{} && result.ptr == str.data() + str.size())
		// Check if the conversion was successful by verifying that no error occurred
		// and the entire string was parsed (result.ptr is at the end of the string)
		return value;

	// If the conversion was not successful, return std::nullopt
	return std::nullopt;
}

export void stringToLower(std::string& str) {
	// Transform the string to lowercase
	std::transform(str.begin(), str.end(), str.begin(),
		[](unsigned char c) { return std::tolower(c); });
	// std::transform applies the specified operation (lambda function) to each character in the string

	// The lambda function [](unsigned char c) { return std::tolower(c); } converts a character to lowercase
	// using std::tolower function from the <cctype> library

	// Note that the lambda function takes an unsigned char as input to handle all possible characters correctly,
	// including characters outside the ASCII range.
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
	std::cout << "\033[2J\033[H";
}

export template<typename T>
void pause(const T& str) {
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