export module Shop;

import <iostream>;

import Structs;
import Random;
import Helpers;
import Text;

export namespace shop {
	void createItems(Item*& items, size_t& numberOfItems) {
		numberOfItems = random::getRandomNumber(1, 16);

		create(items, numberOfItems);

		for (size_t i = 0; i < numberOfItems; i++)
		{
			items[i].name = random::getRandomString(random::getRandomNumber(1, 32));
			items[i].price = random::getRandomNumber(0.1, 999.9, 2);
		}

		std::cout << text::FG_GREEN << "Shop items created" << text::RESET << "\n";
	}

	void showItems(Item*& items, size_t length) {
		if (items == nullptr)
		{
			std::cout << text::BG_RED << text::BOLD << "There is no items to show" << text::RESET << "\n";
			return;
		}

		for (size_t i = 0; i < length; i++)
		{
			std::cout << items[i].name << "\t" << items[i].price << " PLN\n";
		}
		std::cout << "\n" << text::FG_GREEN << "END" << "\n" << text::RESET;
	}
}