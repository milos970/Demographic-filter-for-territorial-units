#pragma once
#include <string>
#include "territorial_unit.h"
#include "criterion_type.h"
#include "filter_value.h"

class FilterType : public FilterValue<TerritorialUnit*, TerritorialUnitType>
{

public:
	FilterType(TerritorialUnitType uT)
		: FilterValue(new CriterionType(), uT) {}
};