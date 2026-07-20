#pragma once
#include "Menu.h"
#include "Calculator.h"

class Application
{
public:
    Application();
    void run();

private:
    // We'll add member objects in the next step.
	Menu menu;
	Calculator calc;
};
