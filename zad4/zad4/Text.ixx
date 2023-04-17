export module Text;

export class Text {
	/*
	*
	* More info here: https://en.wikipedia.org/wiki/ANSI_escape_code
	*
	*/

public:
	// Special
	static inline const char RESET[] = "\033[0m";
	static inline const char BOLD[] = "\033[1m";
	static inline const char FAINT[] = "\033[2m";
	static inline const char ITALIC[] = "\033[3m";
	static inline const char UNDERLINE[] = "\033[4m";
	static inline const char SLOW_BLINK[] = "\033[5m";
	static inline const char RAPID_BLINK[] = "\033[6m";

	// Foreground
	static inline const char FG_BLACK[] = "\033[30m";
	static inline const char FG_RED[] = "\033[31m";
	static inline const char FG_GREEN[] = "\033[32m";
	static inline const char FG_YELLOW[] = "\033[33m";
	static inline const char FG_BLUE[] = "\033[34m";
	static inline const char FG_MAGENTA[] = "\033[35m";
	static inline const char FG_CYAN[] = "\033[36m";
	static inline const char FG_WHITE[] = "\033[37m";
	static inline const char FG_GRAY[] = "\033[90m";
	static inline const char FG_LIGHT_RED[] = "\033[91m";
	static inline const char FG_LIGHT_GREEN[] = "\033[92m";
	static inline const char FG_LIGHT_YELLOW[] = "\033[93m";
	static inline const char FG_LIGHT_BLUE[] = "\033[94m";
	static inline const char FG_LIGHT_MAGENTA[] = "\033[95m";
	static inline const char FG_LIGHT_CYAN[] = "\033[96m";
	static inline const char FG_BRIGHT_WHITE[] = "\033[97m";

	// Background
	static inline const char BG_BLACK[] = "\033[40m";
	static inline const char BG_RED[] = "\033[41m";
	static inline const char BG_GREEN[] = "\033[42m";
	static inline const char BG_YELLOW[] = "\033[43m";
	static inline const char BG_BLUE[] = "\033[44m";
	static inline const char BG_MAGENTA[] = "\033[45m";
	static inline const char BG_CYAN[] = "\033[46m";
	static inline const char BG_WHITE[] = "\033[47m";
	static inline const char BG_GRAY[] = "\033[100m";
	static inline const char BG_LIGHT_RED[] = "\033[101m";
	static inline const char BG_LIGHT_GREEN[] = "\033[102m";
	static inline const char BG_LIGHT_YELLOW[] = "\033[103m";
	static inline const char BG_LIGHT_BLUE[] = "\033[104m";
	static inline const char BG_LIGHT_MAGENTA[] = "\033[105m";
	static inline const char BG_LIGHT_CYAN[] = "\033[106m";
	static inline const char BG_BRIGHT_WHITE[] = "\033[107m";
};
