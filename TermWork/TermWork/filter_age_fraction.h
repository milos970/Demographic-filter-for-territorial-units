#pragma once
#include "territorial_unit.h"
#include "filter_interval.h"
#include "criterion_age_fraction.h"
#include "../../structures/heap_monitor.h"
class FilterAgeFraction : public FilterInterval<TerritorialUnit*, double>
{
public:
	FilterAgeFraction(unsigned int age, Gender gender, double minValue, double maxValue)
		: FilterInterval(new CriterionAgeFraction(age, gender), minValue, maxValue) {};


};



