export module Color;

import <iostream>;

export class Color
{
public:
	static inline const std::string reset = "\033[0m";

	// Foreground
	static inline const std::string fgBlack = "\033[30m";
	static inline const std::string fgRed = "\033[31m";
	static inline const std::string fgGreen = "\033[32m";
	static inline const std::string fgYellow = "\033[33m";
	static inline const std::string fgBlue = "\033[34m";
	static inline const std::string fgMagenta = "\033[35m";
	static inline const std::string fgCyan = "\033[36m";
	static inline const std::string fgWhite = "\033[37m";
	static inline const std::string fgGray = "\033[90m";
	static inline const std::string fgLightRed = "\033[91m";
	static inline const std::string fgLightGreen = "\033[92m";
	static inline const std::string fgLightYellow = "\033[93m";
	static inline const std::string fgLightBlue = "\033[94m";
	static inline const std::string fgLightMagenta = "\033[95m";
	static inline const std::string fgLightCyan = "\033[96m";
	static inline const std::string fgBrightWhite = "\033[97m";

	// Background
	static inline const std::string bgBlack = "\033[40m";
	static inline const std::string bgRed = "\033[41m";
	static inline const std::string bgGreen = "\033[42m";
	static inline const std::string bgYellow = "\033[43m";
	static inline const std::string bgBlue = "\033[44m";
	static inline const std::string bgMagenta = "\033[45m";
	static inline const std::string bgCyan = "\033[46m";
	static inline const std::string bgWhite = "\033[47m";
	static inline const std::string bgGray = "\033[100m";
	static inline const std::string bgLightRed = "\033[101m";
	static inline const std::string bgLightGreen = "\033[102m";
	static inline const std::string bgLightYellow = "\033[103m";
	static inline const std::string bgLightBlue = "\033[104m";
	static inline const std::string bgLightMagenta = "\033[105m";
	static inline const std::string bgLightCyan = "\033[106m";
	static inline const std::string bgBrightWhite = "\033[107m";
};
