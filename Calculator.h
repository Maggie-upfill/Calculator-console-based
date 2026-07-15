#pragma once

#include <vector>
#include <string>

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

	//std::vector<double> numbers;
	double a;
	double b;
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
};
