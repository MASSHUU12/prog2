export module Shop;

import <iostream>;
import <string>;
import <vector>;

import Structs;
import Random;
import Helpers;
import Text;
import Logger;

export class Shop {
public:
	virtual void create() = 0;
	virtual void deleteAll() = 0;
	virtual void fill() = 0;
	virtual void show() = 0;
	virtual void edit() = 0;
};

export class ItemManager : public Shop {
public:
	void static create(Item& item) {
		item = Item("", 0.0);
	}

	void static create(std::vector<Item>& items, const size_t size) {
		items.resize(size);
	}

	void static deleteAll(std::vector<Item>& items) {
		if (items.empty()) {
			Logger::warning("There are no items to delete");
			return;
		}
		items.clear();
		Logger::ok("Shop items deleted");
	}

	void static fill(std::vector<Item>& items) {
		if (!items.empty()) {
			deleteAll(items);
			clearScreen();
		}

		size_t numberOfItems = Random::getRandomNumber(1, 32);
		create(items, numberOfItems);

		for (size_t i = 0; i < numberOfItems; i++) {
			items[i].setName(Random::getRandomString(Random::getRandomNumber(1, 32)));
			items[i].setPrice(Random::getRandomNumber(0.1, 999.9, 2));
		}

		Logger::ok("Shop items created");
	}

	void static show(const std::vector<Item>& items) {
		if (items.empty()) {
			Logger::warning("There are no items to show");
			return;
		}

		for (size_t i = 0; i < items.size(); i++) {
			if (i % 2 == 0) {
				std::cout << Text::BG_GREEN << Text::FG_BLACK
					<< items[i].getName() << "  " << items[i].getPrice()
					<< " PLN\n" << Text::RESET;
				continue;
			}
			std::cout << items[i].getName() << "  " << items[i].getPrice() << " PLN\n";
		}
		Logger::ok("END");

		pause("\nPress any key to continue...");
		clearScreen();
	}

	void static edit(std::vector<Item>& items) {
		std::string input;
		int validatedInput;
		double validatedDInput;
		short index;

		if (items.empty()) {
			Logger::warning("There are no items to edit");
			return;
		}

		do {
			std::cout << "Enter which item you want to edit (0 - "
				<< items.size() - 1 << ")\n";
			std::cout << "> ";
			std::cin >> input;

			try {
				validatedInput = stringToInt(input);
			}
			catch (const std::invalid_argument& e) {
				Logger::error(std::string("Invalid input: ") + e.what() + "\n");
				continue;
			}

			if (validatedInput >= items.size() || validatedInput < 0) {
				Logger::error("Invalid input: The number specified exceeds the acceptable range");
				continue;
			}

			break;
		} while (true);

		index = validatedInput;
		Item& item = items[index];

		std::cout << "You're editing:\n";
		Logger::warning(item.getName() + std::string("  ") + std::to_string(item.getPrice()));

		std::cout << "\nNew name: ";
		std::cin >> input;

		item.setName(input);

		do {
			std::cout << "New price: ";
			std::cin >> input;

			try {
				validatedDInput = std::stod(input);
			}
			catch (const std::invalid_argument& e) {
				Logger::error(std::string("Invalid input: ") + e.what() + "\n");
				continue;
			}
			break;
		} while (true);

		item.setPrice(validatedDInput);
	}
};

export class EmployeeManager : public Shop {
public:
	void static create(Employee& employee) {
		employee = Employee("", 0);
	}

	void static create(std::vector<Employee>& employees, const size_t size) {
		employees.resize(size);
	}

	void static deleteAll(std::vector<Employee>& employees) {
		if (employees.empty()) {
			Logger::warning("There are no employees to delete");
			return;
		}
		employees.clear();
		Logger::ok("Shop employees deleted");
	}

	void static fill(std::vector<Employee>& employees) {
		if (!employees.empty()) {
			deleteAll(employees);
			clearScreen();
		}

		size_t numberOfEmployees = Random::getRandomNumber(1, 32);
		create(employees, numberOfEmployees);

		for (size_t i = 0; i < numberOfEmployees; i++) {
			employees[i].setName(Random::getRandomString(Random::getRandomNumber(1, 32)));
			employees[i].setAge(Random::getRandomNumber(18, 100));
		}

		Logger::ok("Shop employees created");
	}

	void static show(const std::vector<Employee>& employees) {
		if (employees.empty()) {
			Logger::warning("There are no employees to show");
			return;
		}

		for (size_t i = 0; i < employees.size(); i++) {
			if (i % 2 == 0) {
				std::cout << Text::BG_GREEN << Text::FG_BLACK
					<< employees[i].getName() << "  " << employees[i].getAge() << Text::RESET << "\n";
				continue;
			}
			std::cout << employees[i].getName() << "  " << employees[i].getAge() << "\n";
		}
		Logger::ok("END");

		pause("\nPress any key to continue...");
		clearScreen();
	}

	void static edit(std::vector<Employee>& employees) {
		std::string input;
		int validatedInput;
		int validatedIInput;
		short index;

		if (employees.empty()) {
			Logger::warning("There are no employees to edit");
			return;
		}

		do {
			std::cout << "Enter which employee you want to edit (0 - "
				<< employees.size() - 1 << ")\n";
			std::cout << "> ";
			std::cin >> input;

			try {
				validatedInput = stringToInt(input);
			}
			catch (const std::invalid_argument& e) {
				Logger::error(std::string("Invalid input: ") + e.what() + "\n");
				continue;
			}

			if (validatedInput >= employees.size() || validatedInput < 0) {
				Logger::error("Invalid input: The number specified exceeds the acceptable range");
				continue;
			}

			break;
		} while (true);

		index = validatedInput;
		Employee& employee = employees[index];

		std::cout << "You're editing:\n";
		Logger::warning(employee.getName() + std::string("  ") + std::to_string(employee.getAge()));

		std::cout << "\nNew name: ";
		std::cin >> input;

		employee.setName(input);

		do {
			std::cout << "New age: ";
			std::cin >> input;

			try {
				validatedIInput = stringToInt(input);
			}
			catch (const std::invalid_argument& e) {
				Logger::error(std::string("Invalid input: ") + e.what() + "\n");
				continue;
			}
			break;
		} while (true);

		employee.setAge(validatedIInput);
	}
};
