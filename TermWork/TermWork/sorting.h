#pragma once
#include "functionality.h"
#include "../../structures/heap_monitor.h"

class Sorting : public Functionality
{
protected:
	unsigned int ascending_;
public:
	Sorting(Country* country)
		: Functionality(country) {};

	virtual ~Sorting() = default;


};