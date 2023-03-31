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

export class Employee {
private:
	std::string name;
	int age;

public:
    Employee() {
        this->name = "";
        this->age = 0;
    }

    Employee(const std::string& name, int age) : name(name), age(age) {}

    std::string getName() const {
        return name;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    int getAge() const {
        return age;
    }

    void setAge(int newAge) {
        age = newAge;
    }
};
