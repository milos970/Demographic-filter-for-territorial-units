#pragma once
#include "criterion_territorial_unit.h"
#include "criterion_age_number.h"
#include "../../structures/heap_monitor.h"

class CriterionAgeFraction : public CriterionTerritorialUnit<double>
{
private:
	CriterionAgeNumber* criterionAgeNumber_;
	
public:
	CriterionAgeFraction(unsigned int age, Gender gender)
		: criterionAgeNumber_(new CriterionAgeNumber(age, gender)) {};


	~CriterionAgeFraction();

	double evaluate(TerritorialUnit* tU) override;


};