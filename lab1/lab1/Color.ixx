export module Color;

import <iostream>;

export namespace color {
	inline const std::string reset = "\033[0m";

	// Foreground
	inline const std::string fgBlack = "\033[30m";
	inline const std::string fgRed = "\033[31m";
	inline const std::string fgGreen = "\033[32m";
	inline const std::string fgYellow = "\033[33m";
	inline const std::string fgBlue = "\033[34m";
	inline const std::string fgMagenta = "\033[35m";
	inline const std::string fgCyan = "\033[36m";
	inline const std::string fgWhite = "\033[37m";
	inline const std::string fgGray = "\033[90m";
	inline const std::string fgLightRed = "\033[91m";
	inline const std::string fgLightGreen = "\033[92m";
	inline const std::string fgLightYellow = "\033[93m";
	inline const std::string fgLightBlue = "\033[94m";
	inline const std::string fgLightMagenta = "\033[95m";
	inline const std::string fgLightCyan = "\033[96m";
	inline const std::string fgBrightWhite = "\033[97m";

	// Background
	inline const std::string bgBlack = "\033[40m";
	inline const std::string bgRed = "\033[41m";
	inline const std::string bgGreen = "\033[42m";
	inline const std::string bgYellow = "\033[43m";
	inline const std::string bgBlue = "\033[44m";
	inline const std::string bgMagenta = "\033[45m";
	inline const std::string bgCyan = "\033[46m";
	inline const std::string bgWhite = "\033[47m";
	inline const std::string bgGray = "\033[100m";
	inline const std::string bgLightRed = "\033[101m";
	inline const std::string bgLightGreen = "\033[102m";
	inline const std::string bgLightYellow = "\033[103m";
	inline const std::string bgLightBlue = "\033[104m";
	inline const std::string bgLightMagenta = "\033[105m";
	inline const std::string bgLightCyan = "\033[106m";
	inline const std::string bgBrightWhite = "\033[107m";
}
