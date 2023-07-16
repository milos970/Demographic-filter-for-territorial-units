#pragma once
#include "economic_age_group.h"
#include "functionality.h"
#include "../../structures/heap_monitor.h"

class SelectionEconomicAgeGroup : public Functionality
{
public:
	SelectionEconomicAgeGroup(Country* country) 
		: Functionality(country) {};

	void options() override;
	void printResult() override;
};
