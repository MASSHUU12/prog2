export module Menu;

import <iostream>;

export void menu() {
	std::puts("_______________________________________________");
	std::puts("|                      |                      |");
	std::puts("|         Shop         |      Employees       |");
	std::puts("|                      |                      |");
	std::puts("-----------------------------------------------\n");
	std::puts("1. Create items        | 5. Create employees");
	std::puts("2. Show items          | 6. Show employees");
	std::puts("3. Delete items        | 7. Delete employees");
	std::puts("4. Edit item           | 8. Edit employee");
	std::puts("q. Exit");
	std::puts("");
}