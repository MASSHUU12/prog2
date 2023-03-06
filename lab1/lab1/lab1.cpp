import <iostream>;

import Helpers;
import Menu;
import Color;
import Enums;
import CreateShopItems;
import Structs;

int main(void)
{
	std::string input;
	short validatedInput;

	Item* items = nullptr;

	do
	{
		menu();

		std::cout << "> ";
		std::cin >> input;

		stringToLower(input);

		// Check if user wants to exit program
		if (input == "q")
			break;

		try
		{
			validatedInput = stringToInt(input);
		}
		catch (const std::invalid_argument& e)
		{
			clearScreen();
			std::cout << color::fgRed << "Invalid input: " << e.what() << color::reset << "\n\n";
			continue;
		}

		clearScreen();

		switch (validatedInput)
		{
		case CREATE_SHOP_ITEMS:
			createShopItems(items);
			break;
		default:
			std::cout << color::bgRed << "Invalid input: Such an option doesn't exist" << color::reset << "\n\n";
			break;
		}
		
	} while (true);

	return 0;
}
