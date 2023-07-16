#pragma once
#include "criterion_territorial_unit.h"
#include "economic_age_group.h"
#include <iostream>
#include "../../structures/heap_monitor.h"

class CriterionAgeGroupNumber : public CriterionTerritorialUnit< unsigned int>
{
private:
	EconomicAgeGroup economicAgeGroup_;
	

public:
	CriterionAgeGroupNumber(EconomicAgeGroup economicAgeGroup) : economicAgeGroup_(economicAgeGroup) {};

	unsigned int evaluate(TerritorialUnit* tU) override;
	

};