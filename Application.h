#pragma once
#include "Menu.h"
#include "Inpututility.h"
#include "Calculator.h"

class Application
{
public:
    Application();
    void run();

private:
	Menu menu;
	Inpututility input;
	Calculator calculator;
};
