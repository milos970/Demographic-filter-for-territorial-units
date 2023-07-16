#pragma once
#include "territorial_unit.h"
#include "filter_interval.h"
#include "criterion_age_group_fraction.h"
#include "../../structures/heap_monitor.h"

class FilterAgeGroupFraction : public FilterInterval<TerritorialUnit*, double>
{
public:
	FilterAgeGroupFraction(EconomicAgeGroup economicAgeGroup, double minValue, double maxValue)
		: FilterInterval(new CriterionAgeGroupFraction(economicAgeGroup), minValue, maxValue) {};
};
