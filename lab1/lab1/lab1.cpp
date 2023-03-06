import <iostream>;

import Helpers;
import Menu;
import Color;

int main(void)
{
	std::string input;
	short validatedInput;

	do
	{
		menu();

		std::cout << "> ";
		std::cin >> input;

		stringToLower(input);

		// Check if user wants to exit program
		if (input == "q")
			break;

		try
		{
			validatedInput = stringToInt(input);
		}
		catch (const std::invalid_argument& e)
		{
			clearScreen();
			std::cout << "Invalid input: " << e.what() << "\n\n";
			continue;
		}

		//clearScreen();

		std::cout << "\n\n" << Color::bgMagenta << "AAA" << Color::reset << "\n\n";
		
	} while (true);

	return 0;
}
