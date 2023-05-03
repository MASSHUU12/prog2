export module CSV;

import <iostream>;
import <string>;
import <random>;
import <fstream>;
import <cstring>;

import Structs;
import Logger;
import Shop;

export template<class T>
struct SaveData {
	T* data;
	const int& length;
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

export template<class T>
void readFromCsv(const SaveData<T>& saveData) {
	if constexpr (std::is_same_v<T, Item>)
		ItemManager::deleteAll();
	if constexpr (std::is_same_v<T, Employee>)
		EmployeeManager::deleteAll();

	std::ifstream file(saveData.fileName);
	T item;
	saveData.length = 0;

	while (file >> item) {
		saveData.length++;
		saveData.data.push_back(item);
	}
}

export template <typename T>
std::ostream& operator<<(std::ostream& os, const SaveData<T>& data) {
	saveToCsv(data);
	return os;
}
