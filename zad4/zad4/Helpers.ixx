export module Helpers;

import <iostream>;
import <string>;
import <random>;
import <fstream>;
import <cstring>;

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

export template<class T>
struct SaveData {
	T* data;
	const int length;
	const std::string& fileName;

	SaveData(T* data, const int length, const std::string& fileName)
		: data(data), length(length), fileName(fileName) {}
};

export template <typename T>
void saveToCsv(const SaveData<T>& saveData) {
	if (saveData.length <= 0) {
		Logger::warning("There is no data to save");
		return;
	}

	// Open the file for writing
	std::ofstream file(saveData.fileName);

	// Write column headers
	file << "Name,";
	if constexpr (std::is_same_v<T, Item>)
		file << "Price\n";
	else if constexpr (std::is_same_v<T, Employee>)
		file << "Age\n";

	// Write the data for each item
	for (size_t i = 0; i < saveData.length; i++) {
		file << saveData.data[i].getName() << ",";
		if constexpr (std::is_same_v<T, Item>)
			file << saveData.data[i].getPrice() << "\n";
		else if constexpr (std::is_same_v<T, Employee>)
			file << saveData.data[i].getAge() << "\n";
	}

	file.close();

	if constexpr (std::is_same_v<T, Item>)
		Logger::ok("Items saved to: " + saveData.fileName);
	else if constexpr (std::is_same_v<T, Employee>)
		Logger::ok("Employees saved to: " + saveData.fileName);
}

export template <typename T>
std::ostream& operator<<(std::ostream& os, const SaveData<T>& data) {
	saveToCsv(data);
	return os;
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