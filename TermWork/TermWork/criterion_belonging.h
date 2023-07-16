#pragma once
#include "criterion_territorial_unit.h"
#include "territorial_unit.h"
#include "../../structures/heap_monitor.h"

class CriterionBelonging : public CriterionTerritorialUnit<bool>
{
private:
	TerritorialUnit* tU_;
public:
	CriterionBelonging(TerritorialUnit* tU) : tU_(tU) {};
	~CriterionBelonging();

	bool evaluate(TerritorialUnit* tU) override;
};


