export module CreateShopItems;

import <iostream>;

import Structs;
import Random;
import Helpers;

export void createShopItems(Item*& items) {
	short unsigned length = random::getRandomNumber(1, 16);

	create(items, length);

	for (size_t i = 0; i < length; i++)
	{
		items[i].name = random::getRandomString(random::getRandomNumber(1, 32));
		items[i].price = random::getRandomNumber(0.1, 999.9, 2);
	}
}