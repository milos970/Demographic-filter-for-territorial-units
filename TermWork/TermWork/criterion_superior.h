#pragma once
#include "territorial_unit.h"
#include "criterion_territorial_unit.h"
#include "../../structures/heap_monitor.h"

class CriterionSuperior : public CriterionTerritorialUnit<const TerritorialUnit*>
{
public:
	const TerritorialUnit* evaluate(TerritorialUnit* tU) override;
};

