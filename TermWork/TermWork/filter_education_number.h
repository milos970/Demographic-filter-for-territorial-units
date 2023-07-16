#pragma once
#include "territorial_unit.h"
#include "filter_interval.h"
#include "criterion_education_number.h"
#include "../../structures/heap_monitor.h"

class FilterEducationNumber : public FilterInterval<TerritorialUnit*, unsigned int>
{
public:
	FilterEducationNumber(Education education, unsigned int minValue, unsigned int maxValue)
		: FilterInterval(new CriterionEducationNumber(education), minValue, maxValue) {};
};
