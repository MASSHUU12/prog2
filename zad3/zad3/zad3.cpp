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

	Employee* employees = nullptr;
	size_t numberOfEmployees = 0;

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

			Logger::error(std::string("Invalid input: ") + e.what() + "\n");
			continue;
		}

		clearScreen();

		switch (validatedInput)
		{
		case CREATE_SHOP_ITEMS:
			shop::fill(items, numberOfItems);
			break;
		case SHOW_SHOP_ITEMS:
			shop::show(items, numberOfItems);
			break;
		case DELETE_SHOP_ITEMS:
			shop::deleteAll(items, numberOfItems);
			break;
		case EDIT_SHOP_ITEM:
			shop::edit(items, numberOfItems);
			break;
		case SAVE_SHOP_ITEMS:
			saveToCsv(items, numberOfItems, "shop_items.csv");
			break;
		case CREATE_EMPLOYEES:
			shop::fill(employees, numberOfEmployees);
			break;
		case SHOW_EMPLOYEES:
			shop::show(employees, numberOfEmployees);
			break;
		case DELETE_EMPLOYEES:
			shop::deleteAll(employees, numberOfEmployees);
			break;
		case EDIT_EMPLOYEE:
			shop::edit(employees, numberOfEmployees);
			break;
		case SAVE_EMPLOYEES:
			saveToCsv(employees, numberOfEmployees, "shop_employees.csv");
			break;
		default:
			Logger::error(std::string("Invalid input: Such an option doesn't exist") + "\n");
			break;
		}
		
	} while (true);

	return 0;
}
