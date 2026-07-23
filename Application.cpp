#include "Application.h"
#include <iostream>

Application::Application()
{

}
void Application::run()
{
	calculator.loadHistory();
	int choice{};

	do {
		menu.displayMenu();
		std::cout << "Enter your choice: ";
		if (!(std::cin >> choice))
		{
		input.clearInput();

			std::cout << "Invalid input.\n";
			continue;
		}

		switch (choice) {
		case 1:
			calculator.calculate('+');
			break;

		case 2:
			calculator.calculate('-');
			break;

		case 3:
			calculator.calculate('*');
			break;

		case 4:
			calculator.calculate('/');
			break;

		case 5:
			calculator.calculate('%');
			break;
		case 6:
			calculator.calculate('^');
			break;
		case 7:
			calculator.calculate('s');
			break;
		case 8:
			calculator.calculate('q');
			break;
		case 9:
			calculator.calculate('c');
			break;
		case 10:
			calculator.calculate('a');
			break;
		case 11:
			calculator.calculate('m');
			break;
		case 12:
			calculator.calculate('n');
			break;
		case 13:
			calculator.calculate('v');
			break;
		case 14:
			calculator.calculate('w');
			break;
		case 15:
			calculator.calculate('h');
			break;
		case 16:
			calculator.clearHistory();
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
