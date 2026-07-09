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

void Calculator::calculate(char operation)
{
	getNumbers();

	switch (operation)
	{
	case '+':
		printResult(a + b);
		break;

	case '-':
		printResult(a - b);
		break;

	case '*':
		printResult(a * b);
		break;

	case '/':
		if (!isDivisionValid())
			return;

		printResult(static_cast<double>(a) / b);
		break;

	case '%':
		if (!isDivisionValid())
			return;

		printResult(a % b);
		break;
	default:
		std::cout << "Unknown operation.\n";
		break;
	}
}

void menu()
{
	std::cout << "\n=========================\n";
	std::cout << "      CALCULATOR\n";
	std::cout << "=========================\n";
	std::cout << "1. Add\n";
	std::cout << "2. Subtract\n";
	std::cout << "3. Multiply\n";
	std::cout << "4. Divide\n";
	std::cout << "5. Modulo\n";
	std::cout << "6. Exit\n";
	std::cout << "=========================\n";
}

int main()
{
	Calculator calc;
	int choice{};

	do {
		menu();
		std::cout << "Enter your choice: ";
		if (!(std::cin >> choice))
		{
			clearInput();

			std::cout << "Invalid input.\n";
			continue;
		}

		switch (choice) {
		case 1:
			calc.calculate('+');
			break;

		case 2:
			calc.calculate('-');
			break;

		case 3:
			calc.calculate('*');
			break;

		case 4:
			calc.calculate('/');
			break;

		case 5:
			calc.calculate('%');
			break;
		case 6:
			std::cout << "Exiting the program. Goodbye!\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
			break;
		}

	} while (choice != 6);
}





