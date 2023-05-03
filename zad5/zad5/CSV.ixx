export module CSV;

import <iostream>;
import <string>;
import <random>;
import <fstream>;
import <cstring>;

import Structs;
import Logger;
import Shop;
import Helpers;

export template<class T>
struct SaveData {
	T* data;
	size_t& length;
	const std::string& fileName;

	SaveData(T* data, size_t length, const std::string& fileName)
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

export template<class T>
struct ReadData {
	T*& data;
	size_t& length;
	const std::string& fileName;

	ReadData(T*& data, size_t& length, const std::string& fileName)
		: data(data), length(length), fileName(fileName) {}
};

export template<class T>
void readFromCsv(ReadData<T> readData) {
	if constexpr (std::is_same_v<T, Item>)
		ItemManager::deleteAll(readData.data, readData.length);
	if constexpr (std::is_same_v<T, Employee>)
		EmployeeManager::deleteAll(readData.data, readData.length);

	std::ifstream file(readData.fileName);
	if (!file.is_open()) {
		Logger::error("Error: Unable to open file " + readData.fileName);
		return;
	}

	std::string item;
	std::vector<std::string> items;

	// Discard first line
	std::getline(file, item);

	// Read the rest of the file
	while (file >> item) {
		items.push_back(item);
	}

	readData.data = new T[items.size()];
	readData.length = items.size();

	if constexpr (std::is_same_v<T, Item>)
		for (size_t i = 0; i < items.size(); i++)
		{
			std::vector<std::string> itemElement = splitString(items[i], ',');

			if (itemElement.size() >= 2)
			{
				readData.data[i].setName(itemElement[0]);
				readData.data[i].setPrice(stringToNumber<double>(itemElement[1]));
			}
		}
	if constexpr (std::is_same_v<T, Employee>)
		for (size_t i = 0; i < items.size(); i++)
		{
			std::vector<std::string> employeeElement = splitString(items[i], ',');

			if (employeeElement.size() >= 2)
			{
				readData.data[i].setName(employeeElement[0]);
				readData.data[i].setAge(stringToNumber<int>(employeeElement[1]));
			}
		}
	file.close();

	Logger::ok("File " + readData.fileName + " imported");
}

export template <typename T>
std::ostream& operator<<(std::ostream& os, const SaveData<T>& data) {
	saveToCsv(data);
	return os;
}

export template <typename T>
std::istream& operator>>(std::istream& is, ReadData<T>& data) {
	readFromCsv(data);
	return is;
}
