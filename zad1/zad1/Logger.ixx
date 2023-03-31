export module Logger;

import <iostream>;

import Text;

export namespace logger {
	void error(const std::string& str) {
		std::cout << text::BG_RED << str << text::RESET << "\n";
	}

	void warning(const std::string& str) {
		std::cout << text::BG_YELLOW << text::FG_BLACK << str << text::RESET << "\n";
	}

	void ok(const std::string& str) {
		std::cout << text::FG_GREEN << str << text::RESET << "\n";
	}
}