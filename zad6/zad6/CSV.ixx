export module CSV;

import <iostream>;
import <string>;
import <random>;
import <fstream>;
import <cstring>;
import <vector>;

import Structs;
import Logger;
import Shop;
import Helpers;

export template<class T>
struct SaveData {
    std::vector<T>& data;
    const std::string& fileName;

    SaveData(std::vector<T>& data, const std::string& fileName)
        : data(data), fileName(fileName) {}
};

export template <typename T>
void saveToCsv(const SaveData<T>& saveData) {
    if (saveData.data.empty()) {
        Logger::warning("There is no data to save");
        return;
    }

    // Open the file for writing
    std::ofstream file(saveData.fileName);
    if (!file.is_open()) {
        Logger::error("Error: Unable to open file for writing: " + saveData.fileName);
        return;
    }


    // Write column headers
    file << "Name,";
    if constexpr (std::is_same_v<T, Item>)
        file << "Price\n";
    else if constexpr (std::is_same_v<T, Employee>)
        file << "Age\n";

    // Write the data for each item
    for (const auto& item : saveData.data) {
        file << item.getName() << ",";
        if constexpr (std::is_same_v<T, Item>)
            file << item.getPrice() << "\n";
        else if constexpr (std::is_same_v<T, Employee>)
            file << item.getAge() << "\n";
    }

    file.close();
    Logger::ok("Data saved to file: " + saveData.fileName);
}

export template<class T>
struct ReadData {
    std::vector<T>& data;
    const std::string& fileName;

    ReadData(std::vector<T>& data, const std::string& fileName)
        : data(data), fileName(fileName) {}
};

template<class T>
void readFromCsv(const ReadData<T>& readData) {
    readData.data.clear();  // Clear the vector

    std::ifstream file(readData.fileName);
    if (!file.is_open()) {
        Logger::error("Error: Unable to open file " + readData.fileName);
        return;
    }

    std::string line;
    std::getline(file, line); // Discard first line

    while (std::getline(file, line)) {
        std::vector<std::string> itemElement = splitString(line, ',');
        if (itemElement.size() >= 2) {
            T item;
            item.setName(itemElement[0]);
            if constexpr (std::is_same_v<T, Item>)
                item.setPrice(stringToNumber<double>(itemElement[1]));
            else if constexpr (std::is_same_v<T, Employee>)
                item.setAge(stringToNumber<int>(itemElement[1]));
            readData.data.push_back(item);
        } else
            Logger::warning("Invalid data format in the CSV file: " + readData.fileName);
    }

    file.close();
    Logger::ok("Data imported from file: " + readData.fileName);
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
