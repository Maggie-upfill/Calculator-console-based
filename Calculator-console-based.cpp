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


int main()
{



}

