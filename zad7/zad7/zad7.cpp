import <iostream>;
import <vector>;
import <memory>;
import <optional>;

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
	std::optional<int> validatedInput;

	std::vector<std::unique_ptr<Item>> items;
	std::vector<std::unique_ptr<Employee>> employees;

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

		validatedInput = stringToInt(input);
		if (!validatedInput.has_value())
		{
			clearScreen();

			Logger::error(std::string("Invalid input: can't convert \"") + input + "\" to integer.\n");
			continue;
		}

		clearScreen();

		switch (validatedInput.value())
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
