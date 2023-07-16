#pragma once
#include "criterion_territorial_unit.h"
#include "criterion_age_group_number.h"
#include "economic_age_group.h"
#include "../../structures/heap_monitor.h"

class CriterionAgeGroupFraction : public CriterionTerritorialUnit<double>
{
private:
	CriterionAgeGroupNumber* criterionAgeGroupNumber_;
	

public:
	CriterionAgeGroupFraction(EconomicAgeGroup economicAgeGroup)
		: criterionAgeGroupNumber_(new CriterionAgeGroupNumber(economicAgeGroup)) {};

	~CriterionAgeGroupFraction();

	double evaluate(TerritorialUnit* tU) override;

	
};

