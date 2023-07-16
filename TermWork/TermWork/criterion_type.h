#pragma once
#include "territorial_unit.h"
#include "criterion_territorial_unit.h"
#include "../../structures/heap_monitor.h"

class CriterionType : public CriterionTerritorialUnit<TerritorialUnitType>
{
public:
	TerritorialUnitType evaluate(TerritorialUnit* objectType) override;
};