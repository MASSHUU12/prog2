import <iostream>;
import StringToInt;

int main(void)
{
	std::string input;
	short validatedInput;

	do
	{
		std::cin >> input;

		try
		{
			validatedInput = stringToInt(input);
			std::cout << validatedInput;
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << "Invalid input: " << e.what() << "\n";
			continue;
		}
		
	} while (true);

	return 0;
}
