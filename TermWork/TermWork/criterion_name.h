#pragma once
#include "criterion_territorial_unit.h"
#include <string>
#include "territorial_unit.h"
#include "../../structures/heap_monitor.h"

class CriterionName : public CriterionTerritorialUnit<std::string>
{
public:
	std::string evaluate(TerritorialUnit* tU) override;
};
