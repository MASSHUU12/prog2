export module Shop;

import <vector>;
import <memory>;
import <optional>;

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
	void operator()(std::unique_ptr<T>& obj) const {
		obj = std::make_unique<T>("", 0.0);
	}

	template<typename T>
	void operator()(std::vector<std::unique_ptr<T>>& objs, const size_t size) const {
		objs.resize(size);
		for (size_t i = 0; i < size; ++i) {
			objs[i] = std::make_unique<T>("", 0.0);
		}
	}
};

// Functor for deleting items
struct ShopDeleter {
	template<typename T>
	void operator()(std::vector<std::unique_ptr<T>>& objs) const {
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
	void operator()(std::vector<std::unique_ptr<T>>& objs) const {
		if (!objs.empty()) {
			ShopDeleter deleter;
			deleter(objs);
			clearScreen();
		}

		size_t numberOfObjs = Random::getRandomNumber(1, 32);
		ShopCreator creator;
		creator(objs, numberOfObjs);

		if constexpr (std::is_same_v<T, Item>) {
			for (size_t i = 0; i < numberOfObjs; i++) {
				objs[i]->setName(Random::getRandomString(Random::getRandomNumber(1, 32)));
				objs[i]->setPrice(Random::getRandomNumber(0.1, 999.9, 2));
			}
		}
		if constexpr (std::is_same_v<T, Employee>) {
			for (size_t i = 0; i < numberOfObjs; i++) {
				objs[i]->setName(Random::getRandomString(Random::getRandomNumber(1, 32)));
				objs[i]->setAge(Random::getRandomNumber(18, 100));
			}
		}

		Logger::ok("Objects created");
	}
};

// Functor for showing items
struct ShopShower {
	template<typename T>
	void operator()(const std::vector<std::unique_ptr<T>>& objs) const {
		if (objs.empty()) {
			Logger::warning("There are no objects to show.");
			return;
		}

		if constexpr (std::is_same_v<T, Item>) {
			for (size_t i = 0; i < objs.size(); i++) {
				if (i % 2 == 0) {
					std::cout << Text::BG_GREEN << Text::FG_BLACK
						<< objs[i]->getName() << "  " << objs[i]->getPrice()
						<< " PLN\n" << Text::RESET;
					continue;
				}
				std::cout << objs[i]->getName() << "  " << objs[i]->getPrice() << " PLN\n";
			}
		}
		if constexpr (std::is_same_v<T, Employee>) {
			for (size_t i = 0; i < objs.size(); i++) {
				if (i % 2 == 0) {
					std::cout << Text::BG_GREEN << Text::FG_BLACK
						<< objs[i]->getName() << "  " << objs[i]->getAge()
						<< "\n" << Text::RESET;
					continue;
				}
				std::cout << objs[i]->getName() << "  " << objs[i]->getAge() << "\n";
			}
		}

		Logger::ok("END");

		pause<std::string>("\nPress any key to continue...");
		clearScreen();
	}
};

// Functor for editing items
struct ShopEditor {
	template<typename T>
	void operator()(std::vector<std::unique_ptr<T>>& objs) const {
		std::string input;
		std::optional<int> validatedInput;
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

			validatedInput = stringToNumber<int>(input);
			if (!validatedInput.has_value())
			{
				Logger::error(std::string("Invalid input: can't convert \"") + input + "\" to integer.\n");
				continue;
			}

			if (validatedInput.value() >= objs.size() || validatedInput.value() < 0) {
				Logger::error("Invalid input: The number specified exceeds the acceptable range.");
				continue;
			}

			break;
		} while (true);

		index = validatedInput.value();
		T& obj = *objs[index];

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
	static void create(std::unique_ptr<Item>& item) {
		ShopCreator creator;
		creator(item);
	}

	static void create(std::vector<std::unique_ptr<Item>>& items, const size_t size) {
		ShopCreator creator;
		creator(items, size);
	}

	static void deleteAll(std::vector<std::unique_ptr<Item>>& items) {
		ShopDeleter deleter;
		deleter(items);
	}

	static void fill(std::vector<std::unique_ptr<Item>>& items) {
		ShopFiller filler;
		filler(items);
	}

	static void show(const std::vector<std::unique_ptr<Item>>& items) {
		ShopShower shower;
		shower(items);
	}

	static void edit(std::vector<std::unique_ptr<Item>>& items) {
		ShopEditor editor;
		editor(items);
	}
};

export class EmployeeManager : public Shop {
public:
	static void create(std::unique_ptr<Employee>& item) {
		ShopCreator creator;
		creator(item);
	}

	static void create(std::vector<std::unique_ptr<Employee>>& items, const size_t size) {
		ShopCreator creator;
		creator(items, size);
	}

	static void deleteAll(std::vector<std::unique_ptr<Employee>>& items) {
		ShopDeleter deleter;
		deleter(items);
	}

	static void fill(std::vector<std::unique_ptr<Employee>>& items) {
		ShopFiller filler;
		filler(items);
	}

	static void show(const std::vector<std::unique_ptr<Employee>>& items) {
		ShopShower shower;
		shower(items);
	}

	static void edit(std::vector<std::unique_ptr<Employee>>& items) {
		ShopEditor editor;
		editor(items);
	}
};

