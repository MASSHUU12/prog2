export module Structs;

import <iostream>;

export class Item
{
private:
	std::string name;
	double price;

public:
    Item() {
        this->name = "";
        this->price = 0.0;
    }

    Item(const std::string& name, double price) : name(name), price(price) {}

    std::string getName() const {
        return name;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double newPrice) {
        price = newPrice;
    }
};

export struct Employee {
	std::string name;
	int age;
};
