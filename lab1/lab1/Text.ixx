export module Text;

import <iostream>;

export namespace text {
	/*
	* 
	* More info here: https://en.wikipedia.org/wiki/ANSI_escape_code
	*
	*/

	// Special
	inline const std::string RESET = "\033[0m";
	inline const std::string BOLD = "\033[1m";
	inline const std::string FAINT = "\033[2m";
	inline const std::string ITALIC = "\033[3m";
	inline const std::string UNDERLINE = "\033[4m";
	inline const std::string SLOW_BLINK = "\033[5m";
	inline const std::string RAPID_BLINK = "\033[6m";

	// Foreground
	inline const std::string FG_BLACK = "\033[30m";
	inline const std::string FG_RED = "\033[31m";
	inline const std::string FG_GREEN = "\033[32m";
	inline const std::string FG_YELLOW = "\033[33m";
	inline const std::string FG_BLUE = "\033[34m";
	inline const std::string FG_MAGENTA= "\033[35m";
	inline const std::string FG_CYAN = "\033[36m";
	inline const std::string FG_WHITE = "\033[37m";
	inline const std::string FG_GRAY = "\033[90m";
	inline const std::string FG_LIGHT_RED = "\033[91m";
	inline const std::string FG_LIGHT_GREEN = "\033[92m";
	inline const std::string FG_LIGHT_YELLOW = "\033[93m";
	inline const std::string FG_LIGHT_BLUE = "\033[94m";
	inline const std::string FG_LIGHT_MAGENTA = "\033[95m";
	inline const std::string FG_LIGHT_CYAN = "\033[96m";
	inline const std::string FG_BRIGHT_WHITE = "\033[97m";

	// Background
	inline const std::string BG_BLACK = "\033[40m";
	inline const std::string BG_RED = "\033[41m";
	inline const std::string BG_GREEN = "\033[42m";
	inline const std::string BG_YELLOW = "\033[43m";
	inline const std::string BG_BLUE = "\033[44m";
	inline const std::string BG_MAGENTA = "\033[45m";
	inline const std::string BG_CYAN = "\033[46m";
	inline const std::string BG_WHITE = "\033[47m";
	inline const std::string BG_GRAY = "\033[100m";
	inline const std::string BG_LIGHT_RED = "\033[101m";
	inline const std::string BG_LIGHT_GREEN = "\033[102m";
	inline const std::string BG_LIGHT_YELLOW = "\033[103m";
	inline const std::string BG_LIGHT_BLUE = "\033[104m";
	inline const std::string BG_LIGHT_MAGENTA = "\033[105m";
	inline const std::string BG_LIGHT_CYAN = "\033[106m";
	inline const std::string BG_BRIGHT_WHITE = "\033[107m";
}
