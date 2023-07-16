#pragma once
#include "filter_value.h"
#include "criterion_belonging.h"

class FilterBelonging : public FilterValue<TerritorialUnit*, bool>
{

public:
	FilterBelonging(TerritorialUnit* uT)
		: FilterValue(new CriterionBelonging(uT), uT) {}
};