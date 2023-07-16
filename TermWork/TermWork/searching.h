#pragma once
#include "functionality.h"
#include "../../structures/heap_monitor.h"
class Searching : public Functionality
{
public:
	Searching(Country* country) 
		: Functionality(country) {};

	void options() override;
	void algorithm() override;
	void printResult() override;
	
};