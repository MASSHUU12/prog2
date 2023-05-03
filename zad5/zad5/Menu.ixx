export module Menu;

import <iostream>;

export void menu() {
	std::puts("_______________________________________________");
	std::puts("|                      |                      |");
	std::puts("|         Shop         |      Employees       |");
	std::puts("|                      |                      |");
	std::puts("-----------------------------------------------\n");
	std::puts("1. Create items        | 7. Create employees");
	std::puts("2. Show items          | 8. Show employees");
	std::puts("3. Delete items        | 9. Delete employees");
	std::puts("4. Edit item           | 10. Edit employee");
	std::puts("5. Save items          | 11. Save employees");
	std::puts("6. Import items        | 12. Import employees");
	std::puts("q. Exit");
	std::puts("");
}