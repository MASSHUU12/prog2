export module Logger;

import <iostream>;

import Text;

export class Logger {
public:
	static void error(const std::string& str) {
		std::cout << Text::BG_RED << str << Text::RESET << "\n";
	}

	static void warning(const std::string& str) {
		std::cout << Text::BG_YELLOW << Text::FG_BLACK << str << Text::RESET << "\n";
	}

	static void ok(const std::string& str) {
		std::cout << Text::FG_GREEN << str << Text::RESET << "\n";
	}
};
