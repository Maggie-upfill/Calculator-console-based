
/*
-------------------------------------------------------
Project : Calculator Console-Based Application
File    : Calculator-console-based.cpp
Author  : Margaret Hamisi
Purpose : Implements the Calculator class and its
		  arithmetic operations, input validation,
		  calculation history, and file handling.
Date    : 10 July 2026
----------------------------
*/


#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

/*
 * @class Calculator
 * @brief Performs arithmetic operations on two numbers.
 *
 * The Calculator class validates user input, performs
 * mathematical operations, records calculation history,
 * and saves/loads history from a file.
 */

class Calculator
{
private:
	// Use double to support both integer and decimal calculations.

	 // First operand entered by the user.
	double a{};

	// Second operand entered by the user.
	double b{};

	// Stores calculations for the current session.
	std::vector<std::string> history;   

	// Reads and validates user input.
	void getNumbers();

	// Checks whether division or modulo is valid.
	bool isDivisionValid();

	// Displays the calculation result.
	void printResult(double result);

	// Stores a calculation in memory and saves it to file.
	void recordHistory(char operation, double result);

	// Appends a calculation to history.txt.
	void saveHistory(const std::string& record);

public:
	// Performs the selected operation.
	void calculate(char operation);

	// Displays all recorded calculations.
	void displayHistory() const;

	// Removes all stored calculations.
	void clearHistory();


	void loadHistory();
};

void clearInput()
{
	std::cin.clear();

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}



void Calculator::getNumbers()
{
	while (true)      
	{
		std::cout << "Enter two numbers: ";

		if (!(std::cin >> a >> b))
		{
			std::cout << "Invalid input. Please enter numeric values only.\n";

			clearInput();
			continue;
		}

		if (!std::isfinite(a) || !std::isfinite(b))
		{
			std::cout << "Error: Number is outside the supported range.\n";

			clearInput();  
		}

		return;
	}
}

	void Calculator::printResult(double result)
	{
		if (!std::isfinite(result))
		{
			std::cout << "Calculation overflowed or produced an invalid result.\n";
			return;
		}

		std::cout << "Result: " << result << '\n';
	}


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
	{
		double result = a + b;

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('+', result);
		}

		break;
	}

	case '-':
	{
		double result = a - b;

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('-', result);
		}

		break;
	}

	case '*':
	{
		double result = a * b;

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('*', result);
		}

		break;
	}

	case '/':
	{
		if (!isDivisionValid())
			return;

		double result = static_cast<double>(a) / b;

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('/', result);
		}

		break;
	}

	case '%':
	{
		if (!isDivisionValid())
			return;

		double result = a % b;

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('%', result);
		}

		break;
	}

	case '^':
	{
		double result = std::pow(a, b);

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('^', result);
		}

		break;
	}

	/*case 's':
	{
		if (number < 0) {

			std::cout << "Error: Cannot calculate square root of a negative number!\n";
			return;

		}
		if (number < 0)
		{
			std::cout << "Negative number detected.\n";
			std::cout << "Use absolute value instead? (Y/N): ";

			char answer;
			std::cin >> answer;

			if (answer == 'Y' || answer == 'y')
			{
				number = std::abs(number);
			}
			else
			{
				return;
			}
		}

		std::cout << "Square root = " << std::sqrt(number);
		
		double result = std::sqrt(number);

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('s', result);
		}

		break;

	}*/
	case 'q':
	{
		double result = a * a;

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('q', result);
		}

		break;
	}
	case 'c':
	{
		double result = a * a * a;

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('c', result);
		}

		break;
	}
	case 'a':
	{
		double result = std::abs(a);

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('a', result);
		}


		break;
	}
	case 'm':
	{
		double result = std::max(a, b);

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('m', result);
		}

		break;
	}
	case 'n':
	{
		double result = std::min(a, b);

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('n', result);
		}

		break;
	}
	case 'v':
	{
		double result = (a + b) / 2.0;

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('v', result);
		}

		break;
	}
	case 'w':
	{
		int result = std::swap(a, b);

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('w', result);
		}

		break;
	}
		case 'h':

			displayHistory();

			break;

	default:
		std::cout << "Unknown operation.\n";
		break;
	}
}

void Calculator::recordHistory(char operation, double result)
{
	std::string record =
		std::to_string(a) + " " +
		std::string(1, operation) + " " +    
		std::to_string(b) +
		" = " +
		std::to_string(result);

	history.push_back(record);     

	saveHistory(record);
}


void Calculator::saveHistory(const std::string& record)
{
	std::ofstream file("history.txt", std::ios::app);

	if (file)
	{
		file << record << '\n';
	}
}

void Calculator::loadHistory()
{
	std::ifstream file("history.txt");

	std::string line;

	while (std::getline(file, line))
	{
		history.push_back(line);
	}
}


void Calculator::displayHistory() const
{
	if (history.empty())
	{
		std::cout << "History is empty.\n";
		return;
	}

	for (size_t i = 0; i < history.size(); i++)
	{
		std::cout << i + 1 << ". "
			<< history[i]
			<< '\n';
	}
}


void Calculator::clearHistory()
{
	history.clear();

	std::ofstream file("history.txt");

	std::cout << "History cleared.\n";
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
	std::cout << "16. Clear history\n";
	std::cout << "17. Exit\n";

	std::cout << "=========================\n";
}

int main()
{
	Calculator calc;
	calc.loadHistory();
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
			calc.clearHistory();
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





