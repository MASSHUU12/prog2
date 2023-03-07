export module Shop;

import <iostream>;
import <string>;

import Structs;
import Random;
import Helpers;
import Text;
import Logger;

export namespace shop {
	void deleteItems(Item*& items, size_t& length) {
		if (items == nullptr) {
			logger::warning("There is no items to delete");
			return;
		}
		delete[] items;

		items = nullptr;
		length = 0;

		logger::ok("Shop items deleted");
	}

	void createItems(Item*& items, size_t& numberOfItems) {
		if (items != nullptr)
		{
			deleteItems(items, numberOfItems);
			clearScreen();
		}

		numberOfItems = random::getRandomNumber(1, 32);

		create(items, numberOfItems);

		for (size_t i = 0; i < numberOfItems; i++)
		{
			items[i].name = random::getRandomString(random::getRandomNumber(1, 32));
			items[i].price = random::getRandomNumber(0.1, 999.9, 2);
		}

		logger::ok("Shop items created");
	}

	void showItems(Item*& items, const size_t length) {
		if (items == nullptr)
		{
			logger::warning("There is no items to show");
			return;
		}

		for (size_t i = 0; i < length; i++)
		{
			if (i % 2 == 0)
			{
				std::cout << text::BG_GREEN << text::FG_BLACK << items[i].name << "    " << items[i].price << " PLN\n" << text::RESET;
				continue;
			}
			std::cout << items[i].name << "    " << items[i].price << " PLN\n";
		}
		logger::ok("END");

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
			logger::warning("There is no items to edit");
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
				logger::error(std::string("Invalid input: ") + e.what() + "\n");
				continue;
			}

			if (validatedInput >= length || validatedInput < 0)
			{
				logger::error("Invalid input: The number specified exceeds the acceptable range");
				continue;
			}

			break;
		} while (true);

		index = validatedInput;
		Item item = items[index];

		std::cout << "You're editing:\n";
		logger::warning(item.name + std::string("    ") + std::to_string(item.price));

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
				logger::error(std::string("Invalid input: ") + e.what() + "\n");
				continue;
			}
			break;
		} while (true);

		items[index].price = validatedDInput;
	}
}