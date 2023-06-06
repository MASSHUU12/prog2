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

// Functor for creating items
struct ShopCreator {
	template<typename T>
	void operator()(T& obj) const {
		obj = T("", 0.0);
	}

	template<typename T>
	void operator()(std::vector<T>& objs, const size_t size) const {
		objs.resize(size);
	}
};

// Functor for deleting items
struct ShopDeleter {
	template<typename T>
	void operator()(std::vector<T>& objs) const {
		if (objs.empty()) {
			Logger::warning("There are no objects to delete.");
			return;
		}
		objs.clear();
		Logger::ok("Objects deleted.");
	}
};

// Functor for filling items
struct ShopFiller {
	template<typename T>
	void operator()(std::vector<T>& objs) const {
		if (!objs.empty()) {
			ShopDeleter deleter;
			deleter(objs);
			clearScreen();
		}

		size_t numberOfObjs = Random::getRandomNumber(1, 32);
		ShopCreator creator;
		creator(objs, numberOfObjs);

		if constexpr (std::is_same_v<T, Item>)
			for (size_t i = 0; i < numberOfObjs; i++)
			{
				objs[i].setName(Random::getRandomString(Random::getRandomNumber(1, 32)));
				objs[i].setPrice(Random::getRandomNumber(0.1, 999.9, 2));
			}
		if constexpr (std::is_same_v<T, Employee>)
			for (size_t i = 0; i < numberOfObjs; i++)
			{
				objs[i].setName(Random::getRandomString(Random::getRandomNumber(1, 32)));
				objs[i].setAge(Random::getRandomNumber(18, 100));

			}

		Logger::ok("Objects created");
	}
};

// Functor for showing items
struct ShopShower {
	template<typename T>
	void operator()(const std::vector<T>& objs) const {
		if (objs.empty()) {
			Logger::warning("There are no objects to show.");
			return;
		}

		if constexpr (std::is_same_v<T, Item>)
			for (size_t i = 0; i < objs.size(); i++)
			{
				if (i % 2 == 0) {
					std::cout << Text::BG_GREEN << Text::FG_BLACK
						<< objs[i].getName() << "  " << objs[i].getPrice()
						<< " PLN\n" << Text::RESET;
					continue;
				}
				std::cout << objs[i].getName() << "  " << objs[i].getPrice() << " PLN\n";
			}
		if constexpr (std::is_same_v<T, Employee>)
			for (size_t i = 0; i < objs.size(); i++)
			{
				if (i % 2 == 0) {
					std::cout << Text::BG_GREEN << Text::FG_BLACK
						<< objs[i].getName() << "  " << objs[i].getAge()
						<< "\n" << Text::RESET;
					continue;
				}
				std::cout << objs[i].getName() << "  " << objs[i].getAge() << "\n";
			}

		Logger::ok("END");

		pause("\nPress any key to continue...");
		clearScreen();
	}
};

// Functor for editing items
struct ShopEditor {
	template<typename T>
	void operator()(std::vector<T>& objs) const {
		std::string input;
		int validatedInput;
		double validatedDInput;
		short index;

		if (objs.empty()) {
			Logger::warning("There are no objects to edit.");
			return;
		}

		do
		{
			std::cout << "Enter which item you want to edit (0 - "
				<< objs.size() - 1 << ")\n";
			std::cout << "> ";
			std::cin >> input;

			try {
				validatedInput = stringToInt(input);
			}
			catch (const std::invalid_argument& e) {
				Logger::error(std::string("Invalid input: ") + e.what() + "\n");
				continue;
			}

			if (validatedInput >= objs.size() || validatedInput < 0) {
				Logger::error("Invalid input: The number specified exceeds the acceptable range.");
				continue;
			}

			break;
		} while (true);

		index = validatedInput;
		T& obj = objs[index];

		std::cout << "You're editing:\n";

		if constexpr (std::is_same_v<T, Item>)
			Logger::warning(obj.getName() + std::string("  ") + std::to_string(obj.getPrice()));
		if constexpr (std::is_same_v<T, Employee>)
			Logger::warning(obj.getName() + std::string("  ") + std::to_string(obj.getAge()));

		std::cout << "\nNew name: ";
		std::cin >> input;
		obj.setName(input);

		do {
			if constexpr (std::is_same_v<T, Item>)
				std::cout << "New price: ";
			if constexpr (std::is_same_v<T, Employee>)
				std::cout << "New age: ";
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

		if constexpr (std::is_same_v<T, Item>)
			obj.setPrice(validatedDInput);
		if constexpr (std::is_same_v<T, Employee>)
			obj.setAge(validatedDInput);
	}
};

export class ItemManager : public Shop {
public:
	void static create(Item& item) {
		ShopCreator creator;
		creator(item);
	}

	void static create(std::vector<Item>& items, const size_t size) {
		ShopCreator creator;
		creator(items, size);
	}

	void static deleteAll(std::vector<Item>& items) {
		ShopDeleter deleter;
		deleter(items);
	}

	void static fill(std::vector<Item>& items) {
		ShopFiller filler;
		filler(items);
	}

	void static show(const std::vector<Item>& items) {
		ShopShower shower;
		shower(items);
	}

	void static edit(std::vector<Item>& items) {
		ShopEditor editor;
		editor(items);
	}
};

export class EmployeeManager : public Shop {
public:
	void static create(Employee& item) {
		ShopCreator creator;
		creator(item);
	}

	void static create(std::vector<Employee>& items, const size_t size) {
		ShopCreator creator;
		creator(items, size);
	}

	void static deleteAll(std::vector<Employee>& items) {
		ShopDeleter deleter;
		deleter(items);
	}

	void static fill(std::vector<Employee>& items) {
		ShopFiller filler;
		filler(items);
	}

	void static show(const std::vector<Employee>& items) {
		ShopShower shower;
		shower(items);
	}

	void static edit(std::vector<Employee>& items) {
		ShopEditor editor;
		editor(items);
	}
};
