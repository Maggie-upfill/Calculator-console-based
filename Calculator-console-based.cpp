// Calculator-console-based.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

//class calculator
class Calculator
{
private:
	int a{};
	int b{};

	std::vector<std::string> history;

	void getNumbers();
	bool isDivisionValid();
	void printResult(double result);
	void recordHistory(char operation, double result);
	void saveHistory(const std::string& record);

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

void saveHistory(const std::string& history)
{
	std::ofstream outFile("history.txt", std::ios::app);
	if (outFile.is_open())
	{
		outFile << history << std::endl;
		outFile.close();
	}
	else
	{
		std::cout << "Error: Unable to open history file for writing.\n";
	}
}
void displayHistory()
{
	std::ifstream inFile("history.txt");
	if (inFile.is_open())
	{
		std::string line;
		std::cout << "Calculation History:\n";
		while (std::getline(inFile, line))
		{
			std::cout << line << std::endl;
		}
		inFile.close();
	}
	else
	{
		std::cout << "Error: Unable to open history file for reading.\n";
	}
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

	case '^':
		printResult(std::pow(a, b));
		break;

	case 's':
		if (a < 0)
		{
			std::cout << "Error: Cannot calculate square root of a negative number!\n";
			return;
		}
		printResult(std::sqrt(a));
		break;
	case 'q':	
		printResult(a * a);
		break;
	case 'c':
		printResult(a * a * a);
		break;
	case 'a':
		printResult(std::abs(a));
		break;
	case 'm':
		printResult(std::max(a, b));
		break;
	case 'n':
		printResult(std::min(a, b));
		break;
		case 'v':
		printResult((a + b) / 2.0);
		break;
		case 'w':
			std::swap(a, b);
		case 'h':
			displayHistory();
			break;
		case 'f':
			saveHistory("Saved calculation: " + std::to_string(a) + " " + std::to_string(b));
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
	std::cout << "6. Power\n";
	std::cout << "7. Square Root\n";
	std::cout << "8. Square \n";
	std::cout << "9. Cube\n";
	std::cout << "10.Absolute value\n";
	std::cout << "11.Maximum value\n";
	std::cout << "12. Minimum value\n";
	std::cout << "13. Average\n";
	std::cout << "14. Swap numbers\n";
	std::cout << "15. History\n";
	std::cout << "16. Save history\n";
	std::cout << "17. Exit\n";

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
			calc.calculate('^');
			break;
		case 7:
			calc.calculate('s');
			break;
		case 8:
			calc.calculate('q');
			break;
		case 9: 
			calc.calculate('c');
			break;
		case 10:
			calc.calculate('a');
			break;
		case 11:
			calc.calculate('m');
			break;
		case 12:
			calc.calculate('n');
			break;
		case 13:
			calc.calculate('v');
			break;
		case 14:
			calc.calculate('w');
			break;
		case 15:
			calc.calculate('h');
			break;
		case 16:
			calc.calculate('f');
			break;
		case 17:
			std::cout << "Exiting the program. Goodbye!\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
			break;
		}

	} while (choice != 17);
}





