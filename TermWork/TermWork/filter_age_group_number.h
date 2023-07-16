#pragma once
#include "territorial_unit.h"
#include "filter_interval.h"
#include "criterion_age_group_number.h"
#include "../../structures/heap_monitor.h"

class FilterAgeGroupNumber : public FilterInterval<TerritorialUnit*, unsigned int>
{
public:
	FilterAgeGroupNumber(EconomicAgeGroup economicAgeGroup, unsigned int minValue, unsigned int maxValue)
		: FilterInterval(new CriterionAgeGroupNumber(economicAgeGroup), minValue, maxValue) {};

};

