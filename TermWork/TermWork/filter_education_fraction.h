#pragma once
#include "territorial_unit.h"
#include "filter_interval.h"
#include "criterion_education_fraction.h"
#include "../../structures/heap_monitor.h"

class FilterEducationFraction : public FilterInterval<TerritorialUnit*, double>
{
public:
	FilterEducationFraction(Education education, double minValue, double maxValue)
		: FilterInterval(new CriterionEducationFraction(education), minValue, maxValue) {};

};