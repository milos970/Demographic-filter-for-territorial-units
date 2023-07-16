#pragma once
#include <string>
#include "territorial_unit.h"
#include "filter_value.h"
#include "criterion_name.h"

class FilterName : public FilterValue<TerritorialUnit*, std::string>
{
public:
	FilterName(std::string name)
		: FilterValue(new CriterionName(), name) {}
};