#include <iostream>

using std::string;

class Cat
{
	string name = "janghwa";
	int age = 15;

public:
	Cat(){}

	string getName() { return this->name; }
	void setName(string name) { this->name  = name;}

	int getAge() { return this->age; }
	void setAge(int age) { this->age = age; }

};

void main()
{
	Cat cat;

	std::cout << "����� �̸� : " << cat.name << std::endl;
	std::cout << "����� �̸� : " << cat.getName() << std::endl;

}