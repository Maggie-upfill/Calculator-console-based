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
}

//Get two valid integers from the user
void Calculator::getNumbers()
{
	while (true)
	{
		std::cout << "Enter two numbers: ";

		if (std::cin >> a >> b)
		{
			return; // valid input, exit function
		}

		std::cout << "Invalid input. Please enter numbers only.\n";

		clearInput();
	}

}

//Helper function to print the result
void Calculator::printResult(double result)
{
	std::cout << "Result: " << result << std::endl;
}

//Helper function to check if division or modulo is valid
bool Calculator::isDivisionValid()
{
	if (b == 0)
	{
		std::cout << "Error: Division by zero!\n";
		return false;
	}

	return true;
}

int main()
{



}

