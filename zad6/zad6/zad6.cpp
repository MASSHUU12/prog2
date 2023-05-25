import <iostream>;
import <vector>;

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

	std::vector<Item> items;
	std::vector<Employee> employees;

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
			ItemManager::fill(items);
			break;
		case SHOW_SHOP_ITEMS:
			ItemManager::show(items);
			break;
		case DELETE_SHOP_ITEMS:
			ItemManager::deleteAll(items);
			break;
		case EDIT_SHOP_ITEM:
			ItemManager::edit(items);
			break;
		case SAVE_SHOP_ITEMS: {
			std::string fileName = "shop_items.csv";
			SaveData<Item> data = {
				items,
				fileName
			};
			std::cout << data;
			break;
		}
		case IMPORT_SHOP_ITEMS: {
			std::string fileName = "shop_items.csv";
			ReadData<Item> data = {
				items,
				fileName
			};
			std::cin >> data;
			break;
		}
		case CREATE_EMPLOYEES:
			EmployeeManager::fill(employees);
			break;
		case SHOW_EMPLOYEES:
			EmployeeManager::show(employees);
			break;
		case DELETE_EMPLOYEES:
			EmployeeManager::deleteAll(employees);
			break;
		case EDIT_EMPLOYEE:
			EmployeeManager::edit(employees);
			break;
		case SAVE_EMPLOYEES: {
			std::string fileName = "shop_employees.csv";
			SaveData<Employee> data = {
				employees,
				fileName
			};
			std::cout << data;
			break;
		}
		case IMPORT_EMPLOYEES: {
			std::string fileName = "shop_employees.csv";
			ReadData<Employee> data = {
				employees,
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
