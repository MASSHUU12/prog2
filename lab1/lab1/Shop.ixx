export module Shop;

import <iostream>;
import <conio.h>;

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

		numberOfItems = random::getRandomNumber(1, 16);

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

		std::cout << "\nPress any key to continue...";
		_getch();

		clearScreen();
	}
}