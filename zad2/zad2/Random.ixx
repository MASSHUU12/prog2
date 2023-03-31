export module Random;

import <iostream>;
import <random>;
import <string>;
import <sstream>;
import <cmath>;

export class Random {
public:
	static int getRandomNumber(int min, int max) {
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_int_distribution<> distr(min, max);

		return distr(eng);
	}

	static double getRandomNumber(double min, double max) {
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_real_distribution<double> distr(min, max);

		return distr(eng);
	}

	static double getRandomNumber(double min, double max, int precision) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> dist(min, max);

		double rand_num = dist(gen);
		double factor = std::pow(10, precision);

		return std::round(rand_num * factor) / factor;
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
};
