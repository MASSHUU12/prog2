import <iostream>;

import Helpers;
import Menu;
import Text;
import Enums;
import Shop;
import Structs;

int main(void)
{
	std::string input;
	short validatedInput;

	Item* items = nullptr;
	size_t numberOfItems = 0;

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
			std::cout << text::BG_RED << text::BOLD << "Invalid input: " << e.what() << text::RESET << "\n\n";
			continue;
		}

		clearScreen();

		switch (validatedInput)
		{
		case CREATE_SHOP_ITEMS:
			shop::createItems(items, numberOfItems);
			break;
		case SHOW_SHOP_ITEMS:
			shop::showItems(items, numberOfItems);
			break;
		case DELETE_SHOP_ITEMS:
			shop::deleteItems(items, numberOfItems);
			break;
		default:
			std::cout << text::BG_RED << text::BOLD << "Invalid input: Such an option doesn't exist" << text::RESET << "\n\n";
			break;
		}
		
	} while (true);

	return 0;
}
