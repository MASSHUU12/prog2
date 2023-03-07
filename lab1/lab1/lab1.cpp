import <iostream>;

import Helpers;
import Menu;
import Text;
import Enums;
import Shop;
import Structs;
import Logger;

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

		// Check if user wants to exit program
		if (input == "q" || input == "Q")
		{
			std::cout << "Exiting gracefully...";
			break;
		}

		try
		{
			validatedInput = stringToInt(input);
		}
		catch (const std::invalid_argument& e)
		{
			clearScreen();

			logger::error(std::string("Invalid input: ") + e.what() + "\n");
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
		case EDIT_SHOP_ITEM:
			shop::edit(items, numberOfItems);
			break;
		case SAVE_SHOP_ITEMS:
			save_to_csv(items, numberOfItems, "shop_items.csv");
			break;
		case CREATE_EMPLOYEES:
			break;
		case SHOW_EMPLOYEES:
			break;
		case DELETE_EMPLOYEES:
			break;
		case EDIT_EMPLOYEE:
			break;
		case SAVE_EMPLOYEES:
			break;
		default:
			logger::error(std::string("Invalid input: Such an option doesn't exist") + "\n");
			break;
		}
		
	} while (true);

	return 0;
}
