#pragma once


class HistoryManager {
private:

	double a;
	double b;

	// Stores calculations for the current session.
	std::vector<std::string> history;

	// Stores a calculation in memory and saves it to file.
	void recordHistory(char operation, double result);

	// Displays all recorded calculations.
	void displayHistory() const;

	// Removes all stored calculations.
	void clearHistory();


};
