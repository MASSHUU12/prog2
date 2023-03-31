export module Shop;

import <iostream>;
import <string>;

import Structs;
import Random;
import Helpers;
import Text;
import Logger;

export namespace shop {
	void create(Item*& item) {
		item = new Item;
	}

	void create(Item*& item, const size_t size) {
		item = new Item[size];
	}

	void create(Employee*& item) {
		item = new Employee;
	}

	void create(Employee*& item, const size_t size) {
		item = new Employee[size];
	}

	void deleteAll(Item*& items, size_t& length) {
		if (items == nullptr) {
			Logger::warning("There is no items to delete");
			return;
		}
		delete[] items;

		items = nullptr;
		length = 0;

		Logger::ok("Shop items deleted");
	}

	void deleteAll(Employee*& employees, size_t& length) {
		if (employees == nullptr) {
			Logger::warning("There is no employees to delete");
			return;
		}
		delete[] employees;

		employees = nullptr;
		length = 0;

		Logger::ok("Shop employees deleted");
	}

	void fill(Item*& items, size_t& numberOfItems) {
		if (items != nullptr)
		{
			deleteAll(items, numberOfItems);
			clearScreen();
		}

		numberOfItems = Random::getRandomNumber(1, 32);

		create(items, numberOfItems);

		for (size_t i = 0; i < numberOfItems; i++)
		{
			items[i].name = Random::getRandomString(Random::getRandomNumber(1, 32));
			items[i].price = Random::getRandomNumber(0.1, 999.9, 2);
		}

		Logger::ok("Shop items created");
	}

	void fill(Employee*& employees, size_t& numberOfEmployees) {
		if (employees != nullptr)
		{
			deleteAll(employees, numberOfEmployees);
			clearScreen();
		}

		numberOfEmployees = Random::getRandomNumber(1, 32);

		create(employees, numberOfEmployees);

		for (size_t i = 0; i < numberOfEmployees; i++)
		{
			employees[i].name = Random::getRandomString(Random::getRandomNumber(1, 32));
			employees[i].age = Random::getRandomNumber(18, 100);
		}

		Logger::ok("Shop employees created");
	}

	void show(Item*& items, const size_t length) {
		if (items == nullptr)
		{
			Logger::warning("There is no items to show");
			return;
		}

		for (size_t i = 0; i < length; i++)
		{
			if (i % 2 == 0)
			{
				std::cout << Text::BG_GREEN << Text::FG_BLACK
					<< items[i].name << "    " << items[i].price
					<< " PLN\n" << Text::RESET;
				continue;
			}
			std::cout << items[i].name << "    " << items[i].price << " PLN\n";
		}
		Logger::ok("END");

		pause("\nPress any key to continue...");
		clearScreen();
	}

	void show(Employee*& employees, const size_t length) {
		if (employees == nullptr)
		{
			Logger::warning("There is no employees to show");
			return;
		}

		for (size_t i = 0; i < length; i++)
		{
			if (i % 2 == 0)
			{
				std::cout << Text::BG_GREEN << Text::FG_BLACK
					<< employees[i].name << "    " << employees[i].age << Text::RESET << "\n";
				continue;
			}
			std::cout << employees[i].name << "    " << employees[i].age << "\n";
		}
		Logger::ok("END");

		pause("\nPress any key to continue...");
		clearScreen();
	}

	void edit(Item*& items, const size_t length) {
		std::string input;
		int validatedInput;
		double validatedDInput;
		short index;

		if (items == nullptr)
		{
			Logger::warning("There is no items to edit");
			return;
		}

		do
		{
			std::cout << "Enter which item you want to edit (0 - ";
			std::cout << length - 1 << ")\n";
			std::cout << "> ";
			std::cin >> input;

			try
			{
				validatedInput = stringToInt(input);
			}
			catch (const std::invalid_argument& e)
			{
				Logger::error(std::string("Invalid input: ") + e.what() + "\n");
				continue;
			}

			if (validatedInput >= length || validatedInput < 0)
			{
				Logger::error("Invalid input: The number specified exceeds the acceptable range");
				continue;
			}

			break;
		} while (true);

		index = validatedInput;
		Item item = items[index];

		std::cout << "You're editing:\n";
		Logger::warning(item.name + std::string("    ") + std::to_string(item.price));

		std::cout << "\nNew name: ";
		std::cin >> input;

		items[index].name = input;

		do
		{
			std::cout << "New price: ";
			std::cin >> input;

			try
			{
				validatedDInput = std::stod(input);
			}
			catch (const std::invalid_argument& e)
			{
				Logger::error(std::string("Invalid input: ") + e.what() + "\n");
				continue;
			}
			break;
		} while (true);

		items[index].price = validatedDInput;
	}

	void edit(Employee*& employees, const size_t length) {
		std::string input;
		int validatedInput;
		int validatedIInput;
		short index;

		if (employees == nullptr)
		{
			Logger::warning("There is no employees to edit");
			return;
		}

		do
		{
			std::cout << "Enter which employee you want to edit (0 - ";
			std::cout << length - 1 << ")\n";
			std::cout << "> ";
			std::cin >> input;

			try
			{
				validatedInput = stringToInt(input);
			}
			catch (const std::invalid_argument& e)
			{
				Logger::error(std::string("Invalid input: ") + e.what() + "\n");
				continue;
			}

			if (validatedInput >= length || validatedInput < 0)
			{
				Logger::error("Invalid input: The number specified exceeds the acceptable range");
				continue;
			}

			break;
		} while (true);

		index = validatedInput;
		Employee employee = employees[index];

		std::cout << "You're editing:\n";
		Logger::warning(employee.name + std::string("    ") + std::to_string(employee.age));

		std::cout << "\nNew name: ";
		std::cin >> input;

		employees[index].name = input;

		do
		{
			std::cout << "New age: ";
			std::cin >> input;

			try
			{
				validatedIInput = stringToInt(input);
			}
			catch (const std::invalid_argument& e)
			{
				Logger::error(std::string("Invalid input: ") + e.what() + "\n");
				continue;
			}
			break;
		} while (true);

		employees[index].age = validatedIInput;
	}
}