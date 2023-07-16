#pragma once
#include "territorial_unit.h"
#include "filter_interval.h"
#include "criterion_age_number.h"
#include "../../structures/heap_monitor.h"

class FilterAgeNumber : public FilterInterval<TerritorialUnit*, unsigned int>
{
public:
	FilterAgeNumber(unsigned int age, Gender gender, unsigned int minValue, unsigned int maxValue)
		: FilterInterval(new CriterionAgeNumber(age, gender), minValue, maxValue) {};

};
