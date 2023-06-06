export module Random;

import <iostream>;
import <random>;
import <string>;
import <sstream>;
import <cmath>;
import <type_traits>;

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
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_int_distribution<> distr(0, 25);

		std::string str;
		for (int i = 0; i < length; i++) {
			char c = 'a' + distr(eng);
			str.push_back(c);
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
