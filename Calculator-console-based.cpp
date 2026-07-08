// Calculator-console-based.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>

//class calculator
class Calculator
{
private:
	int a{};
	int b{};

	void getNumbers();
	bool isDivisionValid();
	void printResult(double result);

public:
	void calculate(char operation);
};

void clearInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{



}

