export module Menu;

import <iostream>;

export void menu() {
	std::puts("########################");
	std::puts("#                      #");
	std::puts("#         Shop         #");
	std::puts("#                      #");
	std::puts("########################\n");
	std::puts("1. Create shop items");
	std::puts("2. Show shop items");
	std::puts("q. Exit");
	std::puts("");
}