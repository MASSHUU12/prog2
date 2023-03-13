export module Text;

import <iostream>;

export namespace text {
	/*
	* 
	* More info here: https://en.wikipedia.org/wiki/ANSI_escape_code
	*
	*/

	// Special
	inline const char RESET[] = "\033[0m";
	inline const char BOLD[] = "\033[1m";
	inline const char FAINT[] = "\033[2m";
	inline const char ITALIC[] = "\033[3m";
	inline const char UNDERLINE[] = "\033[4m";
	inline const char SLOW_BLINK[] = "\033[5m";
	inline const char RAPID_BLINK[] = "\033[6m";

	// Foreground
	inline const char FG_BLACK[] = "\033[30m";
	inline const char FG_RED[] = "\033[31m";
	inline const char FG_GREEN[] = "\033[32m";
	inline const char FG_YELLOW[] = "\033[33m";
	inline const char FG_BLUE[] = "\033[34m";
	inline const char FG_MAGENTA[] = "\033[35m";
	inline const char FG_CYAN[] = "\033[36m";
	inline const char FG_WHITE[] = "\033[37m";
	inline const char FG_GRAY[] = "\033[90m";
	inline const char FG_LIGHT_RED[] = "\033[91m";
	inline const char FG_LIGHT_GREEN[] = "\033[92m";
	inline const char FG_LIGHT_YELLOW[] = "\033[93m";
	inline const char FG_LIGHT_BLUE[] = "\033[94m";
	inline const char FG_LIGHT_MAGENTA[] = "\033[95m";
	inline const char FG_LIGHT_CYAN[] = "\033[96m";
	inline const char FG_BRIGHT_WHITE[] = "\033[97m";

	// Background
	inline const char BG_BLACK[] = "\033[40m";
	inline const char BG_RED[] = "\033[41m";
	inline const char BG_GREEN[] = "\033[42m";
	inline const char BG_YELLOW[] = "\033[43m";
	inline const char BG_BLUE[] = "\033[44m";
	inline const char BG_MAGENTA[] = "\033[45m";
	inline const char BG_CYAN[] = "\033[46m";
	inline const char BG_WHITE[] = "\033[47m";
	inline const char BG_GRAY[] = "\033[100m";
	inline const char BG_LIGHT_RED[] = "\033[101m";
	inline const char BG_LIGHT_GREEN[] = "\033[102m";
	inline const char BG_LIGHT_YELLOW[] = "\033[103m";
	inline const char BG_LIGHT_BLUE[] = "\033[104m";
	inline const char BG_LIGHT_MAGENTA[] = "\033[105m";
	inline const char BG_LIGHT_CYAN[] = "\033[106m";
	inline const char BG_BRIGHT_WHITE[] = "\033[107m";
}
