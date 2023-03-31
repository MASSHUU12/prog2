export module Menu;

import <iostream>;

export void menu() {
	std::puts("_______________________________________________");
	std::puts("|                      |                      |");
	std::puts("|         Shop         |      Employees       |");
	std::puts("|                      |                      |");
	std::puts("-----------------------------------------------\n");
	std::puts("1. Create items        | 6. Create employees");
	std::puts("2. Show items          | 7. Show employees");
	std::puts("3. Delete items        | 8. Delete employees");
	std::puts("4. Edit item           | 9. Edit employee");
	std::puts("5. Save items          | 10. Save employees");
	std::puts("q. Exit");
	std::puts("");
}