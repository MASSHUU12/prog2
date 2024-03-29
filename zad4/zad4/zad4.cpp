import <iostream>;

import Helpers;
import Menu;
import Text;
import Enums;
import Shop;
import Structs;
import Logger;
import CSV;

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
			ItemManager::fill(items, numberOfItems);
			break;
		case SHOW_SHOP_ITEMS:
			ItemManager::show(items, numberOfItems);
			break;
		case DELETE_SHOP_ITEMS:
			ItemManager::deleteAll(items, numberOfItems);
			break;
		case EDIT_SHOP_ITEM:
			ItemManager::edit(items, numberOfItems);
			break;
		case SAVE_SHOP_ITEMS: {
			std::string fileName = "shop_items.csv";
			SaveData data = {
				items,
				numberOfItems,
				fileName
			};
			std::cout << data;
			break;
		}
		case IMPORT_SHOP_ITEMS: {
			std::string fileName = "shop_items.csv";
			ReadData data = {
				items,
				numberOfItems,
				fileName
			};
			std::cin >> data;
			break;
		}
		case CREATE_EMPLOYEES:
			EmployeeManager::fill(employees, numberOfEmployees);
			break;
		case SHOW_EMPLOYEES:
			EmployeeManager::show(employees, numberOfEmployees);
			break;
		case DELETE_EMPLOYEES:
			EmployeeManager::deleteAll(employees, numberOfEmployees);
			break;
		case EDIT_EMPLOYEE:
			EmployeeManager::edit(employees, numberOfEmployees);
			break;
		case SAVE_EMPLOYEES: {
			std::string fileName = "shop_employees.csv";
			SaveData data = {
				employees,
				numberOfEmployees,
				fileName
			};
			std::cout << data;
			break;
		}
		case IMPORT_EMPLOYEES: {
			std::string fileName = "shop_employees.csv";
			ReadData data = {
				employees,
				numberOfEmployees,
				fileName
			};
			std::cin >> data;
			break;
		}
		default:
			Logger::error(std::string("Invalid input: Such an option doesn't exist") + "\n");
			break;
		}
		
	} while (true);

	return 0;
}
