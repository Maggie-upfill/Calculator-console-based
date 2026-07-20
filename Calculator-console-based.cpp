
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

#include "Calculator.h"
#include "Inpututility.h"
#include "Menu.h"
#include "Application.h"

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

/*class Calculator
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
	bool isDivisorValid()const;

	void squareRoot();

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
};*/

/**
 * @brief Clears the input stream after invalid user input.
 *
 * Resets the error state of std::cin and removes any remaining
 * characters from the input buffer until a newline is found.
 *
 * This prevents invalid input from causing future input operations
 * to fail.
 */

Application::Application()
{

}
static void clearInput()
{
	std::cin.clear();

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


/**
 * @brief Reads and validates two numeric values from the user.
 *
 * Continuously prompts the user until valid numeric values are entered.
 *
 * Validation includes:
 * - Checking that input contains numeric values.
 * - Clearing invalid input from the input buffer.
 * - Checking for values outside the supported floating-point range.
 *
 * The validated numbers are stored in the class attributes a and b.
 */

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
				continue;
			}

			return;
		}
	}


/**
 * @brief Displays the result of a calculation.
 *
 * Checks whether the calculation produced a valid finite value
 * before displaying the result.
 *
 * Prevents displaying:
 * - Infinity caused by overflow.
 * - Invalid floating-point results (NaN).
 *
 * @param result The calculated value to display.
 */
	void Calculator::printResult(double result)
	{
		if (!std::isfinite(result))
		{
			std::cout << "Calculation overflowed or produced an invalid result.\n";
			return;
		}

		std::cout << "Result: " << result << '\n';
	}
	/**
 * @brief Validates whether division can be performed.
 *
 * Division by zero is mathematically undefined, so this function
 * prevents the calculator from performing an invalid operation.
 *
 * @return true if the divisor is not zero.
 * @return false if the divisor is zero.
 */

	bool Calculator::isDivisorValid() const
	{
		if (b == 0)
		{
			std::cout << "Error: Cannot divide or calculate remainder by zero.\n";
			return false;
		}

		return true;
	}

	void Calculator::squareRoot()
	{
		if (a < 0)
		{
			std::cout << "Error: Cannot calculate square root of a negative number.\n";
			return;
		}

		double result = std::sqrt(a);

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('s', result);
		}
	}

/**
 * @brief Performs a mathematical operation based on the selected operator.
 *
 * Supported operations:
 *
 * +  Addition
 * -  Subtraction
 * *  Multiplication
 * /  Division
 * %  Modulo
 * ^  Power
 * q  Square
 * c  Cube
 * a  Absolute value
 * m  Maximum value
 * n  Minimum value
 * v  Average
 * h  Display history
 *
 * The function:
 * 1. Retrieves validated input values.
 * 2. Performs the requested calculation.
 * 3. Displays the result.
 * 4. Stores successful calculations in history.
 *
 * @param operation Character representing the requested operation.
 */

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
		if (!isDivisorValid())
			return;

		double result = a / b;

		printResult(result);

		if (std::isfinite(result))
		{
			recordHistory('/', result);
		}

		break;
	}

	case '%':
	{
		if (!isDivisorValid())
			return;

		double result = std::fmod(a, b);

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

	case 's':
	{
	
	squareRoot();
	break;

	}

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
		std::swap(a, b);

		std::cout << "Numbers swapped"
			          << a << " " << b 
			          << std::endl;

		recordHistory('w', 0);

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

/**
 * @brief Creates and stores a calculation history record.
 *
 * Formats the calculation into a readable string,
 * stores it in the history vector, and saves it permanently
 * to a file.
 *
 * Example:
 *
 * 5 + 2 = 7
 *
 * @param operation The mathematical operator used.
 * @param result The result produced by the calculation.
 */

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

/**
 * @brief Saves a calculation record to a text file.
 *
 * Appends new calculations to history.txt without
 * overwriting previous records.
 *
 * @param record The formatted calculation string to save.
 */
void Calculator::saveHistory(const std::string& record)
{
	
	std::ofstream file("history.txt", std::ios::app);

	if (file)
	{
		file << record << '\n';
	}
}

/**
 * @brief Loads previous calculations from history.txt.
 *
 * Reads stored calculations from the file and restores
 * them into the history vector when the application starts.
 */

void Calculator::loadHistory()
{
	std::ifstream file("history.txt");

	std::string line;

	while (std::getline(file, line))
	{
		history.push_back(line);
	}
}

/**
 * @brief Displays all stored calculations.
 *
 * Prints calculations stored in the history vector with
 * their corresponding index numbers.
 *
 * Example:
 *
 * 1. 5 + 2 = 7
 * 2. 10 / 5 = 2
 */
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

/**
 * @brief Removes all calculation history.
 *
 * Clears the history vector in memory and empties
 * the history.txt file.
 */
void Calculator::clearHistory()
{
	history.clear();

	std::ofstream file("history.txt");

	std::cout << "History cleared.\n";
}
static void menu()
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
	Calculator calc;   // Acts as coordinator
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


//Characteristics of maintainable code
//Single responsibility principle
//Modular design
//Consistent formatting
//Encapsulation
//Small functions
//Testing
//Good documentation
//Clear comment
//Good repository history
//Low coupling
//High cohesion
//Meaningful names


