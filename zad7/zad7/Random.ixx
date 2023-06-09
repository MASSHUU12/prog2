export module Random;

import <random>;
import <sstream>;

export class Random {
public:
	static int getRandomNumber(int min, int max) {
		return getRandomValue(min, max);
	}

	static double getRandomNumber(double min, double max) {
		return getRandomValue<double>(min, max);
	}

	static double getRandomNumber(double min, double max, int precision) {
		return getRandomValue<double>(min, max, precision);
	}

	static std::string getRandomString(int length) {
		std::random_device rd; // Create a random_device object for seeding the random number generator.
		std::mt19937 eng(rd()); // Create a Mersenne Twister engine and seed it with the random_device.
		// Create a uniform distribution object for generating random integers between 0 and 25 (inclusive).
		std::uniform_int_distribution<> distr(0, 25);

		std::string str;
		for (int i = 0; i < length; i++) {
			char c = 'a' + distr(eng); // Generate a random integer and add it to the ASCII value of 'a' to get a random lowercase letter.
			str.push_back(c); // Add the generated character to the string.
		}
		return str;
	}

private:
	template<typename T>
	static T getRandomValue(T min, T max) {
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_real_distribution<T> distr(min, max);

		return distr(eng);
	}

	static int getRandomValue(int min, int max) {
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_real_distribution<> distr(min, max);

		return distr(eng);
	}

	template <typename T>
	static T getRandomValue(T min, T max, int precision) {
		static_assert(!std::is_same<T, int>::value, "T must be of type int.");

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<T> dist(min, max);

		T rand_num = dist(gen);
		T factor = std::pow(10, precision);

		return std::round(rand_num * factor) / factor;
	}
};
